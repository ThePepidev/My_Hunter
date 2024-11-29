/*
** EPITECH PROJECT, 2024
** bsInitiation-CSFML
** File description:
** main.c
*/

#include "../include/my_hunter.h"
#include "../include/my.h"

static window_t *create_window_struct(sfVideoMode mode, const char *title,
    sfUint32 style, const sfContextSettings *settings)
{
    window_t *window = malloc(sizeof(window_t));

    if (!window)
        return NULL;
    window->mode = mode;
    window->title = title;
    window->style = style;
    window->settings = settings;
    return window;
}

static int my_hunter(void)
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
    return 0;
}

static void print_help(void)
{
    my_putstr("My Hunter Game - Help Guide :\n\n");
    my_putstr("Usage:\n\n    './my_hunter' ");
    my_putstr("[without options] //for gameplay\n");
    my_putstr("or\n    './my_hunter -h' //for Help\n\n");
    my_putstr("Gameplay:\n\n");
    my_putstr("    press play button to quit the menu\n");
    my_putstr("    press esc in game to access to the Menu again");
    my_putstr(" and press it again to quit the game\n");
    my_putstr("    click on duck to kill them and raise your score\n");
    my_putstr("    if 3 ducks reach the screen border you loose\n\n");
    my_putstr("Enjoy !\n");
}

static int is_running_in_tty(char **env)
{
    int i = 0;

    if (!env)
        return 1;
    while (env[i]) {
        if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
            return 0;
        i++;
    }
    return 1;
}

int main(int ac, char **av, char **env)
{
    if (is_running_in_tty(env) == 1)
        return 84;
    if (ac == 1)
        return my_hunter();
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0)
            print_help();
    else {
        my_putstr("Bad arguments\n");
        my_putstr("Try : './my_hunter -h' for help");
        return 84;
    }
    return 0;
}
