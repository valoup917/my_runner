/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** .
*/

#include "../include/runner.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
