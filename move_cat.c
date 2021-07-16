/*
** EPITECH PROJECT, 2020
** move_cat.c
** File description:
** move the cat
*/

#include "include/graphic.h"

obj_t *initialize_move(obj_t *cat)
{
    if (cat->m == 1)
        cat = jump_cat(cat);
    else
        cat = move_cat(cat);
    return (cat);
}

obj_t *move_cat_2(obj_t *cat)
{
    sfIntRect dim = {0, 0, 512, 256};
    int div = cat->i / 2;

    if (cat->i % 2 == 0) {
        dim.left = 512;
        dim.top = (div - 1) * 260;
    } else
        dim.top = div * 260;
    cat->dim = dim;
    return (cat);
}

obj_t *move_cat(obj_t *cat)
{
    sfIntRect dim = {0, 0, 512, 256};
    sfVector2f pos = {356, 499};
    int div = cat->i / 2;

    sfSprite_setRotation(cat->sprite, 0);
    if (cat->i % 2 != 0) {
        dim.left = 512;
        dim.top = div * 260;
    } else if (cat->i != 8)
        dim.top = div * 260;
    else
        cat->i = 0;
    cat->i++;
    sfSprite_setTextureRect(cat->sprite, dim);
    return (cat);
}

void move_cat_end(obj_t *cat)
{
    cat->pos.x -= 30;
    sfSprite_setPosition(cat->sprite, cat->pos);
}
