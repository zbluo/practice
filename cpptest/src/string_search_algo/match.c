/***********************************************************
  ac(bnfa) and bm text search algorithm.
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>

#include "match.h"

#ifndef likely
#define likely(x)       __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x)     __builtin_expect(!!(x), 0)
#endif

/* BM Implement */
#define max_t(type, x, y) ({            \
            type __max1 = (x);          \
            type __max2 = (y);          \
            __max1 > __max2 ? __max1: __max2; })


#define BM_SHIFT        256

struct bm {
    unsigned char *pattern;
    int patlen;
    unsigned int bad_shift[BM_SHIFT];
    unsigned int good_shift[0];
};


static int bm_subpattern(unsigned char *pattern, int i, int j, int k)
{
    int x = i+k-1, y = j+k-1, ret = 0;

    while (pattern[x--] == pattern[y--]) {
        if (y < 0) {
            ret = 1;
            break;
        }
        if (--k == 0) {
            ret = pattern[i-1] != pattern[j-1];
            break;
        }
    }

    return ret;
}

static void bm_compute_prefix_table(struct bm *bm)
{
    int i, j, k;

    for (i = 0; i < BM_SHIFT; i++) {
        bm->bad_shift[i] = bm->patlen;
    }
    for (i = 0; i < bm->patlen - 1; i++) {
        bm->bad_shift[bm->pattern[i]] = bm->patlen - 1 - i;
    }

    /* Compute the good shift array, used to match reocurrences 
     * of a subpattern */
    bm->good_shift[0] = 1;
    for (i = 1; i < bm->patlen; i++) {
        bm->good_shift[i] = bm->patlen;
    }
    for (i = bm->patlen-1, k = 1; i > 0; k++, i--) {
        for (j = i-1; j >= 1-k ; j--) {
            if (bm_subpattern(bm->pattern, i, j, k)) {
                bm->good_shift[k] = bm->patlen-j-k;
                break;
            }
        }
    }
}


struct bm *bm_init(const unsigned char *pattern, int patlen)
{
    struct bm *bm;
    unsigned int len;

    len = patlen * sizeof(unsigned int);
    bm = malloc(sizeof(*bm) + patlen + len);
    if (bm == NULL) {
        return NULL;
    }
    bm->patlen = patlen;
    bm->pattern = ((unsigned char *)(bm->good_shift)) + len;
    memcpy(bm->pattern, pattern, patlen);
    bm_compute_prefix_table(bm);

    return bm;
}

void bm_destroy(struct bm *bm)
{
    if (bm) {
        free(bm);
    }
    return;
}

int bm_find(struct bm *bm, const unsigned char *text, int text_len)
{
    int i, shift, bs;

    shift = bm->patlen - 1;
    while (shift < text_len) {
#ifdef TEST
        printf("Searching in position %d (%c)\n", shift, text[shift]);
#endif
        for (i = 0; i < bm->patlen; i++) {
            if ((text[shift-i]) != bm->pattern[bm->patlen-1-i]) {
                 goto next;
            }
        }
#ifdef TEST
        printf("found!\n");
#endif
        return (shift-(bm->patlen-1));

next:
        bs = bm->bad_shift[text[shift-i]];
        /* Now jumping to... */
        shift = max_t(int, shift-i+bs, shift+bm->good_shift[i]);
    }

    return -1;
}


/* KMP Implement */
struct kmp {
    unsigned char *pattern;
    int patlen;
    unsigned int shift[0];
};

static inline void kmp_compute_prefix_table(const unsigned char *pattern,
        int patlen, unsigned int *prefix_table)
{
    unsigned int k, q;

    for (k = 0, q = 1; q < patlen; q++) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix_table[k-1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        prefix_table[q] = k;
    }
}

struct kmp *kmp_init(const unsigned char *pattern, int patlen)
{
    struct kmp *kmp;
    unsigned int len;

    len = patlen * sizeof(unsigned int);
    kmp = malloc(sizeof(*kmp) + patlen + len);
    if (kmp == NULL) {
        return NULL;
    }
    kmp->patlen = patlen;
    kmp->pattern = ((unsigned char *)(kmp->shift)) + len;
    memcpy(kmp->pattern, pattern, patlen);
    kmp_compute_prefix_table(pattern, patlen, kmp->shift);

