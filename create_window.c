/*
** EPITECH PROJECT, 2020
** create_window.c
** File description:
** create a window
*/

#include "include/graphic.h"

fct_t *initialize_window(fct_t *fct, sfVideoMode mode)
{
    fct->window = sfRenderWindow_create(mode, "SFML window", sfResize \
    | sfClose, NULL);
    if (!fct->window)
        return (fct);
    fct->texture = sfTexture_create(800, 600);
    if (!fct->texture)
        return (fct);
    fct->sprite = sfSprite_create();
    sfSprite_setTexture(fct->sprite, fct->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(fct->window, 30);
    return (fct);
}

void condition_close(fct_t *fct, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        fct->stop = 1;
        sfRenderWindow_close(fct->window);
    } else if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape) {
            fct->stop = 1;
            sfRenderWindow_close(fct->window);
        }
        if (event.key.code == sfKeyReturn)
            fct->stop = 2;
    }
}

all_t *main_prgm(fct_t *fct, all_t *all)
{
    sfEvent event;
    ini_t ini;

    ini.i = 1;
    sfMusic_play(all->music);
    while (fct->stop != 2 && sfRenderWindow_isOpen(fct->window)) {
        analyse_events(fct->window, event, all);
        sfRenderWindow_clear(fct->window, sfBlack);
        sfRenderWindow_drawSprite(fct->window, fct->sprite, NULL);
        all->txt = change_text(all->txt);
        if (all->cat->stop != 1)
            display_sprite(fct, all);
        sfRenderWindow_display(fct->window);
        all = playing_game(all, fct, event);
        time_passed(0.08);
    }
    return (all);
}

void free_window(fct_t *fct, all_t *all)
{
    sfSprite_destroy(fct->sprite);
    sfTexture_destroy(fct->texture);
    sfRenderWindow_destroy(fct->window);
    free(fct->map);
    free(fct);
    free(all);
}

void create_window(char *av)
{
    fct_t *fct = malloc(sizeof(struct fct_s));
    all_t *all = malloc(sizeof(struct all_s));
    sfVideoMode mode = {1280, 761, 32};

    fct = create_map(av, fct);
    fct = initialize_window(fct, mode);
    while (sfRenderWindow_isOpen(fct->window)) {
        fct = create_map(av, fct);
        fct->stop = 1;
        all->txt = initialize_text(all->txt, fct->map);
        all = initialize_menu(all);
        all = initialize_pokemon(all);
        all = initialize_create(fct, all);
        initialize_score(all);
        all = create_music(all);
        all = main_menu(all, fct);
        all = main_prgm(fct, all);
        destroy_all_object(all, fct);
    }
    free_window(fct, all);
}
