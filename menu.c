/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** menu
*/

//créer->texture->texture rec->position
//move->colision->display

#include "include/graphic.h"

fct_t *create_start(fct_t *fct, char *filepath, ini_t ini)
{
    fct_t *start = malloc(sizeof(struct fct_s));

    start->texture = sfTexture_createFromFile(filepath, NULL);
    if (!start->texture)
        return (start);
    start->sprite = sfSprite_create();
    sfSprite_setTexture(start->sprite, start->texture, sfTrue);
    sfSprite_setTextureRect(start->sprite, ini.dim);
    sfSprite_setPosition(start->sprite, ini.pos);
    return (start);
}

all_t *initialize_menu(all_t *all)
{
    ini_t ini;

    ini.pos = initialize_pos(520, 220, ini.pos);
    ini.dim = initialize_dim(0, 0, 246, 92);
    all->start = create_object("image/start_menu_3.png", ini);
    all->start->stop = 0;
    return (all);
}

void display_menu(all_t *all, fct_t *fct)
{
    sfRenderWindow_clear(fct->window, sfBlack);
    sfRenderWindow_drawSprite(fct->window, fct->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_3->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_2->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->bg_1->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->pik_rot->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->pik->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->mew->sprite, NULL);
    sfRenderWindow_drawSprite(fct->window, all->start->sprite, NULL);
    sfRenderWindow_display(fct->window);
}

all_t *main_menu(all_t *all, fct_t *fct)
{
    while (all->start->stop == 0 && sfRenderWindow_isOpen(fct->window)) {
        analyse_events(fct->window, fct->event, all);
        if (all->mew->pos.x < -100)
            all->mew->pos.y = rand() % 350;
        if (all->mew->stop == 100)
            move_mew_menu(all->mew);
        if (all->pik_rot->stop == 50)
            move_pikachu_rotation(all->pik_rot);
        if (all->pik->stop == 58)
            move_pikachu_run(all->pik);
        all->mew->stop++;
        all->pik_rot->stop += 1;
        all->pik->stop++;
        display_menu(all, fct);
        time_passed(0.08);
    }
    all->mew->pos.x = 1280;
    sfSprite_setPosition(all->mew->sprite, all->mew->pos);
    return (all);
}
