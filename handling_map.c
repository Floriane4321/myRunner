/*
** EPITECH PROJECT, 2021
** handling_map.c
** File description:
** handling obstacle in the map
*/

#include "include/graphic.h"

all_t *handling_obstacle_map(all_t *all)
{
    if (all->obs_1->stop == 0) {
        all->obs_1->pos.x = 1280;
        all->obs_1->stop = 1;
    } else if (all->obs_2->stop == 0) {
        all->obs_2->pos.x = 1280;
        all->obs_2->stop = 1;
    } else {
        if (all->obs_3->stop == 0) {
            all->obs_3->pos.x = 1280;
            all->obs_3->stop = 1;
        } else if (all->obs_4->stop == 0) {
            all->obs_4->pos.x = 1280;
            all->obs_4->stop = 1;
        } else {
            all->obs_1->pos.x = 1280;
            all->obs_1->stop = 1;
        }
    }
    return (all);
}
