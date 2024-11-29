/*
** EPITECH PROJECT, 2024
** bsInitiation-CSFML
** File description:
** render_window.c
*/

#include "../include/my_hunter.h"

static void handle_event(sfRenderWindow *window, sprite_t *sprite_t,
    sfEvent event, sfSprite *sprite)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

void render_window(window_t *window_t, sprite_t *sprite_t)
{
    sfRenderWindow *window;
    sfSprite *sprite = sprite_t->Menu;
    sfEvent event;

    window = sfRenderWindow_create(window_t->mode, window_t->title,
        window_t->style, window_t->settings);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window))
        handle_event(window, sprite_t, event, sprite);
    sfSprite_destroy(sprite);
    sfRenderWindow_destroy(window);
}
