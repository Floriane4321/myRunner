/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** a function that reverses a string, task3, day6
*/
void my__putchar(char c);

char *my_revstr(char *str)
{
    int len = 0;
    int i = 0;
    char c;

    while (str[len] != '\0')
        len++;
    len = len - 1;
    if (len / 2 == 0) {
        c = str[len - i];
        str[len - i] = str[i];
        str[i] = c;
    }
    while (i <= len / 2 && len / 2 != 0) {
        c = str[len - i];
        str[len - i] = str[i];
        str[i] = c;
        i++;
    }
    return (str);
}
