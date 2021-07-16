/*
** EPITECH PROJECT, 2020
** obstacles.c
** File description:
** fonction about obstacles
*/

#include "include/graphic.h"

obj_t *create_obstacle(ini_t ini, obj_t *obs)
{
    ini.pos = initialize_pos(1280, 421, ini.pos);
    ini.dim = initialize_dim(0, 0, 272, 271);
    obs = create_object("image/rocher_2.png", ini);
    obs->stop = 0;
    return (obs);
}

obj_t *move_obstacle(obj_t *obs)
{
    if (obs->pos.x < -250)
        obs->stop = 0;
    else
        obs->pos.x -= 20;
    sfSprite_setPosition(obs->sprite, obs->pos);
    return (obs);
}
