/*
** EPITECH PROJECT, 2020
** background.c
** File description:
** map runner
*/

#include "include/graphic.h"

all_t *create_background(ini_t ini, fct_t *fct, all_t *all)
{
    ini.pos = initialize_pos(0, 0, ini.pos);
    ini.dim = initialize_dim(0, 0, 1280, 501);
    all->bg_3 = create_object("image/background_white-min.png", ini);
    ini.pos = initialize_pos(1275, 0, ini.pos);
    ini.dim = initialize_dim(5, 0, 5, 501);
    all->bg_33 = create_object("image/background_white-min.png", ini);
    ini.pos = initialize_pos(0, 285, ini.pos);
    ini.dim = initialize_dim(0, 0, 1280, 336);
    all->bg_2 = create_object("image/background_mountain.png", ini);
    ini.pos = initialize_pos(1280, 285, ini.pos);
    ini.dim = initialize_dim(0, 0, 0, 336);
    all->bg_22 = create_object("image/background_mountain.png", ini);
    ini.pos = initialize_pos(0, 620, ini.pos);
    ini.dim = initialize_dim(0, 0, 1280, 141);
    all->bg_1 = create_object("image/devant_2.png", ini);
    ini.pos = initialize_pos(1280, 620, ini.pos);
    ini.dim = initialize_dim(0, 0, 0, 141);
    all->bg_11 = create_object("image/devant_2.png", ini);
    return (all);
}

void move_bg_1(all_t **all_tmp)
{
    all_t *all = *all_tmp;

    if (all->bg_1->dim.width != 0) {
        all->bg_1->dim.left += 20;
        all->bg_1->dim.width -= 20;
        all->bg_11->pos.x -= 20;
        all->bg_11->dim.width += 20;
    } else {
        all->bg_1->dim.left = 20;
        all->bg_1->dim.width = 1260;
        all->bg_11->pos.x = 1260;
        all->bg_11->dim.width = 20;
    }
    sfSprite_setTextureRect(all->bg_1->sprite, all->bg_1->dim);
    sfSprite_setTextureRect(all->bg_11->sprite, all->bg_11->dim);
    sfSprite_setPosition(all->bg_11->sprite, all->bg_11->pos);
    *all_tmp = all;
}

void move_bg_2(all_t **all_tmp)
{
    all_t *all = *all_tmp;

    if (all->bg_2->dim.width > 0) {
        all->bg_2->dim.left += 3;
        all->bg_2->dim.width -= 3;
        all->bg_22->pos.x -= 3;
        all->bg_22->dim.width += 3;
    } else {
        all->bg_2->dim.left = 0;
        all->bg_2->dim.width = 1280;
        all->bg_22->pos.x = 1280;
        all->bg_22->dim.width = 0;
    }
    sfSprite_setTextureRect(all->bg_2->sprite, all->bg_2->dim);
    sfSprite_setTextureRect(all->bg_22->sprite, all->bg_22->dim);
    sfSprite_setPosition(all->bg_22->sprite, all->bg_22->pos);
    *all_tmp = all;
}

void move_bg_3(all_t **all_tmp)
{
    all_t *all = *all_tmp;

    if (all->bg_3->dim.width != 0) {
        all->bg_3->dim.left += 1;
        all->bg_3->dim.width -= 1;
        all->bg_33->pos.x -= 1;
        all->bg_33->dim.width += 1;
    } else {
        all->bg_3->dim.left = 0;
        all->bg_3->dim.width = 1280;
        all->bg_33->pos.x = 1275;
        all->bg_33->dim.width = 5;
    }
    sfSprite_setTextureRect(all->bg_3->sprite, all->bg_3->dim);
    sfSprite_setTextureRect(all->bg_33->sprite, all->bg_33->dim);
    sfSprite_setPosition(all->bg_33->sprite, all->bg_33->pos);
    *all_tmp = all;
}
