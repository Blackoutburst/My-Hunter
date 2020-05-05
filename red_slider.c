/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Cursor color slider
*/

#include "include/function.h"

static sfSprite *slider_sprite;
static sfSprite *slider_tick_sprite;
static sfVector2f tick_position = {950, 250};

void load_red_slider(void)
{
    sfTexture *slider;
    sfTexture *slider_tick;
    sfVector2f position = {950, 250};
    sfVector2f scale = {4, 4};
    sfIntRect rect = {0, 0, 8, 32};

    slider = sfTexture_createFromFile("res/slider.png", NULL);
    slider_tick = sfTexture_createFromFile("res/slider-tick.png", NULL);
    rect.left = 8;
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

int on_red_slider(sfRenderWindow *window, int red)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int on = 0;
    int width = 8 * 4 + 950;
    int height = 32 * 4 + 250;

    if (mouse_pos.x >= 950 && mouse_pos.y >= 250)
        if (mouse_pos.x <= width && mouse_pos.y <= height)
            on = 1;
    if (on && click()) {
        tick_position.y = 250 + (mouse_pos.y - 250) - (8 * 2);
        red = 255 - (mouse_pos.y - 250) * 2.1;
    }
    if (tick_position.y < 250)
        tick_position.y = 250;
    if (tick_position.y + (8 * 4) > height)
        tick_position.y = height - (8 * 4);
    if (red < 0)
        red = 0;
    return (red);
}

void clean_red_slider(void)
{
    sfSprite_destroy(slider_sprite);
    sfSprite_destroy(slider_tick_sprite);
}

void render_red_slider(sfRenderWindow *window)
{
    sfSprite_setPosition(slider_tick_sprite, tick_position);
    sfRenderWindow_drawSprite(window, slider_sprite, NULL);
    sfRenderWindow_drawSprite(window, slider_tick_sprite, NULL);
}
