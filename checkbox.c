/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Checkbox in option menu
*/

#include "include/function.h"

static sfSprite *checkbox_sprite;
static sfClock *clock;
static sfIntRect rect = {0, 0, 8, 8};
static sfVector2i offset = {0, 0};
static int fullscreen = 0;
static int down = 1;

void load_checkbox(void)
{
    sfTexture *checkbox;
    sfVector2f scale = {8, 8};
    sfVector2f position = {190,250};
    clock = sfClock_create();
    checkbox = sfTexture_createFromFile("res/checkbox.png", NULL);
    checkbox_sprite = sfSprite_create();
    sfSprite_setTexture(checkbox_sprite, checkbox, sfTrue);
    sfSprite_setTextureRect(checkbox_sprite, rect);
    sfSprite_setScale(checkbox_sprite, scale);
    sfSprite_setPosition(checkbox_sprite, position);
}

int on_checkbox(sfVector2i mouse_pos, sfRenderWindow *window)
{
    int on = 0;
    int width = 8 * 8 + 190;
    int height = 8 * 8 + 250;
    if (mouse_pos.x >= 190 && mouse_pos.y >= 250)
        if (mouse_pos.x <= width && mouse_pos.y <= height)
            on = 1;
    if (on && click() && !down) {
        fullscreen = toggle_fullscreen(window);
    }
    down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (on);
}

void clean_checkbox(void)
{
    sfSprite_destroy(checkbox_sprite);
    sfClock_destroy(clock);
}

void update_checkbox(sfRenderWindow *window)
{
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);
    float seconds;
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.05) {
        if (on_checkbox(mouse_position, window)) {
            offset.x ++;
        } else {
            offset.x = 0;
        }
        if (offset.x >= 20)
            offset.x = 0;
        rect.left = 8 * offset.x;
        sfClock_restart(clock);
    }
    rect.top = fullscreen ? 8 : 0;
    sfSprite_setTextureRect(checkbox_sprite, rect);
    sfRenderWindow_drawSprite(window, checkbox_sprite, NULL);
}
