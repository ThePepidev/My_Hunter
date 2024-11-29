/*
** EPITECH PROJECT, 2024
** bsInitiation-CSFML
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H
    #define MY_HUNTER_H

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Keyboard.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdio.h>

typedef struct window_s {
    sfVideoMode mode;
    const char *title;
    sfUint32 style;
    const sfContextSettings *settings;
} window_t;

typedef struct sprite_s {
    sfSprite *Menu;
    sfSprite *Game;
    sfSprite *duck;
    sfSprite *Esc;
    sfSprite *crosshair;
    char const **filepath;
} sprite_t;

typedef struct anim_s {
    float speed;
    int direction;
    sfVector2f position;
    sfClock *clock;
    float deltaTime;
} anim_t;

typedef struct clickable_s {
    sfRectangleShape *Escape;
} clickable_t;

void render_window(window_t *window_t, sprite_t *sprite_t);
void set_esc_animation(anim_t *esc_animation, sfSprite *sprite);
anim_t *create_animation(float speed, int direction, sfClock *clock);
sfVector2f getmousepos(sfRenderWindow *window);
int click_esc(sfRenderWindow *window, clickable_t *rec, sfEvent *event);
clickable_t *create_esc_rectangle(sprite_t *sprite);

#endif
