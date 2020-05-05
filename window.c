/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void poll_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
    {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

void clear(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    clean_menu();
    clean_option();
    clean_menu_option();
    clean_menu_background();
    clean_hover();
    clean_menu_fire();
    clean_star();
    clean_title();
    clean_checkbox();
    clean_red_slider();
    clean_green_slider();
    clean_blue_slider();
    clean_volume_slider();
    clean_size_slider();
    clean_menu_song();
    clean_endl_lvl_one();
    clean_level_one_song();
    clean_shoot_sound();
}

void init()
{
    int scene = 0;
    sfImage *icon = sfImage_createFromFile ("res/icon.png");
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window;
    sfEvent event;
    window = sfRenderWindow_create(mode, "Magical Hunt", sfDefaultStyle, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 64, 64, sfImage_getPixelsPtr(icon));
    play_menu_song();
    update(window, event, scene);
    sfImage_destroy(icon);
    clear(window);
}

int update_scene(int scene, sfRenderWindow *window)
{
    if (scene == 0) {
        main_menu(window);
        scene = main_button_action(scene, window);
        render_title(window);
    }
    if (scene == 2) {
        option_menu(window);
        update_option(window);
        scene = option_button_action(scene, window);
    }
    if (scene == 1) {
        play_menu(window);
        scene = play_button_action(scene, window);
    }
    if (scene == 5) {
        endl_lvl_one(window);
    }
    return (scene);
}

void update(sfRenderWindow *window, sfEvent event, int scene)
{
    int down = 1;

    while (sfRenderWindow_isOpen(window)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            exit(0);
        poll_event(window, event);
        if (scene == -1)
            break;
        if (scene == 4) {
            scene = 5;
            play_menu_song();
            play_level_one_song();
            endl_lvl_one(window);
        }
        scene = update_scene(scene, window);
        if (sfMouse_isButtonPressed(sfMouseLeft) && !down)
            play_shoot_sound();
        cursor(window);
        down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
        sfRenderWindow_display(window);
        sfRenderWindow_clear (window, sfBlack);
    }
}
