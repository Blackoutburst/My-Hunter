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

int play_button_action(int scene, sfRenderWindow *window)
{
    sfVector2i m_pos = {0, 0};
    sfVector2f but_pos = {0, 0};
    sfVector2f but_scale = {0, 0};

    m_pos = sfMouse_getPositionRenderWindow(window);
    for (int i = 0; i < 3; i++) {
        but_pos = sfSprite_getPosition(button_sprite[i]);
        but_scale = sfSprite_getScale(button_sprite[i]);
        if (on_button(m_pos, but_pos, but_scale) && i == 0 && !down && click())
            scene = 0;
        if (on_button(m_pos, but_pos, but_scale) && i == 1 && !down && click())
            scene = 1;
        if (on_button(m_pos, but_pos, but_scale) && i == 2 && !down && click())
            scene = 4;
    }
    down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (scene);
}

void load_play_menu(void)
{
    sfTexture *button;
    sfVector2f scale = {2, 2};
    sfIntRect rect = {0, 0, 128, 32};

    clock = sfClock_create();
    button = sfTexture_createFromFile("res/button.png", NULL);
    for (int i = 0; i < 3; i++) {
        rect.left = (128 * i) + 384;
        button_sprite[i] = sfSprite_create();
        sfSprite_setTexture(button_sprite[i], button, sfTrue);
        sfSprite_setTextureRect(button_sprite[i], rect);
        sfSprite_setScale(button_sprite[i], scale);
    }
}

void clean_play_menu(void)
{
    sfClock_destroy(clock);
    for (int i = 0; i < 3; i++) {
        sfSprite_destroy(button_sprite[i]);
    }
}

void play_button_animation(void)
{
    sfTime time;
    float seconds;
    sfVector2f position = {0, 0};
    sfColor gray = {100, 100, 100, 255};

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 6.6)
        sfClock_restart(clock);
    position.x = 20 + 10 * cos(seconds);
    position.y = 500;
    sfSprite_setPosition (button_sprite[0], position);
    position.x = 20 + 10 * cos(seconds);
    position.y = 200;
    sfSprite_setColor(button_sprite[1], gray);
    sfSprite_setPosition (button_sprite[1], position);
    position.x = 100 - 10 * cos(seconds);
    position.y = 350;
    sfSprite_setPosition (button_sprite[2], position);
}

void play_menu(sfRenderWindow *window)
{
    play_button_animation();
    draw_menu_background(window, 0);
    hover_animation(button_sprite, window, 384, 3);
}
