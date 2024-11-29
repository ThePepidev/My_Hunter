/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-mathys1.dupont
** File description:
** create_bool.c
*/

#include "../include/my_hunter.h"
#include "../include/my.h"

bool_t *keep_bool(void)
{
    bool_t *temp = malloc(sizeof(bool_t));
    bool colored = false;
    bool Menu = true;
    bool Duck = false;

    temp->colored_play = colored;
    temp->Menu = Menu;
    for (int i = 0; i < 10; i++)
        temp->Kill_duck[i] = false;
    return temp;
}

duck_t *create_duck(sprite_t *sprite)
{
    duck_t *duck = malloc(sizeof(duck_t));

    duck->duck_nb = 0;
    duck->life_point = 3;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        duck->duck_sprite[i] = sfSprite_copy(sprite->duck);
        duck->duckX[i] = 0.0f;
        duck->duckY[i] = rand() % 1010;
    }
    return duck;
}
