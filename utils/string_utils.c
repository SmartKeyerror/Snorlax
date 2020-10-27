#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

const char characters[63] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void generate_random_string(char *dest, const unsigned int len) {

    struct timeval tpstart;
    gettimeofday(&tpstart, NULL);

    srand(tpstart.tv_usec);

    for (unsigned int i = 0; i < len; i++) {
        *dest++ = characters[rand() % 62];
    }
    *dest = '\0';
}
