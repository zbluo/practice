#include <stdio.h>

#define CIPHER_FUNC(keybits, mode) \
int aes_##keybits##_##mode() { \
    printf("\n%d\n", 9##keybits##8); \
    return 300; \
} 

CIPHER_FUNC(256, gcm);