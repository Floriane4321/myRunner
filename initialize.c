/*
** EPITECH PROJECT, 2021
** initialize.c
** File description:
** initialize parameter
*/

#include "include/graphic.h"

sfVector2f initialize_pos(float x, float y, sfVector2f pos)
{
    pos.x = x;
    pos.y = y;
    return (pos);
}

sfIntRect initialize_dim(int x, int y, int width, int height)
{
    sfIntRect dim;

    dim.left = x;
    dim.top = y;
    dim.width = width;
    dim.height = height;
    return (dim);
}

all_t *initialize_create(fct_t *fct, all_t *all)
{
    ini_t ini;

    all = create_background(ini, fct, all);
    all = create_character(ini, all);
    all = create_cat(ini, all);
    all->obs_1 = create_obstacle(ini, all->obs_1);
    all->obs_2 = create_obstacle(ini, all->obs_2);
    all->obs_3 = create_obstacle(ini, all->obs_3);
    all->obs_4 = create_obstacle(ini, all->obs_4);
    all = create_image_end(all);
    create_press_enter(all);
    return (all);
}
