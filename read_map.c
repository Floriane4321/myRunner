/*
** EPITECH PROJECT, 2021
** read_map.c
** File description:
** read the map
*/

#include "include/graphic.h"

fct_t *create_map(char const *filepath, fct_t *fct)
{
    fct->map = load_file_in_mem(filepath);
    return (fct);
}

all_t *fct_main_map(all_t *all, fct_t *fct)
{
    int o = read_map(fct);

    count_score(all->txt, all->gradient);
    if (o == 0)
        return (all);
    if (o == 1)
        all = handling_obstacle_map(all);
    return (all);
}

int read_map(fct_t *fct)
{
    char c = fct->map[0];

    fct->map = modif_str(fct->map, 0);
    if (c == '1')
        return (0);
    if (c == 'o')
        return (1);
}
