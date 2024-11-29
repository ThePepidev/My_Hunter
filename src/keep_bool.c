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

    temp->colored_play = colored;
    temp->Menu = Menu;
    return temp;
}
