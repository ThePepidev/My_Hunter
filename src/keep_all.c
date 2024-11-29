/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-mathys1.dupont
** File description:
** create_mamastruct.c
*/

#include "../include/my_hunter.h"
#include "../include/my.h"

keep_t *keep_struct(sprite_t *sprite, clickable_t *rec, bool_t *bool_s)
{
    keep_t *temp = (keep_t *)malloc(sizeof(keep_t));

    temp->s = sprite;
    temp->r = rec;
    temp->b = bool_s;
    return temp;
}
