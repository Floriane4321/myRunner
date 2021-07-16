/*
** EPITECH PROJECT, 2020
** my_getstr.c
** File description:
** int under char
*/
#include <stdlib.h>
#include <stdio.h>

char *my_revstr(char *str);
int my_nblen(int nb);

char *my_getstr(int nb)
{
    char *dest = malloc(sizeof(char) * (my_nblen(nb) + 2));
    int aco = nb;
    int i = 0;

    dest[my_nblen(nb)] = 0;
    if (nb < 0) {
        dest[my_nblen(nb) + 1] = 0;
        nb = nb * (-1);
    }
    for (; i < my_nblen(aco); i++) {
        dest[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    if (aco < 0)
        dest[i] = '-';
    dest = my_revstr(dest);
    return (dest);
}

int my_nblen(int nb)
{
    int i = 10;
    int j;
    int aco = nb;

    if (nb < 0)
        nb = nb * (-1);
    for (j = 1; nb / i > 0; j++)
        i = i * 10;
    return (j);
}
