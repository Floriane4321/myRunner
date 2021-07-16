/*
** EPITECH PROJECT, 2021
** image_end.c
** File description:
** image end
*/

#include "include/graphic.h"

all_t *create_image_end(all_t *all)
{
    ini_t ini;

    ini.pos = initialize_pos(90, 20, ini.pos);
    ini.dim = initialize_dim(0, 0, 1064, 722);
    all->end = create_object("image/blood_2.png", ini);
    return (all);
}

void create_press_enter(all_t *all)
{
    ini_t ini;

    ini.pos = initialize_pos(125, 140, ini.pos);
    ini.dim = initialize_dim(0, 0, 1000, 1000);
    all->enter = create_object("image/press_enter.png", ini);
}

void display_score_end(all_t *all, fct_t *fct, sfEvent event)
{
    while (sfRenderWindow_isOpen(fct->window) && fct->stop != 2) {
        while(sfRenderWindow_pollEvent(fct->window, &event))
            condition_close(fct, event);
        modif_text_score(all->txt);
        display_lose(fct, all);
    }
}

void image_lost(char *filepath, all_t *all, fct_t *fct, sfEvent event)
{
    sfMusic_stop(all->music);
    sfMusic_play(all->explosion);
    fct->stop = 0;
    while (fct->stop == 0) {
        while(sfRenderWindow_pollEvent(fct->window, &event))
            condition_close(fct, event);
        sfRenderWindow_clear(fct->window, sfWhite);
        sfRenderWindow_drawSprite(fct->window, all->end->sprite, NULL);
        sfRenderWindow_drawSprite(fct->window, fct->sprite, NULL);
        sfRenderWindow_drawSprite(fct->window, all->enter->sprite, NULL);
        sfRenderWindow_display(fct->window);
    }
    fct->stop = 1;
    display_score_end(all, fct, event);
}
