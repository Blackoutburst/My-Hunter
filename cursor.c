/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Cursor related function
*/

#include "include/function.h"

static sfSprite *cursor_sprite;
static sfColor color = {255, 255, 255, 255};
static float size = 100;
static sfVector2f scale = {8, 8};

void load_cursor(void)
{
    sfTexture *cursor_texture;
    sfVector2f scale = {8, 8};
    cursor_texture = sfTexture_createFromFile("res/cursor.png", NULL);
    cursor_sprite = sfSprite_create();
    sfSprite_setTexture(cursor_sprite, cursor_texture, sfTrue);
    sfSprite_setScale(cursor_sprite, scale);
}

void update_cursor(sfRenderWindow *window)
{

    size = on_size_slider(window, size);
    scale.x = 8 * size / 100;
    scale.y = 8 * size / 100;
    color.r = on_red_slider(window, color.r);
    color.g = on_green_slider(window, color.g);
    color.b = on_blue_slider(window, color.b);
    sfSprite_setColor(cursor_sprite, color);
    sfSprite_setScale(cursor_sprite, scale);
}

void cursor(sfRenderWindow *window)
{
    sfVector2f position = {0, 0};
    sfVector2i mouse_position = {0, 0};
    scale.x = 8 * size / 100;
    scale.y = 8 * size / 100;
    mouse_position = sfMouse_getPositionRenderWindow(window);
    position.x = (float) mouse_position.x - scale.x * 4.5;
    position.y = (float) mouse_position.y - scale.y * 4.5;
    sfSprite_setPosition(cursor_sprite, position);
    sfRenderWindow_drawSprite(window, cursor_sprite, NULL);
}