    return kmp;
}

void kmp_destroy(struct kmp *kmp)
{
    if (kmp) {
        free(kmp);
    }
    return;
}

/* return the position of text where matched, or -1 for not match. */
int kmp_find(struct kmp *kmp, const unsigned char *text, int text_len)
{
    unsigned int i, q;

    q = 0;

    for (i = 0; i < text_len; i++) {
        while (q > 0 && kmp->pattern[q] != text[i]) {
            q = kmp->shift[q - 1];
        }
        if (kmp->pattern[q] == text[i]) {
            q++;
        }
        if (unlikely(q == kmp->patlen)) {
            return (i + 1 - kmp->patlen);
        }
    }

    return -1;
}

/* NFA Implement */
#define NFA_LAST_STATE_INIT             0xffffffff
#define NFA_MAX_ALPHABET_SIZE           256
#define NFA_FAIL_STATE                  0xffffffff
#define NFA_SPARSE_LINEAR_SEARCH_LIMIT  6

#define NFA_SPARSE_MAX_STATE            0x00ffffff
#define NFA_SPARSE_COUNT_SHIFT          24
#define NFA_SPARSE_VALUE_SHIFT          24
#define NFA_SPARSE_CLEAN_STATE          0xff000000

#define NFA_SPARSE_MATCH_BIT            0x80000000
#define NFA_SPARSE_FULL_BIT             0x40000000
#define NFA_SPARSE_COUNT_BITS           0x3f000000
#define NFA_SPARSE_MAX_ROW_TRANSITIONS  0x3f

struct nfa_trans_node {
    struct nfa_trans_node *next;
    unsigned int key;
    unsigned int next_state;
};

struct nfa_match_node {
    struct nfa_match_node *next; 
    void *data;
    void *rule_option_tree;
    void *neg_list;
};

struct nfa {
    unsigned int count_pattern;
    struct nfa_pattern *pattern;
    int max_state;
    int count_state;
    int count_trans;
    int match_state;
    struct nfa_trans_node **trans_table;
    struct nfa_match_node **match_list;
    unsigned int *fail_state;
    unsigned int *trans_list;
};

/* simple queue node */
struct queue_node {
    unsigned state;
    struct queue_node *next;
};
/* simple fifo queue structure */
struct queue {
    struct queue_node *head;
    struct queue_node *tail;
    int count;
};

/* initialize the fifo queue */
static inline void queue_init(struct queue *q)
{
    q->head = NULL;
    q->tail = NULL;
    q->count= 0;
}

/* add items to tail of queue (fifo) */
static inline int queue_add(struct queue *q, int state)
{
    struct queue_node *node;
    node = malloc(sizeof(struct queue_node));
    if (node == NULL) {
        return -1;
    }
    node->state = state;
    node->next = NULL;

    if (q->head == NULL) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
    q->count++;

    return 0;
}

/* remove items from head of queue (fifo) */
static inline int queue_remove(struct queue *q)
{
    int state;
    struct queue_node *node;

    state = 0;
    if (q->head) {
        node = q->head;
        state = node->state;
        q->head = q->head->next;
        q->count--;
        if (q->head == NULL) {
            q->tail = NULL;
            q->count = 0;
        }
        free(node);
    }

    return state;
}

/* return count of items in the queue */
static inline int queue_count(struct queue *q)
{
    return q->count;
}

/* free the queue */
static inline void queue_free(struct queue *q)
{
    while (queue_count(q)) {
        queue_remove(q);
    }
    return;
}

/* get next state from transition list. */
static inline int nfa_get_next_state(struct nfa *nfa, int state, int input)
{
    unsigned int *p;
    struct nfa_trans_node *t;

    /* full set of states always */
    if (state == 0) {
       p = (unsigned int *)nfa->trans_table[0];
       if (p == NULL) {
           return 0;
       }
       return p[input];
    } else {
        t = nfa->trans_table[state];
        while (t) {
            if (t->key == (unsigned int)input) {
                return t->next_state;
            }
            t = t->next;
        }
        return NFA_FAIL_STATE;
    }
    /* fail state */
    return NFA_FAIL_STATE;
}

