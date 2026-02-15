#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int len1, len2;

    len1 = ft_printf("Mine: %c, %s\n", 'A', "Hello");
    len2 =    printf("Real: %c, %s\n", 'A', "Hello");
    printf("Lengths: %d vs %d\n", len1, len2);
    return (0);
}