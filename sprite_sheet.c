/*
** EPITECH PROJECT, 2020
** sprite_sheet.c
** File description:
** character of a game
*/

#include "include/graphic.h"

all_t *create_cat(ini_t ini, all_t *all)
{
    ini.pos = initialize_pos(356, 499, ini.pos);
    ini.dim = initialize_dim(0, 0, 512, 256);
    all->cat = create_object("image/persian.png", ini);
    ini.pos = initialize_pos(150, 430, ini.pos);
    ini.dim = initialize_dim(0, 0, 560, 300);
    all->cat_end = create_object("image/cat_end.png", ini);
    all->cat->i = 1;
    all->cat->stop = 0;
    all->cat->m = 0;
    all->cat->cmp = 0;
    all->cat->origin = initialize_pos(256, 128, all->cat->origin);
    sfSprite_setOrigin(all->cat->sprite, all->cat->origin);
    return (all);
}

all_t *create_character(ini_t ini, all_t *all)
{
    ini.pos = initialize_pos(0, 0, ini.pos);
    ini.dim = initialize_dim(0, 266, 125, 133);
    all->ps = create_object("image/ninja.png", ini);
    return (all);
}

sfFloatRect change_dim(float x, float y, float width, float height)
{
    sfFloatRect dim;

    dim.left = x;
    dim.top = y;
    dim.width = width;
    dim.height = height;
    return (dim);
}

obj_t *move_character(obj_t *ps)
{
    sfIntRect dim = {0, 266, 125, 133};
    sfVector2f pos = {0, 0};

    if (ps->i < 5) {
        dim.left = 0 + (125 * ps->i);
    } else
        ps->i = 0;
    ps->i++;
    sfSprite_setTextureRect(ps->sprite, dim);
    sfSprite_setPosition(ps->sprite, pos);
    return (ps);
    
}
