/*
** EPITECH PROJECT, 2021
** pokemon_3.c
** File description:
** fonction about pokemon
*/

#include "include/graphic.h"

void display_pokemon(fct_t *fct, all_t *all, obj_t *pok)
{
    sfRenderWindow_clear(fct->window, sfBlack);
    sfRenderWindow_drawSprite(fct->window, fct->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_3->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_33->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_2->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_22->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->mew->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_1->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_11->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, pok->sprite, NULL);
    sfRenderWindow_display(fct->window);
}

void move_skelenox(all_t *all, fct_t *fct)
{
    all->skel->stop = 1;
    display_pokemon(fct, all, all->toxic);
    time_passed(0.4);
    sfMusic_play(all->rire);
    display_pokemon(fct, all, all->skel);
    time_passed(1.5);
    all->skel->dim.left += 2000;
    sfSprite_setTextureRect(all->skel->sprite, all->skel->dim);
    for (int i = 0; i < 6; i++) {
        if (all->skel->pos.y == 320)
            all->skel->pos.y += 10;
        else
            all->skel->pos.y -= 10;
        sfSprite_setPosition(all->skel->sprite, all->skel->pos);
        display_pokemon(fct, all, all->skel);
        time_passed(0.08);
    }
    all->skel->dim.left -= 2000;
    sfSprite_setTextureRect(all->skel->sprite, all->skel->dim);
}
