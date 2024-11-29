/*
** EPITECH PROJECT, 2024
** bsInitiation-CSFML
** File description:
** render_window.c
*/

#include "../include/my_hunter.h"

static void destroy_and_free(sfRenderWindow *window, sprite_t *sprite_t,
    anim_t *esc_animation, clickable_t *rectangle)
{
    sfSprite_destroy(sprite_t->Menu);
    sfSprite_destroy(sprite_t->Esc);
    sfSprite_destroy(sprite_t->crosshair);
    sfRenderWindow_destroy(window);
    free(rectangle);
    free(esc_animation);
}

static void display_window(sfRenderWindow *window,
    sprite_t *sprite_t, clickable_t *rec)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite_t->Menu, NULL);
    sfRenderWindow_drawSprite(window, sprite_t->Esc, NULL);
    sfRenderWindow_drawRectangleShape(window, rec->Escape, NULL);
    sfRenderWindow_drawSprite(window, sprite_t->crosshair, NULL);
    sfRenderWindow_display(window);
}

static void handle_event(sfRenderWindow *window, sprite_t *sprite_t,
    sfEvent event, clickable_t *rectangle)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
        if (click_esc(window, rectangle, &event) == 1)
            sfRenderWindow_close(window);
    }
    display_window(window, sprite_t, rectangle);
}

void render_window(window_t *window_t, sprite_t *sprite_t)
{
    sfRenderWindow *window;
    sfVector2f cursorPos;
    clickable_t *rectangle = create_esc_rectangle(sprite_t);
    anim_t *esc_animation = create_animation(30.0f, 1, sfClock_create());
    sfEvent event;

    window = sfRenderWindow_create(window_t->mode, window_t->title,
        window_t->style, window_t->settings);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfWindow_setMouseCursorVisible((sfWindow*)window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        handle_event(window, sprite_t, event, rectangle);
        set_esc_animation(esc_animation, sprite_t->Esc);
        cursorPos = getmousepos(window);
        sfSprite_setPosition(sprite_t->crosshair, cursorPos);
        sfSprite_setPosition(sprite_t->Esc, esc_animation->position);
    }
    destroy_and_free(window, sprite_t, esc_animation, rectangle);
}
