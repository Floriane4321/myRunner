/*
** EPITECH PROJECT, 2021
** animation_end.c
** File description:
** animation of the end
*/

#include "include/graphic.h"

void display_animation_end(fct_t *fct, all_t *all)
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
    sfRenderWindow_drawSprite(fct->window, all->obs_1->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->obs_2->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->obs_3->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->drag->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->cat->sprite, NULL);
    sfRenderWindow_display(fct->window);
}

void display_animation_scare(fct_t *fct, all_t *all)
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
    sfRenderWindow_drawSprite(fct->window, all->obs_1->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->obs_2->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->obs_3->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->drag->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->cat_end->sprite, NULL);
    sfRenderWindow_display(fct->window);
}

void player_win_cat_move_1(all_t *all, fct_t *fct)
{
    sfMusic_play(all->pneu);
    for (int j = 0; j < 24; j++) {
	all = move_game(all);
        move_dracaufeu(all->drag);
        display_animation_end(fct, all);
        time_passed(0.08);
    }
    for (int k = 1; k < 3; k++) {
        display_animation_scare(fct, all);
        main_move_mew(all);
        all->cat_end->dim.left = 0 + (560 * k);
        if (k == 2) {
            sfMusic_play(all->rug);
            time_passed(0.05);
            all->drag->dim.left += 3000;
            sfSprite_setTextureRect(all->drag->sprite, all->drag->dim);
        }
        sfSprite_setTextureRect(all->cat_end->sprite, all->cat_end->dim);
        time_passed(1);
    }
}

void player_win(all_t *all, fct_t *fct, sfEvent event)
{
    sfMusic_stop(all->music);
    player_win_cat_move_1(all, fct);
    display_animation_scare(fct, all);
    time_passed(1);
    sfImage_flipHorizontally(all->cat->image);
    sfTexture_updateFromImage(all->cat->texture, all->cat->image, 0, 0);
    sfSprite_setTextureRect(all->cat->sprite, all->cat->dim);
    sfMusic_play(all->course);
    for (int i = 0; i < 30; i++) {
        move_cat(all->cat);
        move_cat_end(all->cat);
        display_animation_end(fct, all);
        time_passed(0.06);
    }
    move_skelenox(all, fct);
    display_score_end(all, fct, event);
}
