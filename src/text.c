/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-mathys1.dupont
** File description:
** text.c
*/

#include "../include/my_hunter.h"
#include "../include/my.h"

static int len_nbr(float *nb_copy)
{
    int len_nb = 0;

    while (*nb_copy > 1.0) {
        (*nb_copy) /= 10.0;
        len_nb++;
    }
    return len_nb;
}

static char *cast_to_str(int nb)
{
    int temp;
    float nb_copy = (float)nb;
    char *str;
    int i = 0;
    int len_nb = len_nbr(&nb_copy);

    if (nb == 0)
        return "0";
    str = malloc(len_nb + 1);
    for (; i < len_nb; i++) {
        temp = (int)nb_copy;
        nb_copy -= temp;
        nb_copy *= 10;
        str[i] = (nb_copy + 48);
    }
    str[i] = '\0';
    return str;
}

static char *str_cat(char *str1, char *str2)
{
    int len_all = my_strlen(str1) + my_strlen(str2);
    char *result = malloc(len_all + 1);
    int i = my_strlen(str1);

    my_strcpy(result, str1);
    my_strcat(result, str2);
    return result;
}

sfText *create_text(keep_t *params)
{
    sfFont *font = sfFont_createFromFile("Minecraft.ttf");
    sfText *score = sfText_create();
    char *score_nb = cast_to_str(params->duck->score);
    char *score_str = str_cat("score : ", score_nb);

    sfText_setFont(score, font);
    sfText_setString(score, score_str);
    sfText_setCharacterSize(score, 140);
    sfText_setPosition(score, (sfVector2f){580, 350});
    free(score_str);
    return score;
}

void display_text(sfRenderWindow *window, keep_t *params)
{
    sfText *score = create_text(params);

    if (!params->bool_->Game_over)
        sfRenderWindow_drawSprite(window, params->sprite->Title, NULL);
    else
        sfRenderWindow_drawText(window, score, NULL);
}
