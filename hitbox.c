/*
** EPITECH PROJECT, 2021
** hitbox.c
** File description:
** hitbox cat
*/

#include "include/graphic.h"

obj_t *hitbox_cat(obj_t *cat)
{
    cat->hb = sfSprite_getGlobalBounds(cat->sprite);
    cat->hb.left += 200;
    cat->hb.top += 130;
    cat->hb.width = 200;
    cat->hb.height = 50;
    return (cat);
}

obj_t *hitbox_obs(obj_t *obs)
{
    obs->hb = sfSprite_getGlobalBounds(obs->sprite);
    obs->hb.left += 30;
    obs->hb.top += 40;
    obs->hb.width = 212;
    obs->hb.height = 192;
    return (obs);
}

void check_pos(obj_t *cat, obj_t *obs)
{
    float cat_xo = cat->hb.left;
    float cat_yo = cat->hb.top;
    float obs_xo = obs->hb.left;
    float obs_yo = obs->hb.top;
    float cat_xf = cat->hb.left + cat->hb.width;
    float cat_yf = cat->hb.top + cat->hb.height;
    float obs_xf = obs->hb.left + obs->hb.width;
    float obs_yf = obs->hb.top + obs->hb.height;

    if (obs_xo > cat_xo && obs_xo < cat_xf) {
        if (obs_yo > cat_yo && obs_yo < cat_yf)
            cat->stop = 1;
        if (cat_yo > obs_yo && cat_yo < obs_yf)
            cat->stop = 1;
    } else if (obs_xf > cat_xo && obs_xf < cat_xf) {
        if (obs_yf > cat_yo && obs_yf < cat_yf)
            cat->stop = 1;
        if (cat_yf > obs_yo && cat_yf < obs_yf)
            cat->stop = 1;
    }
}

all_t *hitbox_main(all_t *all)
{
    all->cat = hitbox_cat(all->cat);
    all->obs_1 = hitbox_obs(all->obs_1);
    all->obs_2 = hitbox_obs(all->obs_2);
    all->obs_3 = hitbox_obs(all->obs_3);
    all->obs_4 = hitbox_obs(all->obs_4);
    check_pos(all->cat, all->obs_1);
    check_pos(all->cat, all->obs_2);
    check_pos(all->cat, all->obs_3);
    check_pos(all->cat, all->obs_4);
    return (all);
}
