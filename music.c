/*
** EPITECH PROJECT, 2021
** music.c
** File description:
** fonction about music
*/

#include "include/graphic.h"

all_t *create_music(all_t *all)
{
    all->music = sfMusic_createFromFile("music/generique_pokemon.ogg");
    all->explosion = sfMusic_createFromFile("music/explosion.wav");
    all->pneu = sfMusic_createFromFile("music/pneus.wav");
    all->rire = sfMusic_createFromFile("music/rire_demon.wav");
    all->rug = sfMusic_createFromFile("music/rugissement.wav");
    all->course = sfMusic_createFromFile("music/course_rapide.wav");
    return (all);
}
