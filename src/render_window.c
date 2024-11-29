/*
** EPITECH PROJECT, 2024
** bsInitiation-CSFML
** File description:
** render_window.c
*/

#include "../include/my_hunter.h"

static void destroy_loop(keep_t *params, sprite_t *sprite)
{
    for (int i = 0; i < 8; i++)
        sfTexture_destroy(sprite->texture[i]);
    for (int i = 0; i < 10; i++)
        sfSprite_destroy(params->duck->duck_sprite[i]);
}

static void destroy_and_free(sfRenderWindow *window,
    sprite_t *sprite_t, keep_t *params, anim_t *esc)
{
    sfSprite_destroy(sprite_t->Esc);
    sfSprite_destroy(sprite_t->Menu);
    sfSprite_destroy(sprite_t->crosshair);
    sfSprite_destroy(sprite_t->Title);
    sfSprite_destroy(sprite_t->play);
    sfSprite_destroy(sprite_t->play_colored);
    sfSprite_destroy(sprite_t->Game);
    sfSprite_destroy(sprite_t->duck);
    sfRectangleShape_destroy(params->rec->Escape);
    sfRectangleShape_destroy(params->rec->Play);
    destroy_loop(params, sprite_t);
    sfRenderWindow_destroy(window);
    free(params->rec);
    free(params->bool_);
    free(params->duck);
    free(esc);
    free(params);
}

static void display_window(sfRenderWindow *window, keep_t *params)
{
    sfRenderWindow_clear(window, sfBlack);
    if (params->bool_->Menu) {
        sfRenderWindow_drawSprite(window, params->sprite->Menu, NULL);
        display_text(window, params);
        sfRenderWindow_drawSprite(window, params->sprite->play, NULL);
        if (params->bool_->colored_play)
            sfRenderWindow_drawSprite(window,
                params->sprite->play_colored, NULL);
        sfRenderWindow_drawRectangleShape(window, params->rec->Play, NULL);
    } else {
        sfRenderWindow_drawSprite(window, params->sprite->Game, NULL);
        draw_duck_sprite(window, params);
    }
    sfRenderWindow_drawSprite(window, params->sprite->Esc, NULL);
    sfRenderWindow_drawRectangleShape(window, params->rec->Escape, NULL);
    sfRenderWindow_drawSprite(window, params->sprite->crosshair, NULL);
    sfRenderWindow_display(window);
}

static void menu_loop(keep_t *params, sfRenderWindow *window)
{
    if (params->bool_->Menu)
        sfRenderWindow_close(window);
    else
        params->bool_->Menu = true;
}

static void handle_event(sfRenderWindow *window, keep_t *params)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (click_esc(window, params->rec, &event) == 1)
            sfRenderWindow_close(window);
        if (click_play(window, params->rec, &event) == 1) {
            params->bool_->Menu = false;
            params->bool_->Game_over = false;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            menu_loop(params, window);
        click_duck(window, params, &event);
    }
    if (mouse_on_play(window, params->rec) == 1)
        params->bool_->colored_play = true;
    else
        params->bool_->colored_play = false;
    display_window(window, params);
}

static sfRenderWindow *init_window(window_t *window_t)
{
    sfRenderWindow *window = sfRenderWindow_create(window_t->mode,
        window_t->title, window_t->style, window_t->settings);

    sfRenderWindow_setFramerateLimit(window, 60);
    sfWindow_setMouseCursorVisible((sfWindow*)window, sfFalse);
    return window;
}

static game_clocks_t init_game_clocks(void)
{
    game_clocks_t clocks = {
        .mainClock = sfClock_create(),
        .animationClock = sfClock_create(),
        .currentFrame = 0
    };

    return clocks;
}

static void update_game_state(sfRenderWindow *window, keep_t *params,
    game_clocks_t *clocks)
{
    update_duck_count(params);
    updateduckanimation(params, &clocks->currentFrame, clocks->animationClock);
    update_duck_positions(window, params,
        sfTime_asSeconds(sfClock_restart(clocks->mainClock)));
}

static void update_sprites(sfRenderWindow *window, sprite_t *sprite_t,
    anim_t *esc_animation)
{
    sfVector2f cursorPos = getmousepos(window);

    set_esc_animation(esc_animation, sprite_t->Esc);
    sfSprite_setPosition(sprite_t->crosshair, cursorPos);
    sfSprite_setPosition(sprite_t->Esc, esc_animation->position);
}

void render_window(window_t *window_t, sprite_t *sprite_t)
{
    sfRenderWindow *window = init_window(window_t);
    game_clocks_t clocks = init_game_clocks();
    anim_t *esc_animation = create_animation(30.0f, 1, sfClock_create());
    keep_t *params = init_game_params(sprite_t);

    srand(time(NULL));
    while (sfRenderWindow_isOpen(window)) {
        update_game_state(window, params, &clocks);
        handle_event(window, params);
        update_sprites(window, sprite_t, esc_animation);
    }
    destroy_and_free(window, sprite_t, params, esc_animation);
    sfClock_destroy(clocks.mainClock);
    sfClock_destroy(clocks.animationClock);
}
