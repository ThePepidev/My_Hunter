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
    #include <stdbool.h>
    #include <time.h>

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
    sfSprite *Title;
    sfSprite *play;
    sfSprite *play_colored;
    char const **textures;
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
    sfRectangleShape *Play;
} clickable_t;

typedef struct bool_s {
    bool colored_play;
    bool Menu;
    bool Duck;
    bool Kill_duck[10];
    bool Game_over;
} bool_t;

typedef struct duck_s {
    int duck_nb;
    float duckX[10];
    float duckY[10];
    sfSprite *duck_sprite[10];
    int life_point;
    int score;
} duck_t;

typedef struct keep_s {
    sprite_t *sprite;
    clickable_t *rec;
    bool_t *bool_;
    duck_t *duck;
} keep_t;

typedef struct game_clocks_s {
    sfClock *mainClock;
    sfClock *animationClock;
    int currentFrame;
} game_clocks_t;

void render_window(window_t *window_t, sprite_t *sprite_t);
void set_esc_animation(anim_t *esc_animation, sfSprite *sprite);
anim_t *create_animation(float speed, int direction, sfClock *clock);
sfVector2f getmousepos(sfRenderWindow *window);
int click_esc(sfRenderWindow *window, clickable_t *rec, sfEvent *event);
clickable_t *create_all_rectangle(sprite_t *sprite);
sprite_t *create_sprite(char const **texture_filepath);
int mouse_on_play(sfRenderWindow *window, clickable_t *rec);
bool_t *keep_bool(void);
int click_play(sfRenderWindow *window, clickable_t *rec, sfEvent *event);
keep_t *keep_struct(sprite_t *sprite,
    clickable_t *rec, bool_t *bool_s, duck_t *duck);
duck_t *create_duck(sprite_t *sprite);
void update_duck_positions(sfRenderWindow *window,
    keep_t *params, float deltaTime);
void update_duck_count(keep_t *params);
void updateduckanimation(keep_t *params, int *currentFrame, sfClock *clock);
int click_duck(sfRenderWindow *window, keep_t *params, sfEvent *event);
void draw_duck_sprite(sfRenderWindow *window, keep_t *params);
keep_t *init_game_params(sprite_t *sprite_t);
sfText *create_text(keep_t *params);
void display_text(sfRenderWindow *window, keep_t *params);

#endif
