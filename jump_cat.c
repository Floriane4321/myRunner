/*
** EPITECH PROJECT, 2021
** jump_cat.c
** File description:
** fonction about jump cat
*/

#include "include/graphic.h"

obj_t *jump_cat(obj_t *cat)
{
    sfIntRect dim = {512, 780, 512, 256};

    if (cat->pos.y >= cat->ini.pos.y && cat->stop == 85) {
        cat->stop = 0;
        cat->m = 0;
        cat->i = 3;
        return (cat);
    }
    if (cat->stop != 84 && cat->stop != 85) {
        cat->ini.pos.y = cat->pos.y;
        cat->stop = 84;
        cat->i = 6;
    }
    cat = jump_cat_2(cat);
    sfSprite_setRotation(cat->sprite, cat->deg);
    sfSprite_setOrigin(cat->sprite, cat->origin);
    sfSprite_setTextureRect(cat->sprite, cat->dim);
    sfSprite_setPosition(cat->sprite, cat->pos);
    return (cat);
}

obj_t *jump_cat_2(obj_t *cat)
{
    if (cat->pos.y >= 250 && cat->stop != 85) {
        cat->deg = 340;
        if (cat->pos.y > 489) {
            cat->pos.y -= 20;
            cat->i = 6;
        } else if (cat->pos.y > 469) {
            cat->pos.y -= 30;
            cat->i = 7;
        } else {
            cat->pos.y -= 30;
            cat->i = 8;
        }
    } else {
        cat->i = 8;
        cat = jump_cat_3(cat);
    }
    cat = move_cat_2(cat);
    return (cat);
}

obj_t *jump_cat_3(obj_t *cat)
{
    cat->stop = 85;
    if (cat->deg < 380) {
        if (cat->cmp > 10)
            cat->deg += 10;
        else {
            cat->cmp++;
            cat->deg += 3;
        }
    } else if (cat->pos.y <= 488) {
        cat->cmp = 0;
        cat->i = 1;
        cat->pos.y += 25;
    } else {
        cat->pos.y += 10;
        cat->i = 2;
    }
    return (cat);
}
