/*
** EPITECH PROJECT, 2020
** .h
** File description:
** .
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

typedef struct game_object
{
    char *description;
    int jump;
    sfClock *clock;
    sfVector2f my_pos;
    sfSprite *my_sprite;
    sfTexture *my_texture;
    sfIntRect my_rect;
    struct game_object *next;
}List;

typedef struct Text
{
    sfVector2f pos;
    sfText *text;
    sfFont *font;
}text;

typedef struct Score
{
    sfClock *clock;
    sfVector2f my_pos;
    sfText *text;
    sfFont *font;
}score;

int runner(char *argv[]);

void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

void game(struct game_object *personnage, struct game_object *background);
void analyse_events(sfRenderWindow *window, sfEvent event, struct game_object *personnage, struct game_object *background);
void manage_mouse_click(sfRenderWindow *window, sfEvent event, struct game_object *personnage, struct game_object *background);
struct Text *songs_text (struct Text *title);
struct Text *menu_text (struct Text *title);

int death_all(struct game_object *personnage);
int O1_body(struct game_object *personnage);
int O2_body(struct game_object *personnage);
int O3_body(struct game_object *personnage);

int O1_head(struct game_object *personnage);
int O2_head(struct game_object *personnage);
int O3_head(struct game_object *personnage);

void jump (struct game_object *personnage, sfClock *jump_clock);
void up (struct game_object *personnage);
void down (struct game_object *personnage);

void obstacles(struct game_object *personnage);
void move_obstacles(struct game_object *personnage, int offset, float count);

void print_my_sprite(struct game_object *personnage, sfRenderWindow *window);
void move_rect(struct game_object *personnage, int offset, int max_value, float count);

int start(struct game_object *personnage, struct game_object *background, char *song);
void print_my_background(struct game_object *background, sfRenderWindow *window);
void move_back(struct game_object *background, int offset, int max_value, float count);

void print_score(struct Score *score);
void create_print(struct Score *score);
void manage_print(struct Score *score, float seconds);

struct game_object *personnage_all(struct game_object *personnage);
struct game_object *background_all(struct game_object *background);
struct game_object *add_object(struct game_object *L, const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect);
struct game_object *create_object(const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect);