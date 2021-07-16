/*
** EPITECH PROJECT, 2020
** fct_main.c
** File description:
** fonctions main
*/

#include "include/graphic.h"

void display_lose(fct_t *fct, all_t *all)
{
    sfRenderWindow_clear(fct->window, sfBlack);
    sfRenderWindow_drawSprite(fct->window, fct->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_3->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_33->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_2->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_22->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_1->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_11->sprite, NULL);
    if (all->skel->stop == 1)
        sfRenderWindow_drawSprite(fct->window, all->skel->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->enter->sprite, NULL);
    sfRenderWindow_drawText(fct->window, all->txt->text, NULL);
    sfRenderWindow_display(fct->window);
}

void display_sprite(fct_t *fct, all_t *all)
{
    sfRenderWindow_drawSprite(fct->window, all->bg_3->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_33->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_2->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_22->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->mew->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_1->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_11->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->obs_1->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->obs_2->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->obs_3->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->gradient->sprite, NULL);
    sfRenderWindow_drawText(fct->window, all->txt->text, NULL);
    sfRenderWindow_drawSprite(fct->window, all->cadre->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->pok_sc->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->cat->sprite, NULL);
}

sfIntRect convert_floatrect(sfFloatRect rect)
{
    sfIntRect dim;

    dim.left = (int) rect.left;
    dim.top = (int) rect.top;
    dim.width = (int) rect.width;
    dim.height = (int) rect.height;
    return (dim);
}

all_t *move_game(all_t *all)
{
    move_bg_1(&all);
    move_bg_2(&all);
    move_bg_3(&all);
    main_move_mew(all);
    move_pokemon_score(all->pok_sc);
    all->cat = initialize_move(all->cat);
    all->ps = move_character(all->ps);
    if (all->obs_1->stop == 1)
        all->obs_1 = move_obstacle(all->obs_1);
    if (all->obs_2->stop == 1)
        all->obs_2 = move_obstacle(all->obs_2);
    if (all->obs_3->stop == 1)
        all->obs_3 = move_obstacle(all->obs_3);
    if (all->obs_4->stop == 1)
	all->obs_4 = move_obstacle(all->obs_4);
    all = hitbox_main(all);
    return (all);
}

all_t *playing_game(all_t *all, fct_t *fct, sfEvent event)
{
    if (fct->map[0] == 0)
        all->cat->stop = 100;
    if (all->cat->stop != 100)
        all = move_game(all);
    if (all->cat->stop == 1) {
        image_lost("image/blood_2.png", all, fct, event);
        return (all);
    }
    if (fct->map[0] == 0) {
        player_win(all, fct, event);
        return (all);
    }
    if (all->cat->stop != 100)
        all = fct_main_map(all, fct);
    return (all);
}
