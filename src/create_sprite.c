/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-mathys1.dupont
** File description:
** create_sprite.c
*/

#include "../include/my_hunter.h"
#include "../include/my.h"

static int create_sprite_background(char const **texture_filepath,
    sprite_t *sprite, sfSprite *sprite_temp, int *i)
{
    sfTexture *texture;
    sfVector2u imageSize;
    float scaleX;
    float scaleY;

    for (*i = 0; *i < 2; (*i)++) {
        sprite_temp = sfSprite_create();
        texture = sfTexture_createFromFile(texture_filepath[*i], NULL);
        sfSprite_setTexture(sprite_temp, texture, sfTrue);
        imageSize = sfTexture_getSize(texture);
        scaleX = (float)1920 / imageSize.x;
        scaleY = (float)1080 / imageSize.y;
        sfSprite_setScale(sprite_temp, (sfVector2f){scaleX, scaleY});
        if (*i == 0)
            sprite->Menu = sprite_temp;
        if (*i == 1)
            sprite->Game = sprite_temp;
        sprite->texture[*i] = texture;
    }
    return 0;
}

static int create_sprite_little(char const **texture_filepath,
    sprite_t *sprite, sfSprite *sprite_temp, int *i)
{
    sfTexture *texture;
    sfVector2u imageSize;
    float scaleX;
    float scaleY;

    for (; *i < 4; (*i)++) {
        sprite_temp = sfSprite_create();
        texture = sfTexture_createFromFile(texture_filepath[*i], NULL);
        sfSprite_setTexture(sprite_temp, texture, sfTrue);
        imageSize = sfTexture_getSize(texture);
        scaleX = (float)125 / imageSize.x;
        scaleY = (float)125 / imageSize.y;
        sfSprite_setScale(sprite_temp, (sfVector2f){scaleX, scaleY});
        sprite->Esc = sprite_temp;
        sprite->texture[*i] = texture;
    }
    return 0;
}

static int create_play_sprite(char const **texture_filepath,
    sprite_t *sprite, sfSprite *sprite_temp, int *i)
{
    sfTexture *texture;
    sfVector2u imageSize;
    float scaleX;
    float scaleY;

    for (; *i < 8; (*i)++) {
        sprite_temp = sfSprite_create();
        texture = sfTexture_createFromFile(texture_filepath[*i], NULL);
        sfSprite_setTexture(sprite_temp, texture, sfTrue);
        imageSize = sfTexture_getSize(texture);
        scaleX = (float)250 / imageSize.x;
        scaleY = (float)100 / imageSize.y;
        sfSprite_setScale(sprite_temp, (sfVector2f){scaleX, scaleY});
        sfSprite_setPosition(sprite_temp, (sfVector2f){810, 600});
        if (*i == 6)
            sprite->play = sprite_temp;
        if (*i == 7)
            sprite->play_colored = sprite_temp;
        sprite->texture[*i] = texture;
    }
}

static int create_title_sprite(char const **texture_filepath,
    sprite_t *sprite, sfSprite *sprite_temp, int *i)
{
    sfTexture *texture;
    sfVector2u imagesize;
    sfVector2f position = {560, 240};
    float scaleX;
    float scaleY;

    for (; *i < 6; (*i)++) {
        sprite_temp = sfSprite_create();
        texture = sfTexture_createFromFile(texture_filepath[*i], NULL);
        sfSprite_setTexture(sprite_temp, texture, sfTrue);
        imagesize = sfTexture_getSize(texture);
        scaleX = (float)800 / imagesize.x;
        scaleY = (float)125 / imagesize.y;
        sfSprite_setScale(sprite_temp, (sfVector2f){scaleX, scaleY});
        sfSprite_setPosition(sprite_temp, position);
        sprite->Title = sprite_temp;
        sprite->texture[*i] = texture;
    }
}

static int create_sprite_cursor(char const **texture_filepath,
    sprite_t *sprite, sfSprite *sprite_temp, int *i)
{
    sfTexture *texture;
    sfVector2u imageSize;
    float scaleX;
    float scaleY;

    for (; *i < 5; (*i)++) {
        sprite_temp = sfSprite_create();
        texture = sfTexture_createFromFile(texture_filepath[*i], NULL);
        sfSprite_setTexture(sprite_temp, texture, sfTrue);
        imageSize = sfTexture_getSize(texture);
        scaleX = (float)50 / imageSize.x;
        scaleY = (float)50 / imageSize.y;
        sfSprite_setScale(sprite_temp, (sfVector2f){scaleX, scaleY});
        sprite->crosshair = sprite_temp;
        sprite->texture[*i] = texture;
    }
    return 0;
}

sprite_t *create_sprite(char const **texture_filepath)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfSprite *sprite_temp;
    sfTexture *texture;
    int i;

    create_sprite_background(texture_filepath, sprite, sprite_temp, &i);
    for (; i < 3; i++) {
        sprite_temp = sfSprite_create();
        texture = sfTexture_createFromFile(texture_filepath[i], NULL);
        sfSprite_setTexture(sprite_temp, texture, sfTrue);
        sprite->duck = sprite_temp;
        sprite->texture[i] = texture;
    }
    create_sprite_little(texture_filepath, sprite, sprite_temp, &i);
    create_sprite_cursor(texture_filepath, sprite, sprite_temp, &i);
    create_title_sprite(texture_filepath, sprite, sprite_temp, &i);
    create_play_sprite(texture_filepath, sprite, sprite_temp, &i);
    return sprite;
}
