/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-mathys1.dupont
** File description:
** create_mamastruct.c
*/

#include "../include/my_hunter.h"
#include "../include/my.h"

keep_t *keep_struct(sprite_t *sprite,
    clickable_t *rec, bool_t *bool_s, duck_t *duck)
{
    keep_t *temp = (keep_t *)malloc(sizeof(keep_t));

    temp->sprite = sprite;
    temp->rec = rec;
    temp->bool_ = bool_s;
    temp->duck = duck;
    return temp;
}

keep_t *init_game_params(sprite_t *sprite_t)
{
    return keep_struct(sprite_t,
        create_all_rectangle(sprite_t),
        keep_bool(),
        create_duck(sprite_t));
}
