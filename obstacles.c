/*
** EPITECH PROJECT, 2021
** obstacles
** File description:
** .
*/

#include "include/runner.h"

void obstacles(struct game_object *personnage)
{
    personnage = personnage->next;
    move_obstacles(personnage, 5, 0.01);
    personnage = personnage->next;
    move_obstacles(personnage, 5, 0.01);
    personnage = personnage->next;
    move_obstacles(personnage, 5, 0.01);
}

void move_obstacles(struct game_object *personnage, int offset, float count)
{   
    sfTime time =  sfClock_getElapsedTime(personnage->clock);
    float seconds = time.microseconds / 100000.0;

    personnage->my_pos.x -= offset;
    sfSprite_setPosition(personnage->my_sprite, personnage->my_pos);
    if (seconds > count)
    {
        if (personnage->my_pos.x == -100)
        {
            personnage->my_pos.x = 1300;
            move_rect(personnage, 70, 240, 0);
            sfSprite_setTextureRect(personnage->my_sprite, personnage->my_rect);

            sfSprite_setPosition(personnage->my_sprite, personnage->my_pos);
        }
        sfClock_restart(personnage->clock);
    } 
}