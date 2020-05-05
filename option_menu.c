/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Main menu related function
*/

#include "include/function.h"

static sfSprite *button_sprite[3];
static sfClock *clock;
static int down = 1;

int option_button_action(int scene, sfRenderWindow *window)
{
    sfVector2i m_pos = {0, 0};
    sfVector2f but_pos = {0, 0};
    sfVector2f but_scale = {0, 0};
    m_pos = sfMouse_getPositionRenderWindow(window);
    for (int i = 0; i < 1; i ++) {
        but_pos = sfSprite_getPosition(button_sprite[i]);
        but_scale = sfSprite_getScale(button_sprite[i]);
        if (on_button(m_pos, but_pos, but_scale) && i == 0 && !down && click())
            scene = 0;
    }
    down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (scene);
}

void load_option_menu(void)
{
    sfTexture *button;
    sfIntRect rect = {0, 0, 128, 32};
    sfVector2f scale = {2, 2};
    clock = sfClock_create();
    button = sfTexture_createFromFile("res/button.png", NULL);
    for (int i = 0; i < 1; i++) {
        rect.left = 128 * 3;
        button_sprite[i] = sfSprite_create();
        sfSprite_setTexture(button_sprite[i], button, sfTrue);
        sfSprite_setTextureRect(button_sprite[i], rect);
        sfSprite_setScale(button_sprite[i], scale);
    }
}

void clean_menu_option(void)
{
    sfClock_destroy(clock);
    for (int i = 0; i < 1; i++) {
        sfSprite_destroy(button_sprite[i]);
    }
}

void option_button_animation(void)
{
    float seconds;
    sfTime time;
    sfVector2f position = {0, 0};

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 6.6)
        sfClock_restart(clock);
    position.x = 10 * cos(seconds);
    position.y = 650;
    sfSprite_setPosition (button_sprite[0], position);
}

void option_menu(sfRenderWindow *window)
{
    update_cursor(window);
    option_button_animation();
    draw_menu_background(window, 0);
    hover_animation(button_sprite, window, 384, 1);
}
