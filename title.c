/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Render title on sceen
*/

#include "include/function.h"

static sfSprite *title_sprite;

void load_title(void)
{
    sfTexture *title;
    sfVector2f scale = {3, 3};
    sfVector2f position = {505,50};

    title = sfTexture_createFromFile("res/title.png", NULL);
    title_sprite = sfSprite_create();
    sfSprite_setTexture(title_sprite, title, sfTrue);
    sfSprite_setPosition(title_sprite, position);
    sfSprite_setScale(title_sprite, scale);
}

void clean_title(void)
{
    sfSprite_destroy(title_sprite);
}

void render_title(sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, title_sprite, NULL);
}
