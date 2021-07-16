/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** counts the number of characters, task3, day4
*/

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
