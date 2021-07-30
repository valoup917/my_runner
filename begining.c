/*
** EPITECH PROJECT, 2021
** begining
** File description:
** .
*/

#include "include/runner.h"

void game(struct game_object *personnage, struct game_object *background)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1200, 600, 32};
    sfEvent event;

    struct Text *title = NULL;
    title = menu_text(title);
    struct Text *songs = NULL;
    songs = songs_text(songs);

    sfVector2f t_rex_pos = {20,420};
    sfIntRect t_rex_rect = {0,0,175,179};
    struct game_object *menu = NULL;
    menu = add_object(menu, "pics/presentation.png", t_rex_pos, t_rex_rect);

    
    window = sfRenderWindow_create(video_mode, "boostrap hunter", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 4);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, personnage, background);
        }
        move_rect(menu, 175, 350, 0.1);
        sfSprite_setTextureRect(menu->my_sprite, menu->my_rect);
        sfRenderWindow_drawSprite(window, menu->my_sprite, NULL);
        sfRenderWindow_drawText(window, title->text, NULL);
        sfRenderWindow_drawText(window, songs->text, NULL);
        }
}

void analyse_events(sfRenderWindow *window, sfEvent event, struct game_object *personnage, struct game_object *background)
{
    if (event.type == sfEvtClosed || ((event.type == sfEvtKeyPressed) && ((event.key.code == 59) || (event.key.code == 36))))
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(window, event, personnage, background);
}

void manage_mouse_click(sfRenderWindow *window, sfEvent event, struct game_object *personnage, struct game_object *background)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    if ((x > 740 && x < 800) && (y > 185 && y < 215)) {
        sfRenderWindow_destroy(window), start(personnage, background, "songs/bo2.wav");
    }
    if ((x > 715 && x < 820) && (y > 270 && y < 300)) {
        sfRenderWindow_destroy(window), start(personnage, background, "songs/rocky.wav");
    }
    if ((x > 600 && x < 875) && (y > 350 && y < 385)) {
        sfRenderWindow_destroy(window), start(personnage, background, "songs/megalovania.wav");
    }
    if ((x > 650 && x < 885) && (y > 430 && y < 460)) {
        sfRenderWindow_destroy(window), start(personnage, background, "songs/acdc.wav");
    }
    if ((x > 650 && x < 885) && (y > 515 && y < 545)) {
        sfRenderWindow_destroy(window), start(personnage, background, "songs/jurassic.wav");
    }
}

struct Text *songs_text (struct Text *title)
{
    title = malloc(sizeof(char)* 3000);
    if (!title)
        return NULL;
    sfVector2f position = {650, 180};
    title->pos = position;
    title->text = sfText_create();
    title->font = sfFont_createFromFile("Fonts/3D.ttf");
    sfText_setString(title->text, "           bo2\n\n        Rocky\n\n Megalovania\n\nThunderstuck\n\nJurassic Parc\n");
    sfText_setFont(title->text, title->font);
    sfText_setColor(title->text, sfRed);
    sfText_setPosition(title->text, title->pos);
    sfText_setCharacterSize(title->text, 30);
    return title;
}

struct Text *menu_text (struct Text *title)
{
    title = malloc(sizeof(char)* 3000);
    if (!title)
        return NULL;
    sfVector2f position = {350, 0};
    title->pos = position;
    title->text = sfText_create();
    title->font = sfFont_createFromFile("Fonts/3D.ttf");
    sfText_setString(title->text, "Dino run");
    sfText_setFont(title->text, title->font);
    sfText_setColor(title->text, sfGreen);
    sfText_setPosition(title->text, title->pos);
    sfText_setCharacterSize(title->text, 100);
    return title;
}