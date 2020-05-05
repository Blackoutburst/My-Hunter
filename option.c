/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Option in option scene
*/

#include "include/function.h"

static sfSprite *options_sprite[4];

void load_option(void)
{
    sfTexture *options;
    sfVector2f position = {100, 150};
    sfVector2f scale = {2, 2};
    sfIntRect rect = {0, 0, 128, 32};

    options = sfTexture_createFromFile("res/options.png", NULL);
    for (int i = 0; i < 4; i++) {
        rect.left = (128 * i);
        options_sprite[i] = sfSprite_create();
        sfSprite_setTexture(options_sprite[i], options, sfTrue);
        sfSprite_setTextureRect(options_sprite[i], rect);
        sfSprite_setPosition(options_sprite[i], position);
        sfSprite_setScale(options_sprite[i], scale);
        position.x = 300 * (i + 1);
        if (i == 0)
            position.x += 50;
    }
}

void clean_option(void)
{
    for (int i = 0; i < 4; i++){
        sfSprite_destroy(options_sprite[i]);
    }
}

void update_option(sfRenderWindow *window)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(window, options_sprite[i], NULL);
    }
    update_checkbox(window);
    render_volume_slider(window);
    render_size_slider(window);
    render_red_slider(window);
    render_green_slider(window);
    render_blue_slider(window);
}
