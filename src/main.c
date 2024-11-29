/*
** EPITECH PROJECT, 2024
** bsInitiation-CSFML
** File description:
** main.c
*/

#include "../include/my_hunter.h"

static window_t *create_window_struct(sfVideoMode mode, const char *title,
    sfUint32 style, const sfContextSettings *settings)
{
    window_t *window = malloc(sizeof(window_t));

    window->mode = mode;
    window->title = title;
    window->style = style;
    window->settings = settings;
    return window;
}

int main(int ac, char **av)
{
    sprite_t *sprite;
    window_t *window;
    sfVideoMode mode = {1920, 1080, 32};
    char const *texture_filepath[] = {"textures/Menu.png",
        "textures/background.png", "textures/Duck.png",
        "textures/esc_touch.png", "textures/crosshair.png",
        "textures/My_Hunter.png", "textures/play.png",
        "textures/play_colored.png", NULL};
    sfMusic *music;

    window = create_window_struct(mode, "my_hunter", sfFullscreen, NULL);
    sprite = create_sprite(texture_filepath);
    music = sfMusic_createFromFile("musique/music.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    render_window(window, sprite);
    sfMusic_destroy(music);
    free(sprite);
    free(window);
}
