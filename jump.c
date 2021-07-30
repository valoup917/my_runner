/*
** EPITECH PROJECT, 2021
** jump
** File description:
** .
*/

#include "include/runner.h"

void jump (struct game_object *personnage, sfClock *jump_clock)
{
     if (personnage->jump == 1) {

        float seconds;
        sfTime time;
        time = sfClock_getElapsedTime(jump_clock);
        seconds = time.microseconds / 10000 ;

        if (seconds < 40)
            up(personnage);
        if (seconds > 40 && seconds < 80)
            down(personnage);
        
        if (seconds > 81)
            personnage->jump = 0;
    }
}

void up (struct game_object *personnage)
{
    if (personnage->my_pos.y > 250 && personnage->my_pos.y <= 425)
        personnage->my_pos.y -= 15;
    else if (personnage->my_pos.y > 200 && personnage->my_pos.y <= 250)
        personnage->my_pos.y -= 5;
    sfSprite_setPosition(personnage->my_sprite, personnage->my_pos);
}

void down (struct game_object *personnage)
{
    if (personnage->my_pos.y >= 200 && personnage->my_pos.y < 420)
        personnage->my_pos.y += 15;
    else if (personnage->my_pos.y = 420)
        personnage->my_pos.y += 5;
    sfSprite_setPosition(personnage->my_sprite, personnage->my_pos);
}