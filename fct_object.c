/*
** EPITECH PROJECT, 2020
** fct_object.c
** File description:
** fonctions about objects
*/

#include "include/graphic.h"

obj_t *create_object(char *filepath, ini_t ini)
{
    obj_t *obj = malloc(sizeof(struct obj_s));

    obj->image = sfImage_createFromFile(filepath);
    obj->texture = sfTexture_createFromImage(obj->image, NULL);
    if (!obj->texture)
        return (NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->pos = ini.pos;
    obj->dim = ini.dim;
    obj->i = 0;
    obj->stop = 0;
    obj->m = 0;
    obj->deg = 0;
    obj->cmp = 0;
    sfSprite_setTextureRect(obj->sprite, ini.dim);
    sfSprite_setPosition(obj->sprite, ini.pos);
    return (obj);
}
void destroy_all_object_next(all_t *all)
{
    destroy_object(all->bg_22);
    destroy_object(all->bg_33);
    destroy_object(all->obs_1);
    destroy_object(all->obs_2);
    destroy_object(all->obs_3);
    destroy_object(all->obs_4);
    destroy_object(all->cadre);
    destroy_object(all->gradient);
    destroy_object(all->start);
    destroy_object(all->enter);
    destroy_object(all->skel);
    destroy_object(all->toxic);
    sfMusic_destroy(all->music);
    sfMusic_destroy(all->explosion);
    sfMusic_destroy(all->pneu);
    sfMusic_destroy(all->rire);
    sfMusic_destroy(all->rug);
    sfMusic_destroy(all->course);
}

void destroy_all_object(all_t *all, fct_t *fct)
{
    if (fct->map[0] != 0)
        destroy_object(all->end);
    sfFont_destroy(all->txt->font);
    sfText_destroy(all->txt->text);
    free(all->txt);
    destroy_object(all->ps);
    destroy_object(all->pok_sc);
    destroy_object(all->cat);
    destroy_object(all->cat_end);
    destroy_object(all->mew);
    destroy_object(all->pik_rot);
    destroy_object(all->pik);
    destroy_object(all->drag);
    destroy_object(all->bg_1);
    destroy_object(all->bg_2);
    destroy_object(all->bg_3);
    destroy_object(all->bg_11);
    destroy_all_object_next(all);
}

void destroy_object(obj_t *obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
    sfImage_destroy(obj->image);
    free(obj);
}

void destroy_fct(fct_t *fct)
{
    sfSprite_destroy(fct->sprite);
    sfTexture_destroy(fct->texture);
}
