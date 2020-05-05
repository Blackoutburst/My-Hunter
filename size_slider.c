/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Cursor size slider
*/

#include "include/function.h"

static sfSprite *slider_sprite;
static sfSprite *slider_tick_sprite;
static sfVector2f tick_position = {720, 250};

void load_size_slider(void)
{
    sfTexture *slider;
    sfTexture *slider_tick;
    sfVector2f position = {720, 250};
    sfVector2f scale = {4, 4};
    sfIntRect rect = {0, 0, 8, 32};

    slider = sfTexture_createFromFile("res/slider.png", NULL);
    slider_tick = sfTexture_createFromFile("res/slider-tick.png", NULL);
    rect.left = 0;
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

float on_size_slider(sfRenderWindow *window, float size)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int on = 0;
    int width = 8 * 4 + 720;
    int height = 32 * 4 + 250;

    if (mouse_pos.x >= 720 && mouse_pos.y >= 250)
        if (mouse_pos.x <= width && mouse_pos.y <= height)
            on = 1;
    if (on && click()) {
        tick_position.y = 250 + (mouse_pos.y - 250) - (8 * 2);
        size = 100 - (mouse_pos.y - 250) / 2;
    }
    if (tick_position.y < 250)
        tick_position.y = 250;
    if (tick_position.y + (8 * 4) > height)
        tick_position.y = height - (8 * 4);
    if (size < 0)
        size = 0;
    return (size);
}

void clean_size_slider(void)
{
    sfSprite_destroy(slider_sprite);
    sfSprite_destroy(slider_tick_sprite);
}

void render_size_slider(sfRenderWindow *window)
{
    sfSprite_setPosition(slider_tick_sprite, tick_position);
    sfRenderWindow_drawSprite(window, slider_sprite, NULL);
    sfRenderWindow_drawSprite(window, slider_tick_sprite, NULL);
}
