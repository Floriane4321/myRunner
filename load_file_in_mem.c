/*
** EPITECH PROJECT, 2020
** load_file_in_mem.c
** File description:
** bsbsq step4_1
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *load_file_in_mem(char const *filepath)
{
    struct stat len;
    int fd = open(filepath, O_RDONLY);
    int size;
    char *buffer;
    int lens;

    if (fd == -1)
        return ("\0");
    stat(filepath, &len);
    if (stat(filepath, &len) == -1)
        return (0);
    size = len.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    lens = read(fd, buffer, size);
    close(fd);
    if (lens <= 0)
        return (0);
    buffer[size] = 0;
    return (buffer);
}
