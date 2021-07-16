/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** displays the characters of a string, task2, day4
*/
#include <unistd.h>
int my_strlen(char const *str);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
