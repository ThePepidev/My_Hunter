/*
** EPITECH PROJECT, 2024
** bsInitiation-CSFML
** File description:
** render_window.c
*/

#include "../include/my_hunter.h"

static void destroy_and_free(sfRenderWindow *window,
    sprite_t *sprite_t, keep_t *s, anim_t *esc)
{
    sfSprite_destroy(sprite_t->Esc);
    sfSprite_destroy(sprite_t->Menu);
    sfSprite_destroy(sprite_t->crosshair);
    sfSprite_destroy(sprite_t->Title);
    sfSprite_destroy(sprite_t->play);
    sfSprite_destroy(sprite_t->play_colored);
    sfSprite_destroy(sprite_t->Game);
    sfSprite_destroy(sprite_t->duck);
    sfRectangleShape_destroy(s->r->Escape);
    sfRectangleShape_destroy(s->r->Play);
    sfRenderWindow_destroy(window);
    free(s->r);
    free(s->b);
    free(esc);
    free(s);
}

static void display_window(sfRenderWindow *window, keep_t *s)
{
    sfRenderWindow_clear(window, sfBlack);
    if (s->b->Menu) {
        sfRenderWindow_drawSprite(window, s->s->Menu, NULL);
        sfRenderWindow_drawSprite(window, s->s->Title, NULL);
        sfRenderWindow_drawSprite(window, s->s->play, NULL);
        if (s->b->colored_play)
            sfRenderWindow_drawSprite(window, s->s->play_colored, NULL);
        sfRenderWindow_drawRectangleShape(window, s->r->Play, NULL);
    } else {
        sfRenderWindow_drawSprite(window, s->s->Game, NULL);
    }
    sfRenderWindow_drawSprite(window, s->s->Esc, NULL);
    sfRenderWindow_drawRectangleShape(window, s->r->Escape, NULL);
    sfRenderWindow_drawSprite(window, s->s->crosshair, NULL);
    sfRenderWindow_display(window);
}

static void menu_loop(keep_t *s, sfRenderWindow *window)
{
    if (s->b->Menu)
        sfRenderWindow_close(window);
    else
        s->b->Menu = true;
}

static void handle_event(sfRenderWindow *window, sfEvent event, keep_t *s)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (click_esc(window, s->r, &event) == 1)
            sfRenderWindow_close(window);
        if (click_play(window, s->r, &event) == 1)
            s->b->Menu = false;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            menu_loop(s, window);
        }
    }
    if (mouse_on_play(window, s->r) == 1)
        s->b->colored_play = true;
    else
        s->b->colored_play = false;
    display_window(window, s);
}

void render_window(window_t *window_t, sprite_t *sprite_t)
{
    sfRenderWindow *window;
    sfVector2f cursorPos;
    anim_t *esc_animation = create_animation(30.0f, 1, sfClock_create());
    keep_t *s = keep_struct(sprite_t,
        create_all_rectangle(sprite_t), keep_bool());
    sfEvent event;

    window = sfRenderWindow_create(window_t->mode, window_t->title,
        window_t->style, window_t->settings);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfWindow_setMouseCursorVisible((sfWindow*)window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        handle_event(window, event, s);
        set_esc_animation(esc_animation, sprite_t->Esc);
        cursorPos = getmousepos(window);
        sfSprite_setPosition(sprite_t->crosshair, cursorPos);
        sfSprite_setPosition(sprite_t->Esc, esc_animation->position);
    }
    destroy_and_free(window, sprite_t, s, esc_animation);
}
