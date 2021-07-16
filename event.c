/*
** EPITECH PROJECT, 2020
** event.c
** File description:
** check event
*/

#include "include/graphic.h"

all_t *analyse_events(sfRenderWindow *window, sfEvent event, all_t *all)
{
    while(sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event.mouseButton, all);
        if (event.type == sfEvtKeyPressed)
            all = key_pressed(event.key, all, window);
    }
    return (all);
}

all_t *key_pressed(sfKeyEvent event, all_t *all, sfRenderWindow *window)
{
    if (event.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.code == sfKeySpace)
        all->cat->m = 1;
    return (all);
}

void manage_mouse_click(sfMouseButtonEvent event, all_t *all)
{
    sfFloatRect dim = sfSprite_getGlobalBounds(all->start->sprite);

    if (event.x >= dim.left && event.x <= dim.left + dim.width) {
        if (event.y >= dim.top && event.y <= dim.top + dim.height)
            all->start->stop = 1;
    }
}