/* put next state, head insertion, and transition updates. */
static inline int nfa_put_next_state(struct nfa *nfa, int state, int input,
        int next_state)
{
    unsigned int *p;
    struct nfa_trans_node *t;
    struct nfa_trans_node *tnew;

    if (state >= nfa->max_state) {
        return -1;
    }

    if (input >= NFA_MAX_ALPHABET_SIZE) {
        return -1;
    }

    if (state == 0) {
        p = (unsigned int *)nfa->trans_table[0];
        if (p == NULL) {
            p = malloc(sizeof(unsigned int) * NFA_MAX_ALPHABET_SIZE);
            if (p == NULL) {
                return -1;
            }
            memset(p, 0, sizeof(unsigned int) * NFA_MAX_ALPHABET_SIZE);
            nfa->trans_table[0] = (struct nfa_trans_node *)p;
        }
        if (p[input]) {
            p[input] =  next_state;
            return 0;
        }
        p[input] = next_state;
    } else {
        /* check if the transition already exists, if so just update
            the next_state. */
        t = nfa->trans_table[state];
        while (t) {
            if (t->key == (unsigned)input) {
            /* transition already exists, reset the next state */
            t->next_state = next_state;
            return 0;
            }
            t = t->next;
        }
        /* definitely not an existing transition, add it */
        tnew = malloc(sizeof(struct nfa_trans_node));
        if (tnew == NULL) {
            return -1;
        }
        memset(tnew, 0, sizeof(struct nfa_trans_node));
        tnew->key = input;
        tnew->next_state = next_state;
        tnew->next = nfa->trans_table[state];

        nfa->trans_table[state] = tnew;
    }
    nfa->count_trans++;

    return 0;
}

/* add pattern characters to the initial trie */
static int nfa_add_pattern_states(struct nfa *nfa, struct nfa_pattern *pat)
{
    int state, next, patlen;
    unsigned char * pattern;
    struct nfa_match_node *node;

    patlen = pat->patlen;
    pattern = pat->pattern;
    state = 0;

    /* match up pattern with existing states */
    for (; patlen > 0; pattern++, patlen--) {
        next = nfa_get_next_state(nfa, state, *pattern);
        if (next == (int)NFA_FAIL_STATE || next == 0) {
            break;
        }
        state = next;
    }

    /* add new states for the rest of the pattern bytes, 1 state per byte. */
    for (; patlen > 0; pattern++, patlen--) {
        nfa->count_state++;
        if (nfa_put_next_state(nfa, state, *pattern, nfa->count_state)  < 0 ) {
            return -1;
        }
        state = nfa->count_state;
        if (nfa->count_state >= nfa->max_state) {
            return -1;
        }
    }

    /* add a pattern to the list of patterns terminated at this state */
    node = malloc(sizeof(struct nfa_match_node));
    if (node == NULL) {
        return -1;
    }
    memset(node, 0, sizeof(struct nfa_match_node));
    node->data = pat;
    node->next = nfa->match_list[state];
    nfa->match_list[state] = node;

    return 0;
}

/* used only by nfa_contains() */
static inline int nfa_conv_node_to_full(struct nfa_trans_node *t,
        unsigned int* full)
{
    int ret;

    ret = 0;
    memset(full, 0, sizeof(unsigned int) * NFA_MAX_ALPHABET_SIZE);

    if (t == NULL) {
        return 0;
    }
    while (t && (t->key < NFA_MAX_ALPHABET_SIZE)) {
        full[t->key] = t->next_state;
        ret++;
        t = t->next;
    }
    return ret;
}

static inline int nfa_contains(struct nfa_trans_node *tk,
    struct nfa_trans_node *tj)
{
    int ret;
    unsigned int full[NFA_MAX_ALPHABET_SIZE];

    ret = nfa_conv_node_to_full(tk, full);
    if (ret == 0) {
        /* emtpy state */
        return 1;
    }
    while (tj) {
        if (!full[tj->key]) {
            return 0;
        }
        tj = tj->next;
    }
    return 1;
}

/* optimization, eliminate duplicate fail states.
    check if a fail state is a subset of the current state,
    if so recurse to the next fail state, and so on. */
