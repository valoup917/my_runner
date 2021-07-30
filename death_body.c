/*
** EPITECH PROJECT, 2021
** death body
** File description:
** .
*/

#include "include/runner.h"

int death_all(struct game_object *personnage)
{
    if (O1_body(personnage) == 1)
        return 1;
    if (O2_body(personnage) == 1)
        return 1;
    if (O3_body(personnage) == 1)
        return 1;
    if (O1_head(personnage) == 1)
        return 1;
    if (O2_head(personnage) == 1)
        return 1;
    if (O3_head(personnage) == 1)
        return 1;
    return 0;
}

int O1_body(struct game_object *personnage)
{
    float pos_object_x = personnage->my_pos.x + 22;
    float pos_object_y = personnage->my_pos.y + 85;

    personnage = personnage->next;

    float pos_object1_x = personnage->my_pos.x + 60;
    float pos_object2_x = personnage->my_pos.x;


    if ((pos_object_x > pos_object2_x && pos_object_x < pos_object1_x) && (pos_object_y > 410))
        return 1;
    
    return 0;
}

int O2_body(struct game_object *personnage)
{
    float pos_object_x = personnage->my_pos.x + 22;
    float pos_object_y = personnage->my_pos.y + 85;
   
    personnage = personnage->next;
    personnage = personnage->next;

    float pos_object1_x = personnage->my_pos.x + 60;
    float pos_object2_x = personnage->my_pos.x;

    if ((pos_object_x > pos_object2_x && pos_object_x < pos_object1_x) && (pos_object_y > 410))
        return 1;

    return 0;
}

int O3_body(struct game_object *personnage)
{
    float pos_object_x = personnage->my_pos.x + 22;
    float pos_object_y = personnage->my_pos.y + 85;
    
    personnage = personnage->next;
    personnage = personnage->next;
    personnage = personnage->next;

    float pos_object1_x = personnage->my_pos.x + 60;
    float pos_object2_x = personnage->my_pos.x;

    if ((pos_object_x > pos_object2_x && pos_object_x < pos_object1_x) && (pos_object_y > 410))
        return 1;
   
    return 0;
}