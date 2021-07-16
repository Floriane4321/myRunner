/*
** EPITECH PROJECT, 2021
** modif_str.c
** File description:
** modification of str (reduice)
*/

#include "include/graphic.h"

char *modif_str(char *str, int pos)
{
    int len = my_strlen(str);
    char *dest;
    int i;

    pos++;
    if (pos > len)
        return (0);
    dest = malloc(sizeof(char) * (len - pos + 1));
    for (i = 0; pos < len; pos++)
        dest[i++] = str[pos];
    dest[i] = 0;
    free(str);
    return (dest);
}
