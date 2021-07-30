/*
** EPITECH PROJECT, 2020
** part 2
** File description:
** .
*/

#include "include/runner.h"

int start(struct game_object *personnage, struct game_object *background, char *song)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1200, 600, 32};
    sfEvent event;
    sfClock *jump_clock = sfClock_create();

    sfMusic *music = sfMusic_createFromFile(song);
    sfMusic_play(music);


    struct Score *score = malloc(sizeof(char)* 3000);
    score->clock = sfClock_create();
    
    window = sfRenderWindow_create(video_mode, "Dino Run", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window)) {
        
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfWhite);
        
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed || ((event.type == sfEvtKeyPressed) && ((event.key.code == 59) || (event.key.code == 36))))
                sfRenderWindow_close(window);
            if (personnage->jump != 1 && (event.type == sfEvtKeyPressed) && ((event.key.code == 57) || (event.key.code == 73))) {
                personnage->jump = 1;
                sfClock_restart(jump_clock);
            }
        }
        print_score(score);
        jump(personnage, jump_clock);
        obstacles(personnage);
        print_my_background(background, window);
        print_my_sprite(personnage, window);
        
        if (death_all(personnage) == 1) {
            sfRenderWindow_destroy(window);
            sfMusic_destroy(music);
            exit(0);
        }
        sfRenderWindow_drawText(window, score->text, NULL);
        }
    return 0;
}

void print_my_background(struct game_object *background, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, background->my_sprite, NULL);
    background = background->next;
    
    move_back(background, 1, 600,0.000001);
    sfSprite_setTextureRect(background->my_sprite, background->my_rect);
    sfRenderWindow_drawSprite(window, background->my_sprite, NULL);
    background = background->next;
    
    move_back(background, 2, 600,0.000001);
    sfSprite_setTextureRect(background->my_sprite, background->my_rect);
    sfRenderWindow_drawSprite(window, background->my_sprite, NULL);
    background = background->next;

    move_back(background, 5, 600,0.000001);
    sfSprite_setTextureRect(background->my_sprite, background->my_rect);
    sfRenderWindow_drawSprite(window, background->my_sprite, NULL);
    background = background->next;
    
    move_back(background, 5, 600,0.000001);
    sfSprite_setTextureRect(background->my_sprite, background->my_rect);
    sfRenderWindow_drawSprite(window, background->my_sprite, NULL);
}

void move_back(struct game_object *background, int offset, int max_value, float count)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(background->clock);
    seconds = time.microseconds / 1000000000.0;

    if (seconds > count)
    {
        background->my_rect.left = background->my_rect.left + offset;
        if (background->my_rect.left >= max_value) {
            background->my_rect.left = 0;
        }
        sfClock_restart(background->clock);
    } 
}