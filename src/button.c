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

int mouse_on_play(sfRenderWindow *window, clickable_t *rec)
{
    sfFloatRect play_size = sfRectangleShape_getGlobalBounds(rec->Play);
    sfVector2f mousePos = getmousepos(window);

    if (sfFloatRect_contains(&play_size, mousePos.x, mousePos.y))
        return 1;
    return 0;
}

static void create_esc_rectangle(clickable_t *rectangle, sprite_t *sprite)
{
    sfFloatRect sprite_size = sfSprite_getGlobalBounds(sprite->Esc);
    sfVector2f rectangle_size = {(float)sprite_size.width,
        (float)sprite_size.height};
    sfRectangleShape* esc_rectangle = sfRectangleShape_create();

    sfRectangleShape_setSize(esc_rectangle, rectangle_size);
    sfRectangleShape_setPosition(esc_rectangle, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(esc_rectangle, sfColor_fromRGBA(0, 0, 0, 0));
    rectangle->Escape = esc_rectangle;
}

static void create_play_rectangle(clickable_t *rectangle, sprite_t *sprite)
{
    sfFloatRect sprite_size = sfSprite_getGlobalBounds(sprite->play);
    sfVector2f rectangle_size = {(float)sprite_size.width - 50,
        (float)sprite_size.height - 50};
    sfRectangleShape* play_rectangle = sfRectangleShape_create();
    sfVector2f sprite_pos = sfSprite_getPosition(sprite->play);

    sfRectangleShape_setSize(play_rectangle, rectangle_size);
    sfRectangleShape_setPosition(play_rectangle, sprite_pos);
    sfRectangleShape_setFillColor(play_rectangle,
        sfColor_fromRGBA(0, 0, 0, 0));
    rectangle->Play = play_rectangle;
}

clickable_t *create_all_rectangle(sprite_t *sprite)
{
    clickable_t *rectangle = malloc(sizeof(rectangle));

    create_esc_rectangle(rectangle, sprite);
    create_play_rectangle(rectangle, sprite);
    return rectangle;
}

sfVector2f getmousepos(sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f temp_vector = {(float)mouse_pos.x - 25,
        (float)mouse_pos.y - 25};

    return temp_vector;
}
