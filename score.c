/*
** EPITECH PROJECT, 2021
** part 3
** File description:
** .
*/

#include "include/runner.h"

void print_score(struct Score *score)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(score->clock);
    seconds = time.microseconds / 1000000.0;
    create_print(score);
    manage_print(score,seconds);

    if (seconds > 10) {
        sfText_setString(score->text, "Score: pas fort");
        sfVector2f position = {950,0};
        sfText_setPosition(score->text, position);
    }
    if (seconds > 30) {
        sfText_setString(score->text, "Score: bof");
        sfVector2f position = {1030,0};
        sfText_setPosition(score->text, position);
    }
} 

void create_print(struct Score *score)
{
    sfVector2f position = {830,0};
    score->my_pos = position;
    score->text = sfText_create();
    score->font = sfFont_createFromFile("Fonts/3D.ttf");
    sfText_setString(score->text, "Score: pas fort du tout");
    sfText_setFont(score->text, score->font);
    sfText_setColor(score->text, sfBlack);
    sfText_setPosition(score->text, score->my_pos);
}

void manage_print(struct Score *score, float seconds)
{
    if (seconds > 50) {
        sfVector2f position = {980,0};
        sfText_setString(score->text, "Score: moyen"), sfText_setPosition(score->text, position);
    }
    if (seconds > 70) {
        sfVector2f position = {1020,0};
        sfText_setString(score->text, "Score: fort"), sfText_setPosition(score->text, position);
    }
    if (seconds > 100) {
        sfVector2f position = {940,0};
        sfText_setString(score->text, "Score: tres fort");
        sfText_setPosition(score->text, position);
    }
    if (seconds > 130) {
        sfVector2f position = {910,0};
        sfText_setString(score->text, "Score: t'es un pro");
        sfText_setPosition(score->text, position);
    }   
}