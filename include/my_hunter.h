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
    char const **filepath;
} sprite_t;

void render_window(window_t *window_t, sprite_t *sprite_t);

#endif