static int nfa_optimize(struct nfa *nfa)
{
    int k, fs, fr;
    unsigned int *state;

    state = nfa->fail_state;
    for (k = 2; k < nfa->count_state; k++) {
        fr = state[k];
        fs = state[k];
        while (fs && nfa_contains(nfa->trans_table[k],
            nfa->trans_table[fs])) {
            fs = state[fs];
        }
        if (fr != fs) {
            state[k] = fs;
        }
    }

    return 0;
}

/* build a non-deterministic finite automata using Aho-Corasick construction,
    the keyword trie must already be built via nfa_add_pattern_states(). */
static int nfa_build(struct nfa* nfa)
{
    int r, s, i;
    unsigned int *state;
    struct nfa_match_node **match_list;
    struct nfa_match_node *mlist, *p;
    struct queue q, *queue;

    state = nfa->fail_state;
    match_list = nfa->match_list;
    queue = &q;

    /* init a queue */
    queue_init(queue);

    /* add the state 0 transitions 1st, the states at depth 1,
        fail to state 0 */
    for (i = 0; i < NFA_MAX_ALPHABET_SIZE; i++) {
        /* note that state zero does not fail, it just returns 0..nstates-1 */
        s = nfa_get_next_state(nfa, 0, i);
        if (s) {
            /* don't bother adding state zero */
            if (queue_add(queue, s)) {
                return -1;
            }
            state[s] = 0;
        }
    }

    /* build the fail state successive layer of transitions */
    while (queue_count(queue) > 0) {
        r = queue_remove (queue);
        /* find final states for any failure */
        for (i = 0; i < NFA_MAX_ALPHABET_SIZE; i++) {
            int fs, next;
            s = nfa_get_next_state(nfa, r, i);
            if (s == (int)NFA_FAIL_STATE) {
                continue;
            }
            if (queue_add(queue, s)) {
                return -1;
            }
            fs = state[r];
            /* locate the next valid state for 'i' starting at fs. */
            while ((next=nfa_get_next_state(nfa, fs, i)) ==
                (int)NFA_FAIL_STATE) {
                fs = state[fs];
            }

            /* update 's' state failure state to point to the next
                valid state */
            state[s] = next;

            /* copy 'next' states match list into 's' states match list,
                we just create a new list nodes, the patterns are 
                not copied. */
            for (mlist = match_list[next]; mlist != NULL;
                mlist = mlist->next) {
                /* Dup the node, don't copy the data */
                p = malloc(sizeof(struct nfa_match_node));
                if (p == NULL) {
                    return -1;
                }
                memset(p, 0, sizeof(struct nfa_match_node));
                p->data = mlist->data;
                /* insert at head */
                p->next = match_list[s];
                match_list[s] = p;
            }
        }
    }

    /* clean up the queue */
    queue_free(queue);

    /* optimize the failure states */
    nfa_optimize(nfa);

    return 0;
}

/* converts a single row of states from list format to a full format. */
static int nfa_list_conv_row_to_full(struct nfa *nfa, unsigned int state,
        unsigned int *full)
{
    if ((int)state >= nfa->max_state) {
        /* protects 'full' against overflow */
        return -1;
    }

    if (state == 0) {
        if (nfa->trans_table[0]) {
            memcpy(full, nfa->trans_table[0],
                sizeof(unsigned int) * NFA_MAX_ALPHABET_SIZE);
        } else {
            memset(full, 0, sizeof(unsigned int) * NFA_MAX_ALPHABET_SIZE);
        }
        return NFA_MAX_ALPHABET_SIZE;
    } else {
        int count = 0;
        struct nfa_trans_node *t = nfa->trans_table[state];
        memset(full, 0, sizeof(unsigned int) * NFA_MAX_ALPHABET_SIZE);
        if (t == NULL) {
            return 0;
        }
        while (t && (t->key < NFA_MAX_ALPHABET_SIZE)) {
            full[ t->key ] = t->next_state;
            count++;
            t = t->next;
        }
        return count;
    }

    return -1;
}

/* free the entire transition list table */
static int nfa_free_trans_table(struct nfa *nfa)
{
    int i;
    struct nfa_trans_node *t, *p;

    if (nfa->trans_table) {
        if (nfa->trans_table[0]) {
            free(nfa->trans_table[0]);
        }

        for (i = 1; i < nfa->max_state; i++) {
            t = nfa->trans_table[i];
            while (t) {
                p = t;
                t = t->next;
                free(p);
            }
        }

        free(nfa->trans_table);
        nfa->trans_table = NULL;
    }

    return 0;
}

