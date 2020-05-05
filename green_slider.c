/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Cursor color slider
*/

#include "include/function.h"

static sfSprite *slider_sprite;
static sfSprite *slider_tick_sprite;
static sfVector2f tick_position = {1010, 250};

void load_green_slider(void)
{
    sfTexture *slider;
    sfTexture *slider_tick;
    sfVector2f position = {1010, 250};
    sfVector2f scale = {4, 4};
    sfIntRect rect = {0, 0, 8, 32};

    slider = sfTexture_createFromFile("res/slider.png", NULL);
    slider_tick = sfTexture_createFromFile("res/slider-tick.png", NULL);
    rect.left = 16;
    slider_sprite = sfSprite_create();
    sfSprite_setTexture(slider_sprite, slider, sfTrue);
    sfSprite_setTextureRect(slider_sprite, rect);
    sfSprite_setPosition(slider_sprite, position);
    sfSprite_setScale(slider_sprite, scale);
    slider_tick_sprite = sfSprite_create();
    sfSprite_setTexture(slider_tick_sprite, slider_tick, sfTrue);
    sfSprite_setPosition(slider_tick_sprite, tick_position);
    sfSprite_setScale(slider_tick_sprite, scale);
}

int on_green_slider(sfRenderWindow *window, int green)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int on = 0;
    int width = 8 * 4 + 1010;
    int height = 32 * 4 + 250;

    if (mouse_pos.x >= 1010 && mouse_pos.y >= 250)
        if (mouse_pos.x <= width && mouse_pos.y <= height)
            on = 1;
    if (on && click()) {
        tick_position.y = 250 + (mouse_pos.y - 250) - (8 * 2);
        green = 255 - (mouse_pos.y - 250) * 2.1;
    }
    if (tick_position.y < 250)
        tick_position.y = 250;
    if (tick_position.y + (8 * 4) > height)
        tick_position.y = height - (8 * 4);
    if (green < 0)
        green = 0;
    return (green);
}

void clean_green_slider(void)
{
    sfSprite_destroy(slider_sprite);
    sfSprite_destroy(slider_tick_sprite);
}

void render_green_slider(sfRenderWindow *window)
{
    sfSprite_setPosition(slider_tick_sprite, tick_position);
    sfRenderWindow_drawSprite(window, slider_sprite, NULL);
    sfRenderWindow_drawSprite(window, slider_tick_sprite, NULL);
}
