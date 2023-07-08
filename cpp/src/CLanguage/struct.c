#include <stdio.h>
#include <stdlib.h>

// as long as the struct definition is before the code allocating the memory of that struct, it's OK
typedef struct struct_1_t STRUCT_1;
typedef struct struct_2_t STRUCT_2;

struct struct_1_t {
    unsigned char ch[2];
    int (*init) (STRUCT_2 *st_2);
};

struct struct_2_t {
    int i[2];
    int (*init) (STRUCT_1 *st_1);
};

STRUCT_2 myst2 = {{11, 22}, NULL};

int do_sth(STRUCT_2 *st2) {
    printf("\n%d\n", st2->i[0]);
    return 0;
}

STRUCT_1 st1 = {{'a', 'b'}, do_sth};

void test(int argc, char *argv[])
{
    st1.init(&myst2);
}

/******
void foo(void);
That is the correct way to say "no parameters" in C, and it also works in C++.

But:
void foo();
Means different things in C and C++! In C it means "could take any number of parameters of unknown types", and in C++ it means the same as foo(void).
Variable argument list functions are inherently un-typesafe and should be avoided where possible.
******/
