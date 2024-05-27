/*
** EPITECH PROJECT, 2023
** int_to_str
** File description:
** int_to_str
*/
#include <stdlib.h>

static int nbr_len(int nb)
{
    int n = 0;

    if (nb == 0)
        n = n + 1;
    if (nb < 0) {
        n = n + 1;
        nb = nb * -1;
    }
    while (nb > 0) {
        nb = nb / 10;
        n = n + 1;
    }
    return n;
}

static void add_int_to_str(int nb, char *str, int n)
{
    while (nb >= 1) {
        str[n - 1] = nb % 10 + '0';
        nb = nb / 10;
        n --;
    }
}

char *int_to_str(int nb)
{
    int n = nbr_len(nb);
    char *str = malloc(sizeof(char) * (n + 1));

    str[n] = '\0';
    if (nb == 0) {
        str[0] = '0';
        return str;
    }
    if (nb < 0) {
        nb = nb * -1;
        add_int_to_str(nb, str, n);
        str[0] = '-';
        return str;
    }
    add_int_to_str(nb, str, n);
    return str;
}
