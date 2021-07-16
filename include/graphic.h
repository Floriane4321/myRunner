/*
** EPITECH PROJECT, 2020
** graphic.h
** File description:
** name fonction graphic
*/

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <SFML/Audio.h>

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Export.h>

#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>

typedef struct fb_s
{
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
}fb_t;

typedef struct fct_s
{
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    fb_t *fb;
    char *map;
    sfEvent event;
    int i;
    int stop;
}fct_t;

typedef struct ini_s
{
    sfVector2f pos;
    sfIntRect dim;
    int i;
}ini_t;

typedef struct obj_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfImage *image;
    sfVector2f pos;
    sfVector2f origin;
    sfIntRect dim;
    sfFloatRect hb;
    sfFloatRect sc;
    ini_t ini;
    int i;
    int stop;
    int m;
    int deg;
    int cmp;
}obj_t;

typedef struct txt_s
{
    sfText *text;
    sfFont *font;
    sfColor color;
    sfVector2f pos;
    int cmp;
    int map_f;
}txt_t;
typedef struct all_s
{
    obj_t *ps;
    obj_t *cat;
    obj_t *cat_end;
    obj_t *mew;
    obj_t *pik_rot;
    obj_t *pik;
    obj_t *pok_sc;
    obj_t *drag;
    obj_t *skel;
    obj_t *toxic;
    obj_t *cadre;
    obj_t *gradient;
    obj_t *bg_1;
    obj_t *bg_2;
    obj_t *bg_3;
    obj_t *bg_11;
    obj_t *bg_22;
    obj_t *bg_33;
    obj_t *obs_1;
    obj_t *obs_2;
    obj_t *obs_3;
    obj_t *obs_4;
    obj_t *end;
    obj_t *win;
    obj_t *menu;
    obj_t *start;
    obj_t *enter;
    txt_t *txt;
    sfMusic *music;
    sfMusic *explosion;
    sfMusic *pneu;
    sfMusic *rire;
    sfMusic *rug;
    sfMusic *course;
}all_t;

int my_strlen(char *str);
char *modif_str(char *str, int pos);
char *my_getstr(int nb);
char *my_revstr(char *str);
void my_putstr(char *str);

fb_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(fb_t *framebuffer);
void my_put_pixel(fb_t *fb, unsigned int x, unsigned int y, sfColor color);
void create_window(char *av);
all_t *move_game(all_t *all);

all_t *analyse_events(sfRenderWindow *window, sfEvent event, all_t *all);
void condition_close(fct_t *fct, sfEvent event);
void manage_mouse_click(sfMouseButtonEvent event, all_t *all);
all_t *key_pressed(sfKeyEvent event, all_t *all, sfRenderWindow *window);
all_t *playing_game(all_t *all, fct_t *fct, sfEvent event);

all_t *initialize_create(fct_t *fct, all_t *all);
sfVector2f initialize_pos(float x, float y, sfVector2f pos);
sfIntRect initialize_dim(int x, int y, int width, int height);
sfFloatRect change_dim(float x, float y, float width, float height);
sfIntRect convert_floatrect(sfFloatRect rect);

void time_passed(float n);

fct_t *create_map(char const *filepath, fct_t *fct);
int read_map(fct_t *fct);
all_t *fct_main_map(all_t *all, fct_t *fct);
all_t *handling_obstacle_map(all_t *all);
char *load_file_in_mem(char const *filepath);

obj_t *create_object(char *filepath, ini_t ini);
void destroy_object(obj_t *obj);
void destroy_all_object(all_t *all, fct_t *fct);
void destroy_fct(fct_t *fct);
void display_sprite(fct_t *fct, all_t *all);

all_t *create_background(ini_t ini, fct_t *fct, all_t *all);
void move_bg_1(all_t **all_tmp);
void move_bg_2(all_t **all_tmp);
void move_bg_3(all_t **all_tmp);

fct_t *create_start(fct_t *fct, char *filepath, ini_t ini);
all_t *initialize_menu(all_t *all);
all_t *main_menu(all_t *all, fct_t *fct);

all_t *create_character(ini_t ini, all_t *all);
obj_t *move_character(obj_t *ps);
obj_t *move_cat(obj_t *cat);
all_t *create_cat(ini_t ini, all_t *all);
obj_t *initialize_move(obj_t *cat);
obj_t *jump_cat(obj_t *cat);
obj_t *jump_cat_2(obj_t *cat);
obj_t *jump_cat_3(obj_t *cat);
obj_t *move_cat_2(obj_t *cat);
void move_cat_end(obj_t *cat);

obj_t *create_obstacle(ini_t ini, obj_t *obs);
obj_t *move_obstacle(obj_t *obs);

void initialize_score(all_t *all);
void count_score(txt_t *txt, obj_t *gradient);

all_t *initialize_pokemon(all_t *all);
void move_mew(obj_t *mew);
void move_pokemon_score(obj_t *pok);
void move_mew_menu(obj_t *mew);
void initialize_pokemon_next(all_t *all, ini_t ini);
void move_pikachu_rotation(obj_t *pik_rot);
void move_pikachu_run(obj_t *pik);
void main_move_mew(all_t *all);
void move_dracaufeu(obj_t *drag);
void move_skelenox(all_t *all, fct_t *fct);
void display_pokemon(fct_t *fct, all_t *all, obj_t *pok);

all_t *hitbox_main(all_t *all);

all_t *create_image_end(all_t *all);
void image_lost(char *filepath, all_t *all, fct_t *fct, sfEvent event);
void player_win(all_t *all, fct_t *fct, sfEvent event);
void display_lose(fct_t *fct, all_t *all);
void create_press_enter(all_t *all);
void display_score_end(all_t *all, fct_t *fct, sfEvent event);

txt_t *initialize_text(txt_t *txt, char *map);
txt_t *change_text(txt_t *txt);
void modif_text_score(txt_t *txt);

all_t *create_music(all_t *all);

#endif
