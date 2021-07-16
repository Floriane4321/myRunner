/*
** EPITECH PROJECT, 2021
** pokemon_2.c
** File description:
** pokemon decor 2
*/

#include "include/graphic.h"

void initialize_pokemon_next(all_t *all, ini_t ini)
{
    ini.pos = initialize_pos(1000, -95, ini.pos);
    ini.dim = initialize_dim(0, 0, 3000, 3000);
    all->drag = create_object("image/dracaufeu-min.png", ini);
    all->drag->origin = initialize_pos(0.3, 0.3, all->drag->origin);
    sfSprite_setScale(all->drag->sprite, all->drag->origin);
    ini.pos = initialize_pos(880, 320, ini.pos);
    ini.dim = initialize_dim(0, 0, 2000, 2000);
    all->skel = create_object("image/skelenox.png", ini);
    all->skel->origin = initialize_pos(0.15, 0.15, all->skel->origin);
    sfSprite_setScale(all->skel->sprite, all->skel->origin);
    ini.pos = initialize_pos(600, 100, ini.pos);
    ini.dim = initialize_dim(0, 0, 3000, 3000);
    all->toxic = create_object("image/nuage_skelenox.png", ini);
    all->toxic->origin = initialize_pos(0.2, 0.2, all->toxic->origin);
    sfSprite_setScale(all->toxic->sprite, all->toxic->origin);
}

void move_pikachu_rotation(obj_t *pik_rot)
{
    if (pik_rot->pos.x > 1280) {
	pik_rot->pos.x = -60;
        pik_rot->stop = -150;
    } else
        pik_rot->pos.x += 10;
    if (pik_rot->i < 4)
        pik_rot->dim.left = 0 + (560 * pik_rot->i);
    else
        pik_rot->i = -1;
    pik_rot->i++;
    pik_rot->stop--;
    sfSprite_setTextureRect(pik_rot->sprite, pik_rot->dim);
    sfSprite_setPosition(pik_rot->sprite, pik_rot->pos);
}

void move_pikachu_run(obj_t *pik)
{
    if (pik->pos.x > 1280) {
        pik->pos.x = -70;
        pik->stop = -150;
    } else
        pik->pos.x += 10;
    if (pik->i < 4)
        pik->dim.left = 0 + (560 * pik->i);
    else
        pik->i = -1;
    pik->i++;
    pik->stop -= 1;
    sfSprite_setTextureRect(pik->sprite, pik->dim);
    sfSprite_setPosition(pik->sprite, pik->pos);
}

void main_move_mew(all_t *all)
{
    if (all->mew->pos.x < -100)
        all->mew->pos.y = rand() % 350;
    if (all->mew->stop == 200)
        move_mew(all->mew);
    all->mew->stop++;
}

void move_dracaufeu(obj_t *drag)
{
    drag->pos.x -= 20;
    sfSprite_setPosition(drag->sprite, drag->pos); 
}
