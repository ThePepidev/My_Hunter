/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-mathys1.dupont
** File description:
** duck.c
*/

#include "../include/my_hunter.h"
#include "../include/my.h"

int click_duck(sfRenderWindow *window, keep_t *params, sfEvent *event)
{
    sfFloatRect spritePos;
    sfVector2f mousePos;

    for (int i = 0; i < 10; i++) {
        spritePos = sfSprite_getGlobalBounds(params->duck->duck_sprite[i]);
        mousePos = getmousepos(window);
        if (sfFloatRect_contains(&spritePos, mousePos.x, mousePos.y) &&
            event->type == sfEvtMouseButtonPressed &&
                event->key.code == sfMouseLeft)
            params->bool_->Kill_duck[i] = true;
    }
    return 0;
}

void updateduckanimation(keep_t *params, int *currentFrame, sfClock *clock)
{
    sfTime elapsed = sfClock_getElapsedTime(clock);
    sfIntRect frame;

    if (sfTime_asSeconds(elapsed) >= 0.3) {
        *currentFrame = (*currentFrame + 1) % 3;
        frame = (sfIntRect){(*currentFrame) * 110, 0, 110, 110};
        for (int i = 0; i < 10; i++)
            sfSprite_setTextureRect(params->duck->duck_sprite[i], frame);
        sfClock_restart(clock);
    }
}

static void reset_duck(keep_t *params)
{
    for (int i = 0; i < 10; i++) {
        params->duck->duckX[i] = 0.0f;
        params->duck->duckY[i] = rand() % 1010;
    }
}

void update_duck_count(keep_t *params)
{
    if (params->bool_->Menu == true) {
        params->duck->duck_nb = 0;
        params->duck->life_point = 3;
        reset_duck(params);
    }
    if (rand() % 100 < 1 && params->bool_->Menu == false) {
        if (params->duck->duck_nb < 10) {
            params->duck->duck_nb++;
        }
    }
}

void update_duck_positions(sfRenderWindow *window,
    keep_t *params, float deltaTime)
{
    sfVector2f duckPosition;
    const float duckSpeed = 200.0f;

    for (int i = 0; i < params->duck->duck_nb; i++) {
        duckPosition = (sfVector2f){params->duck->duckX[i],
            params->duck->duckY[i]};
        duckPosition.x += duckSpeed * deltaTime;
        if (duckPosition.x > 1920) {
            duckPosition.x = 0.0f;
            duckPosition.y = rand() % 1010;
            params->duck->life_point--;
        }
        if (params->duck->life_point == 0) {
            params->bool_->Game_over = true;
            params->bool_->Menu = true;
        }
        params->duck->duckX[i] = duckPosition.x;
        params->duck->duckY[i] = duckPosition.y;
    }
}

void draw_duck_sprite(sfRenderWindow *window, keep_t *params)
{
    sfVector2f duckPosition;

    for (int i = 0; i < params->duck->duck_nb; i++) {
        if (params->bool_->Kill_duck[i]) {
            params->duck->duckX[i] = 0.00f;
            params->duck->duckY[i] = rand() % 1010;
            params->bool_->Kill_duck[i] = false;
            params->duck->score++;
        }
        duckPosition = (sfVector2f){params->duck->duckX[i],
            params->duck->duckY[i]};
        sfSprite_setPosition(params->duck->duck_sprite[i], duckPosition);
        sfRenderWindow_drawSprite(window, params->duck->duck_sprite[i], NULL);
    }
}
