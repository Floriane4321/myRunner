/*
** EPITECH PROJECT, 2021
** text.c
** File description:
** fonction about text
*/

#include "include/graphic.h"

txt_t *initialize_text(txt_t *txt, char *map)
{
    txt = malloc(sizeof(struct txt_s));
    txt->cmp = 0;
    txt->map_f = my_strlen(map);
    txt->text = sfText_create();
    txt->font = sfFont_createFromFile("include/arial-black.ttf");
    sfText_setFont(txt->text, txt->font);
    txt->pos = initialize_pos(1150, 25, txt->pos);
    sfText_setPosition(txt->text, txt->pos);
    sfText_setString(txt->text, "10 000");
    sfText_setCharacterSize(txt->text, 30);
    sfText_setFillColor(txt->text, sfRed);
    return (txt);
}

txt_t *change_text(txt_t *txt)
{
    txt->cmp++;
    sfText_setString(txt->text, my_getstr(txt->cmp));
    return (txt);
}

void modif_text_score(txt_t *txt)
{
    txt->pos = initialize_pos(600, 100, txt->pos);
    sfText_setPosition(txt->text, txt->pos);
    sfText_setCharacterSize(txt->text, 70);
}
