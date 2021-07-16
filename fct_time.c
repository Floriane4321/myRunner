/*
** EPITECH PROJECT, 2020
** fct_time.c
** File description:
** fonction about time
*/

#include "include/graphic.h"

void time_passed(float n)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfSeconds(n);

    n = sfTime_asSeconds(time);
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < n);
    sfClock_destroy(clock);
}
