#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Two processes let Python capture bytes and return value independently. */
int main(int argc, char **argv)
{
    int result;
    int custom;
    char type;
    if (argc != 5)
        return 2;
    custom = strcmp(argv[1], "custom") == 0;
    type = argv[2][strlen(argv[2]) - 1];
    if (type == 'd' || type == 'i') {
        int value = (int)strtol(argv[3], NULL, 10);
        result = custom ? ft_printf(argv[2], value) : printf(argv[2], value);
    } else {
        unsigned int value = (unsigned int)strtoul(argv[3], NULL, 10);
        result = custom ? ft_printf(argv[2], value) : printf(argv[2], value);
    }
    fprintf(stderr, "%d", result);
    return 0;
}