/* convert state machine to csparse format.
    merges state/transition/failure arrays into one.
    for each state we use a state-word followed by the transition list for
    the state sw(state 0 )...tl(state 0) sw(state 1)...
    tl(state1) sw(state2)...tl(state2) ....
    the transition and failure states are replaced with the start index of
    transition state, this eliminates the next state[] lookup....
    the compaction of multiple arays into a single array reduces the total
    number of states that can be handled since the max index is 2^24-1,
    whereas without compaction we had 2^24-1 states. */
static int nfa_conv_list_to_csparse_array(struct nfa *nfa)
{
    int m, k, i, nc;
    unsigned int state;
    unsigned int *fail_state;
    /* transition list */
    unsigned int *ps;
    /* state indexes into ps */
    unsigned int *pi;
    unsigned int ps_index;
    unsigned int nps;
    unsigned int full[NFA_MAX_ALPHABET_SIZE];

    fail_state = (unsigned int *)nfa->fail_state;
    ps_index = 0;
    /* count total state transitions, account for state and control words  */
    nps = 0;
    for (k = 0;k < nfa->count_state; k++) {
        /* state word */
        nps++;
        /* control word */
        nps++;
        /* count transitions */
        nc = 0;
        nfa_list_conv_row_to_full(nfa, (unsigned int)k, full);
        for (i = 0; i < NFA_MAX_ALPHABET_SIZE; i++) {
            state = full[i] & NFA_SPARSE_MAX_STATE;
            if (state) {
                nc++;
            }
        }
        /* add in transition count */
        if (k == 0 || nc > NFA_SPARSE_MAX_ROW_TRANSITIONS) {
            nps += NFA_MAX_ALPHABET_SIZE;
        } else {
            for (i = 0; i < NFA_MAX_ALPHABET_SIZE; i++) {
                state = full[i] & NFA_SPARSE_MAX_STATE;
                if (state) {
                    nps++;
                }
            }
        }
    }

    /* check if we have too many states + transitions */
    if (nps > NFA_SPARSE_MAX_STATE) {
        return -1;
    }

    /* malloc the transition list */
    ps = malloc(sizeof(unsigned int) * nps);
    if (ps == NULL) {
        return -1;
    }
    memset(ps, 0, sizeof(unsigned int) * nps);
    nfa->trans_list = ps;

    /* state index list for pi */
    pi = malloc(sizeof(unsigned int) * nfa->count_state);
    if (pi == NULL) {
        return -1;
    }
    memset(pi, 0, sizeof(unsigned int) * nfa->count_state);
    /* build the transition list array */
    for (k = 0; k < nfa->count_state; k++) {
        /* save index of start of state 'k' */
        pi[k] = ps_index;
        /* save the state were in as the 1st word */
        ps[ps_index] = k;
        /* skip past state word */
        ps_index++;
        /* conver state 'k' to full format */
        nfa_list_conv_row_to_full(nfa, (unsigned int)k, full);
        /* count transitions */
        nc = 0;
        for (i = 0; i < NFA_MAX_ALPHABET_SIZE; i++) {
            state = full[i] & NFA_SPARSE_MAX_STATE;
            if (state) {
                nc++;
            }
        }
        /* add a full state or a sparse state  */
        if (k == 0 || nc > NFA_SPARSE_MAX_ROW_TRANSITIONS) {
            /* set the control word */
            ps[ps_index] = NFA_SPARSE_FULL_BIT;
            ps[ps_index] |= fail_state[k] & NFA_SPARSE_MAX_STATE;
            if (nfa->match_list[k]) {
                ps[ps_index] |= NFA_SPARSE_MATCH_BIT;
            }
            ps_index++;
            /* copy the transitions */
            nfa_list_conv_row_to_full(nfa, (unsigned int)k, &ps[ps_index]);
            /* add in 256 transitions */
            ps_index += NFA_MAX_ALPHABET_SIZE;

        } else {
            /* set the control word */
            ps[ps_index] = nc << NFA_SPARSE_COUNT_SHIFT;
            ps[ps_index] |= fail_state[k] & NFA_SPARSE_MAX_STATE;
            if (nfa->match_list[k]) {
                ps[ps_index] |= NFA_SPARSE_MATCH_BIT;
            }
            ps_index++;
            /* add in the transitions */
            for (m = 0, i = 0; i < NFA_MAX_ALPHABET_SIZE && m < nc; i++) {
                state = full[i] & NFA_SPARSE_MAX_STATE;
                if (state) {
                    ps[ps_index++] = (i << NFA_SPARSE_VALUE_SHIFT) | state;
                    m++;
                }
            }
        }
    }

    /* sanity check we have not overflowed our buffer */
    if (ps_index > nps) {
        free(pi);
        return -1;
    }

    /* replace transition states with transition indices.
    this allows us to skip using next state[] to locate the next state
    this limits us to < 16M transitions due to 24 bit state sizes, and the
    fact we have now converted next state fields to next index fields 
    in this array, and we have merged the next-state and state arrays. */
    ps_index = 0;
    for (k = 0; k < nfa->count_state; k++) {
        if (pi[k] >= nps) {
            free(pi);
            return -1;
        }
        /* skip state id */
        ps_index++;        
        /* full Format */
        if (ps[ps_index] & NFA_SPARSE_FULL_BIT) {
            /* do the fail-state */
            ps[ps_index] = (ps[ps_index] & NFA_SPARSE_CLEAN_STATE ) |
                (pi[ps[ps_index] & NFA_SPARSE_MAX_STATE]) ;
            ps_index++;
            /* do the transition-states */
            for (i = 0; i < NFA_MAX_ALPHABET_SIZE; i++) {
                ps[ps_index] = (ps[ps_index] & NFA_SPARSE_CLEAN_STATE) |
                    (pi[ps[ps_index] & NFA_SPARSE_MAX_STATE]) ;
                ps_index++;
            }
        } else {
            /* sparse Format */
            nc = (ps[ps_index] & NFA_SPARSE_COUNT_BITS) >>
                NFA_SPARSE_COUNT_SHIFT;
            /* do the cw = [cb | fail-state] */
            ps[ps_index] = (ps[ps_index] & NFA_SPARSE_CLEAN_STATE ) |
                (pi[ps[ps_index] & NFA_SPARSE_MAX_STATE]);
            ps_index++;
            /* do the transition-states */
            for (i = 0; i < nc; i++) {
                ps[ps_index] = (ps[ps_index] & NFA_SPARSE_CLEAN_STATE ) |
                   (pi[ps[ps_index] & NFA_SPARSE_MAX_STATE]);
                ps_index++;
            }
        }

        /* check for buffer overflow again */
        if (ps_index > nps) {
            free(pi);
            return -1;
        }
    }
    free(pi);

    return 0;
}

