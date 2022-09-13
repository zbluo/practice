/***********************************************************
  ac(bnfa) and bm text search algorithm.
***********************************************************/
#ifndef _MATCH_H_
#define _MATCH_H_

/*
    Implements Boyer-Moore string matching algorithm:
    [1] A Fast String Searching Algorithm, R.S. Boyer and Moore.
        Communications of the Association for Computing Machinery, 
        20(10), 1977, pp. 762-772.
        http://www.cs.utexas.edu/users/moore/publications/fstrpos.pdf
    [2] Handbook of Exact String Matching Algorithms, Thierry Lecroq, 2004
        http://www-igm.univ-mlv.fr/~lecroq/string/string.pdf
    CASE SENSITIVE!
*/

struct bm;

struct bm *bm_init(const unsigned char *pattern, int patlen);

void bm_destroy(struct bm *bm);

/* return the position of text where matched, or -1 for not match. */
int bm_find(struct bm *bm, const unsigned char *text, int text_len);

/*
    Implements a linear-time string-matching algorithm due to Knuth,
    Morris, and Pratt(KMP).
    CASE SENSITIVE!
*/

struct kmp;

struct kmp *kmp_init(const unsigned char *pattern, int patlen);

void kmp_destroy(struct kmp *kmp);

/* return the position of text where matched, or -1 for not match. */
int kmp_find(struct kmp *kmp, const unsigned char *text, int text_len);

/*
    Implements multi-pattern search engine using Aho-Corasick construction,
    non-deterministic finite automata(NFA).
    Summary:
        nfa_init();
        for (...)
            nfa_add_pattern();
        nfa_compile();
        nfa_find();
        nfa_destroy();
    CASE SENSITIVE!
*/

/* 
    nfa_find() result.
    readonly struct after init and compile for thread safe.
*/
struct nfa_pattern {
    /* in the nfa storage, all pattern linked as list. please ignore it. */
    struct nfa_pattern *next;
    unsigned char *pattern;
    int patlen;
    /* user private data. */
    void *data;
    /* free function of the private data */
    void (*func)(void *);
};

struct nfa;

struct nfa *nfa_init(void);

int nfa_add_pattern(struct nfa *nfa, const unsigned char *pattern,
        int patlen, void *data, void (*func)(void *));

int nfa_compile(struct nfa *nfa);

/*
    return the first position of text where matched, or -1 for not match.
    if the pat is not NULL, the matched pattern will be set.
*/
int nfa_find(struct nfa *nfa, const unsigned char *text, int text_len,
        struct nfa_pattern **pat);

void nfa_destroy(struct nfa *nfa);

#endif
