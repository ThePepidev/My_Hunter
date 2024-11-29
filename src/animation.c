/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-mathys1.dupont
** File description:
** escape_animation.c
*/

#include "../include/my_hunter.h"

void set_esc_animation(anim_t *esc_animation, sfSprite *sprite)
{
    float deltaTime = sfTime_asSeconds(sfClock_restart(esc_animation->clock));
    sfVector2f position = sfSprite_getPosition(sprite);

    esc_animation->position = position;
    esc_animation->deltaTime = deltaTime;
    esc_animation->position.y += esc_animation->direction *
        esc_animation->speed * esc_animation->deltaTime;
    if (esc_animation->position.y >= 10)
        esc_animation->direction = -1;
    if (esc_animation->position.y <= 0)
        esc_animation->direction = 1;
}

anim_t *create_animation(float speed, int direction, sfClock *clock)
{
    anim_t *animation = malloc(sizeof(anim_t));

    animation->speed = speed;
    animation->direction = direction;
    animation->clock = clock;
    return animation;
}