/* binary array search on sparse transition array
    O(logN) search times..same as a binary tree.
    data must be in sorted order in the array.
    return: = -1 => not found
            >= 0  => index of element 'val'
    notes:
    val is tested against the high 8 bits of the 'a' array entry,
    this is particular to the storage format we are using. */
static inline int nfa_bsearch(unsigned int *a, int a_len, int val)
{
    int m, l, r;
    int c;

    l = 0;
    r = a_len - 1;

    while (r >= l) {
        m = (r + l) >> 1;
        c = a[m] >> NFA_SPARSE_VALUE_SHIFT;
        if (val == c) {
            return m;
        } else if (val < c) {
            r = m - 1;
        } else {
            /* val > c */
            l = m + 1;
        }
    }

    return -1;
}

/* sparse format for state table using single array storage
    word 1: state
    word 2: control-word = cb << 24| fs
    cb    : control-byte
        mb | fb | nt
    mb : bit 8 set if match state, zero otherwise
    fb : bit 7 set if using full format, zero otherwise
    nt : number of transitions 0..63 (more than 63 requires full format)
    fs : failure-transition-state
    word 3+: byte-value(0-255) << 24 | transition-state */
static inline unsigned int nfa_get_next_state_csparse_nfa(unsigned int *pcx,
    unsigned int sindex, unsigned int input)
{
    int k, nc, index;
    register unsigned int *pcs;

    for (;;) {
        /* skip state-id == 1st word */
        pcs = pcx + sindex + 1;
        if (pcs[0] & NFA_SPARSE_FULL_BIT) {
            if (sindex == 0) {
                return (pcs[input + 1] & NFA_SPARSE_MAX_STATE);
            } else {
                if (pcs[input + 1] & NFA_SPARSE_MAX_STATE) {
                    return (pcs[input + 1] & NFA_SPARSE_MAX_STATE);
                }
            }
        } else {
            nc = (pcs[0] >> NFA_SPARSE_COUNT_SHIFT) &
                NFA_SPARSE_MAX_ROW_TRANSITIONS;
            if (nc > NFA_SPARSE_LINEAR_SEARCH_LIMIT) {
                /* binary search... */
                index = nfa_bsearch(pcs + 1, nc, input);
                if (index >= 0) {
                    return (pcs[index + 1] & NFA_SPARSE_MAX_STATE);
                }
            } else {
                /* linear search... */
                for (k = 0; k < nc; k++) {
                    if ((pcs[k + 1] >> NFA_SPARSE_VALUE_SHIFT) == input) {
                        return (pcs[k + 1] & NFA_SPARSE_MAX_STATE);
                    }
                }
            }
        }

        /* no transition found ... get the failure state and try again  */
        sindex = pcs[0] & NFA_SPARSE_MAX_STATE;
    }

    return NFA_FAIL_STATE;
}

