#include "main.h"
#include <stdio.h>
/**
 * binary_to_uint - Converts a binary number represented as a string to an unsigned integer.
 *
 * @b: The binary string to convert. It should consist of '0' and '1' characters only.
 *
 * Return: The converted decimal number as an unsigned int. If the input string is NULL or
 *         contains any character other than '0' and '1', the function returns 0.
 */
unsigned int binary_to_uint(const char *b) {
    unsigned int total = 0;
    unsigned int power = 1;
    int len;

    if (b == NULL)
        return 0;

    for (len = 0; b[len] != '\0'; len++) {
        if (b[len] != '0' && b[len] != '1')
            return 0;
    }

    len--;

    for (; len >= 0; len--, power *= 2) {
        if (b[len] == '1')
            total += power;
    }

    return total;
}
