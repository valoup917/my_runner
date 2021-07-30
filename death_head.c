/*
** EPITECH PROJECT, 2021
** death head
** File description:
** .
*/

#include "include/runner.h"

int O1_head(struct game_object *personnage)
{
    float pos_object_x = personnage->my_pos.x + 80;
    float pos_object_y = personnage->my_pos.y;
    
    personnage = personnage->next;

    if (pos_object_x == (personnage->my_pos.x + 5) && pos_object_y == 425)
        return 1;
    return 0;
}

int O2_head(struct game_object *personnage)
{
    float pos_object_x = personnage->my_pos.x + 80;
    float pos_object_y = personnage->my_pos.y;
    
    personnage = personnage->next;
    personnage = personnage->next;

    if (pos_object_x == (personnage->my_pos.x + 5) && pos_object_y == 425)
        return 1;
    return 0;
}

int O3_head(struct game_object *personnage)
{
    float pos_object_x = personnage->my_pos.x + 80;
    float pos_object_y = personnage->my_pos.y;
    
    personnage = personnage->next;
    personnage = personnage->next;
    personnage = personnage->next;
   
    if (pos_object_x == (personnage->my_pos.x + 5) && pos_object_y == 425)
        return 1;
    
    return 0;
}