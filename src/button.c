/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-mathys1.dupont
** File description:
** getmousepos.c
*/

#include "../include/my_hunter.h"

int click_esc(sfRenderWindow *window, clickable_t *rec, sfEvent *event)
{
    sfFloatRect esc_size = sfRectangleShape_getGlobalBounds(rec->Escape);
    sfVector2f mousePos = getmousepos(window);

    if (sfFloatRect_contains(&esc_size, mousePos.x, mousePos.y)
        && event->mouseButton.button == sfMouseLeft)
        return 1;
    return 0;
}

clickable_t *create_esc_rectangle(sprite_t *sprite)
{
    clickable_t *rectangle = malloc(sizeof(rectangle));
    sfFloatRect sprite_size = sfSprite_getGlobalBounds(sprite->Esc);
    sfVector2f rectangle_size = {(float)sprite_size.width,
        (float)sprite_size.height};
    sfRectangleShape* esc_rectangle = sfRectangleShape_create();

    sfRectangleShape_setSize(esc_rectangle, rectangle_size);
    sfRectangleShape_setPosition(esc_rectangle, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(esc_rectangle, sfColor_fromRGBA(0, 0, 0, 0));
    rectangle->Escape = esc_rectangle;
    return rectangle;
}

sfVector2f getmousepos(sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f temp_vector = {(float)mouse_pos.x - 25,
        (float)mouse_pos.y - 25};

    return temp_vector;
}
