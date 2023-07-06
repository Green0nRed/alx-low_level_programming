#include "main.h"
#include "stdio.h"

unsigned int binary_to_uint(const char *b) {
    unsigned int total = 0;
    unsigned int power = 1;
    int len = 0;

    if (b == NULL)
        return 0;

    while (b[len] != '\0') {
        if (b[len] != '0' && b[len] != '1')
            return 0;
        len++;
    }

    for (int i = len - 1; i >= 0; i--) {
        if (b[i] == '1')
            total += power;
        power *= 2;
    }

    return total;
}
