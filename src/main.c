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

static int create_sprite_suite(char const **texture_filepath,
    sprite_t *sprite, sfSprite *sprite_temp, int i)
{
    sfTexture *texture;
    sfVector2u imageSize;
    float scaleX;
    float scaleY;

    for (i = 0; i < 2; i++) {
        sprite_temp = sfSprite_create();
        texture = sfTexture_createFromFile(texture_filepath[i], NULL);
        sfSprite_setTexture(sprite_temp, texture, sfTrue);
        imageSize = sfTexture_getSize(texture);
        scaleX = (float)1920 / imageSize.x;
        scaleY = (float)1080 / imageSize.y;
        sfSprite_setScale(sprite_temp, (sfVector2f){scaleX, scaleY});
        if (i == 0)
            sprite->Menu = sprite_temp;
        if (i == 1)
            sprite->Game = sprite_temp;
    }
    return 0;
}

static sprite_t *create_sprite(char const **texture_filepath)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfSprite *sprite_temp;
    sfTexture *texture;
    int i;

    create_sprite_suite(texture_filepath, sprite, sprite_temp, i);
    i = 2;
    for (; i < 3; i++) {
        sprite_temp = sfSprite_create();
        texture = sfTexture_createFromFile(texture_filepath[i], NULL);
        sfSprite_setTexture(sprite_temp, texture, sfTrue);
        sprite->duck = sprite_temp;
    }
    return sprite;
}

int main(int ac, char **av)
{
    sprite_t *sprite;
    window_t *window;
    sfVideoMode mode = {1920, 1080, 32};
    char const *texture_filepath[] = {"textures/Menu.png",
        "textures/background.png", "textures/Duck.png", NULL};
    sfMusic *music;

    window = create_window_struct(mode, "my_hunter", sfFullscreen, NULL);
    sprite = create_sprite(texture_filepath);
    music = sfMusic_createFromFile("musique/music.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    render_window(window, sprite);
    sfMusic_destroy(music);
    free(window);
}