struct nfa *nfa_init(void)
{
    struct nfa *nfa;

    nfa = malloc(sizeof(*nfa));
    if (nfa == NULL) {
        return NULL;
    }
    memset(nfa, 0, sizeof(*nfa));

    return nfa;
}

int nfa_add_pattern(struct nfa *nfa, const unsigned char *pattern,
        int patlen, void *data, void (*func)(void *))
{
    struct nfa_pattern *pat;

    pat = malloc(sizeof(*pat) + patlen);
    if (pat == NULL) {
        return -1;
    }
    memset(pat, 0, sizeof(*pat) + patlen);
    pat->pattern = (unsigned char *)(pat + 1);
    memcpy (pat->pattern, pattern, patlen);
    pat->patlen = patlen;
    pat->data = data;
    pat->func = func;
    /* insert at front of list */
    pat->next = nfa->pattern;
    nfa->pattern = pat;
    nfa->count_pattern++;

    return 0;
}

int nfa_compile(struct nfa *nfa)
{
    struct nfa_pattern *pat;
    struct nfa_match_node **node;
    unsigned int match_state;
    int i;

    /* count number of states */
    for (pat = nfa->pattern; pat != NULL; pat = pat->next) {
        nfa->max_state += pat->patlen;
    }
    /* one extra */
    nfa->max_state++;

    /* alloc a List based State Transition table */
    nfa->trans_table = malloc(sizeof(struct nfa_trans_node *)
        * nfa->max_state);
    if (nfa->trans_table == NULL) {
        return -1;
    }
    memset(nfa->trans_table, 0, sizeof(struct nfa_trans_node *)
        * nfa->max_state);

    /* alloc a match list table, this has a list of pattern matches 
        for each state */
    nfa->match_list = malloc(sizeof(void *) * nfa->max_state);
    if (nfa->match_list == NULL) {
        return -1;
    }
    memset(nfa->match_list, 0, sizeof(void *) * nfa->max_state);

    /* add each pattern to the state table, this forms a keyword trie
        using lists */
    nfa->count_state = 0;
    for (pat = nfa->pattern; pat != NULL; pat = pat->next) {
        nfa_add_pattern_states(nfa, pat);
    }
    nfa->count_state++;

    if (nfa->count_state > NFA_SPARSE_MAX_STATE) {
        /* call nfa_free() to clean up */
        return -1;
    }

    /* realloc a smaller match list table, only need num states  */
    node = nfa->match_list;
    nfa->match_list = malloc(sizeof(void *) * nfa->count_state);
    if (nfa->match_list == NULL) {
        nfa->match_list = node;
        return -1;
    }
    memset(nfa->match_list, 0, sizeof(void *) * nfa->count_state);
    memcpy(nfa->match_list, node, 
        sizeof(void *) * nfa->count_state);
    free(node);

    /* alloc a failure state table, only need num states */
    nfa->fail_state = malloc(sizeof(unsigned int) * nfa->count_state);
    if (nfa->fail_state == NULL) {
        return -1;
    }
    memset(nfa->fail_state, 0, sizeof(unsigned int) * nfa->count_state);

    /* build the nfa w/failure states, time the nfa construction. */
    if (nfa_build(nfa)) {
        return -1;
    }

    /* convert nfa storage format from list to full or sparse. */
    if (nfa_conv_list_to_csparse_array(nfa)) {
        return -1;
    }
    free(nfa->fail_state);
    nfa->fail_state = NULL;

    /* free up the transition table lists */
    nfa_free_trans_table(nfa);

    /* count states with Pattern Matches */
    match_state = 0;
    for (i = 0; i < nfa->count_state; i++) {
        if (nfa->match_list[i]) {
            match_state++;
        }
    }
    nfa->match_state = match_state;

    return 0;
}

