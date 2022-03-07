#include <stdio.h>

#define CIPHER_FUNC(keybits, mode) \
int aes_##keybits##_##mode() { \
    printf("\n%d\n", 9##keybits##8); \
    return 300; \
} \
aes_256_gcm()

int main(int argc, char *argv[])
{
    CIPHER_FUNC(256, gcm);
}
