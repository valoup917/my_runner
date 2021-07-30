/*
** EPITECH PROJECT, 2021
** structure creation
** File description:
** .
*/

#include "include/runner.h"

struct game_object *personnage_all(struct game_object *personnage)
{
    sfVector2f t_rex_pos = {20,425};
    sfVector2f o1_pos = {1800,380};
    sfVector2f o2_pos = {2300,380};
    sfVector2f o3_pos = {1300,380};

    sfIntRect t_rex_rect = {0,0,80,86};
    sfIntRect o1_rect = {0,0,70,132};

    personnage = add_object(personnage, "pics/obsta.png", o1_pos, o1_rect);
    personnage = add_object(personnage, "pics/obsta2.png", o2_pos, o1_rect);
    personnage = add_object(personnage, "pics/obsta3.png", o3_pos, o1_rect);
    personnage = add_object(personnage, "pics/t-rex-green-slice.png", t_rex_pos, t_rex_rect);
    return (personnage);
}

struct game_object *background_all(struct game_object *background)
{
    sfVector2f pos = {0,0};
    sfVector2f p1_pos = {0,290};
    sfVector2f p2_pos = {0,330};
    sfVector2f p3_pos = {0,400};
    sfVector2f pground_pos = {0,490};

    sfIntRect back_rect = {0,0,1200,750};
    sfIntRect p1_back_rect = {0,0,1200,130};

    background = add_object(background, "pics/paralax_ground.png", pground_pos, p1_back_rect);
    background = add_object(background, "pics/paralax3.png", p3_pos, p1_back_rect);
    background = add_object(background, "pics/paralax2.png", p2_pos, p1_back_rect);
    background = add_object(background, "pics/paralax1.png", p1_pos, p1_back_rect);
    background = add_object(background, "pics/paralax0.jpg", pos, back_rect);
    return (background);
}

struct game_object *add_object(struct game_object *L, const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect)
{
    struct game_object *number = create_object(path_to_spritesheet, pos, rect);
    if (L == NULL) {
        return number;
    }
    number->next = L;
    return number;
}

struct game_object *create_object(const char *path_to_spritesheet, sfVector2f pos, sfIntRect rect)
{
    struct game_object *personnage = malloc(sizeof(char)* 3000);
    
    if (!personnage)
        return NULL;
    personnage->description = malloc(sizeof(char)*50);
    my_strcpy(personnage->description, path_to_spritesheet);
    personnage->my_sprite = sfSprite_create();
    personnage->my_pos = pos;
    personnage->my_rect = rect;
    personnage->jump = 0;
    personnage->my_texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    personnage->clock = sfClock_create();
    sfSprite_setTexture(personnage->my_sprite, personnage->my_texture, sfFalse);
    sfSprite_setTextureRect(personnage->my_sprite, rect);
    sfSprite_setPosition(personnage->my_sprite, pos);
    personnage->next = NULL;
    return personnage;
}