int nfa_find(struct nfa *nfa, const unsigned char *text, int text_len,
        struct nfa_pattern **pat)
{
    struct nfa_match_node *mlist, **match_list;
    const unsigned char *text_pos, *text_end;
    struct nfa_pattern *pattern;
    unsigned int *trans_list, sindex;
    unsigned int last_match;
    int index;


    text_pos = text;
    text_end = text + text_len;
    match_list = nfa->match_list;
    trans_list = nfa->trans_list;
    last_match = NFA_LAST_STATE_INIT;

    /* reset state machine */
    sindex = 0;
    for (; text_pos < text_end; text_pos++) {
        /* transition to next state index */
        sindex = nfa_get_next_state_csparse_nfa(trans_list, sindex, *text_pos);
        /* log matches in this state */
        if (sindex && (trans_list[sindex + 1] & NFA_SPARSE_MATCH_BIT)) {
            if (sindex == last_match) {
                continue;
            }
            mlist = match_list[trans_list[sindex]];
            pattern = (struct nfa_pattern *)(mlist->data);
            index = text_pos - text - pattern->patlen + 1;

            if (pat) {
                *pat = pattern;
            }
            return index;
        }
    }

    return -1;
}


void nfa_destroy(struct nfa *nfa)
{
    int i;
    struct nfa_pattern *pat, *p;
    struct nfa_match_node *mlist, *q;

    /* free patterns */
    pat = nfa->pattern;
    while (pat) {
        p = pat;
        pat = pat->next;
        if (p->func && p->data) {
            p->func(p->data);
        }
        free(p);
    }

    /* free trans table */
    nfa_free_trans_table(nfa);

    /* free match list entries */
    if (nfa->match_list) {
        for (i = 0; i < nfa->count_state; i++) {
            mlist = nfa->match_list[i];
            while (mlist) {
                q = mlist;
                mlist = mlist->next;
                free(q);
            }
        }
        free(nfa->match_list);
    }

    /* free arrays */
    if (nfa->fail_state) {
        free(nfa->fail_state);
    }
    if (nfa->trans_list) {
        free(nfa->trans_list);
    }

    free(nfa);

    return;
}


#ifdef TEST
int main(int argc, const char **argv)
{
#if 0
    struct bm *bm = bm_init(argv[1], strlen(argv[1]));
    int ret = bm_find(bm, argv[2], strlen(argv[2]));
    printf("pattern:[%s]\ntext:[%s]\nret=[%d].\n", argv[1], argv[2], ret);
    bm_destroy(bm);
#endif
#if 0
    struct kmp *kmp = kmp_init(argv[1], strlen(argv[1]));
    int ret = kmp_find(kmp, argv[2], strlen(argv[2]));
    printf("pattern:[%s]\ntext:[%s]\nret=[%d].\n", argv[1], argv[2], ret);
    kmp_destroy(kmp);
#endif
    int ret;
    struct nfa *nfa = nfa_init();
    ret = nfa_add_pattern(nfa, argv[1], strlen(argv[1]), NULL, NULL);
    printf("add(), ret=[%d].\n", ret);
    ret = nfa_add_pattern(nfa, argv[2], strlen(argv[2]), NULL, NULL);
    printf("add(), ret=[%d].\n", ret);
    ret = nfa_compile(nfa);
    printf("compile(), ret=[%d].\n", ret);
    ret = nfa_find(nfa, argv[3], strlen(argv[3]), NULL);
    printf("find(), ret=[%d].\n", ret);
    nfa_destroy(nfa);

    return 0;
}
#endif

