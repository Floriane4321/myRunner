/*
** EPITECH PROJECT, 2021
** pokemon_1.c
** File description:
** pokemon decor
*/

#include "include/graphic.h"

all_t *initialize_pokemon(all_t *all)
{
    ini_t ini;

    srand(time(NULL));
    ini.pos = initialize_pos(1280, 70, ini.pos);
    ini.dim = initialize_dim(0, 0, 100, 100);
    all->mew = create_object("image/mew_sprite.png", ini);
    all->mew->pos.y = rand() % 350;
    ini.pos = initialize_pos(0, 15, ini.pos);
    ini.dim = initialize_dim(0, 0, 70, 60);
    all->pok_sc = create_object("image/pokemon_sc.png", ini);
    ini.pos = initialize_pos(-60, 580, ini.pos);
    ini.dim = initialize_dim(0, 0, 60, 40);
    all->pik_rot = create_object("image/pikachu_rotation.png", ini);
    ini.pos = initialize_pos(-70, 580, ini.pos);
    all->pik = create_object("image/pikachu_2.png", ini);
    initialize_pokemon_next(all, ini);
    return (all);
}

void change_skin_mew(obj_t *mew)
{
    if (mew->cmp == 122) {
        mew->cmp = 0;
        mew->i = 0;
    }
    if (mew->i == 0 && mew->cmp < 110) {
        mew->dim.left = 0;
    } else if (mew->cmp < 110) {
        mew->dim.left += 532;
        mew->i = -1;
    }
    if (mew->cmp == 110)
        mew->i = 2;
    if (mew->i < 15 && mew->cmp > 110) {
        mew->dim.left = 0 + (532 * mew->i);
        time_passed(0.1);
    }
    mew->i++;
    mew->cmp++;
}

void move_mew_menu(obj_t *mew)
{
    if (mew->pos.x < -100) {
        mew->pos.x = 1280;
        mew->stop = 0;
    } else if (mew->pos.x >= -100 && mew->cmp < 110) {
	mew->pos.x -= 10;
    }
    change_skin_mew(mew);
    mew->stop--;
    sfSprite_setTextureRect(mew->sprite, mew->dim);
    sfSprite_setPosition(mew->sprite, mew->pos);
}

void move_mew(obj_t *mew)
{
    if (mew->pos.x < -100) {
        mew->pos.x = 1280;
        mew->stop = 0;
    } else {
        mew->pos.x -= 10;
    }
    if (mew->i == 0) {
        mew->dim.left = 0;
        mew->i++;
    } else {
        mew->dim.left += 532;
        mew->i--;
    }
    mew->stop--;
    sfSprite_setTextureRect(mew->sprite, mew->dim);
    sfSprite_setPosition(mew->sprite, mew->pos);
}

void move_pokemon_score(obj_t *pok)
{
    if (pok->i < 4)
        pok->dim.left = 0 + (370 * pok->i);
    else
        pok->i = -1;
    pok->i++;
    sfSprite_setTextureRect(pok->sprite, pok->dim);
}
