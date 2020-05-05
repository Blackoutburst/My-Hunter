/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Menu stars in the sky
*/

#include "include/function.h"
#include <time.h>

static sfSprite *moon_sprite;

void clean_moon(void)
{
    sfSprite_destroy(moon_sprite);
}
void load_moon(void)
{
    sfTexture *moon;
    sfVector2f pos = {10, 10};
    sfVector2f moon_scale = {10, 10};

    moon = sfTexture_createFromFile("res/moon.png", NULL);
    moon_sprite = sfSprite_create();
    sfSprite_setTexture(moon_sprite, moon, sfTrue);
    sfSprite_setPosition(moon_sprite, pos);
    sfSprite_setScale(moon_sprite, moon_scale);
}

void draw_moon(sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, moon_sprite, NULL);
}
