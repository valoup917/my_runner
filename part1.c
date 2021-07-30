/*
** EPITECH PROJECT, 2020
** part1
** File description:
** 1
*/

#include "include/runner.h"

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 2) {
        write (2, "./my_runner: bad arguments: 0 given but 1 is required\nretry with -h\n", 68);
        return 84;
    }
    if (runner(argv) == 84) 
        return 84;
    struct game_object *personnage = NULL;
    personnage = personnage_all(personnage);
    struct game_object *background = NULL;
    background = background_all(background);
    if (argv[1][0] == '-' && argv[1][1] == 'i')
        game(personnage, background);
    else 
        game(personnage, background);
    return 0;
}

int runner(char *argv[])
{
    if (argv[1][0] == '-' && argv[1][1] == 'i')
        return 0;
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        my_putstr("Finite runner created with CSFML.\n\n\nUSAGE\n./my_runner map.txt\n\nOPTIONS\n-i          launch the game in infinity mode.\n-h          print the usage and quit.\n\nUSER INTERACTIONS\nSPACE_KEY          jump.\n");
    return 0;
}

void print_my_sprite(struct game_object *personnage, sfRenderWindow *window)
{
    move_rect(personnage, 80, 160, 0.2);
    sfSprite_setTextureRect(personnage->my_sprite, personnage->my_rect);
    sfRenderWindow_drawSprite(window, personnage->my_sprite, NULL);

    personnage = personnage->next;
    sfRenderWindow_drawSprite(window, personnage->my_sprite, NULL);
    personnage = personnage->next;
    sfRenderWindow_drawSprite(window, personnage->my_sprite, NULL);
    personnage = personnage->next;
    sfRenderWindow_drawSprite(window, personnage->my_sprite, NULL);
}

void move_rect(struct game_object *personnage, int offset, int max_value, float count)
{   
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(personnage->clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > count)
    {
        personnage->my_rect.left = personnage->my_rect.left + offset;
            if (personnage->my_rect.left >= max_value) 
                personnage->my_rect.left = 0;
        sfClock_restart(personnage->clock);
    } 
}