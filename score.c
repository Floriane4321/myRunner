/*
** EPITECH PROJECT, 2021
** score.c
** File description:
** fonction about score
*/

#include "include/graphic.h"

void initialize_score(all_t *all)
{
    ini_t ini;

    ini.pos = initialize_pos(70, -45, ini.pos);
    ini.dim = initialize_dim(0, 10, 3000, 2500);
    all->cadre = create_object("image/cadre_score-min.png", ini);
    all->cadre->origin = initialize_pos(0.08, 0.08, all->cadre->origin);
    sfSprite_setScale(all->cadre->sprite, all->cadre->origin);
    ini.pos = initialize_pos(110, -57, ini.pos);
    ini.dim = initialize_dim(640, 0, 0, 2500);
    all->gradient = create_object("image/gradient.png", ini);
    all->gradient->origin = initialize_pos(0.09, 0.09, all->gradient->origin);
    sfSprite_setScale(all->gradient->sprite, all->gradient->origin);
}

void count_score(txt_t *txt, obj_t *gradient)
{
    gradient->dim.width = (int) (1600 * txt->cmp / txt->map_f);
    sfSprite_setTextureRect(gradient->sprite, gradient->dim);
}
