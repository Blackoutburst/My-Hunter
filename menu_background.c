/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Main menu background function
*/

#include "include/function.h"

static sfSprite *background_sprite;
static sfSprite *crystal_sprite;
static sfClock *clock;
static sfClock *clock_sprite;
static sfIntRect rect2 = {0, 0, 19, 34};
static sfVector2f offset = {0, 0};
static sfIntRect rect = {0, 0, 106, 60};

void load_menu_background(void)
{
    sfVector2f scale = {12.1, 12};
    sfVector2f scale2 = {10, 10};
    sfVector2f position = {1210 / 2 - (19 * 4) / 2, 650 / 2 - (34 * 4) / 2};
    sfTexture *background;
    sfTexture *crystal;
    background = sfTexture_createFromFile("res/menu-background.png", NULL);
    background_sprite = sfSprite_create();
    sfSprite_setTexture(background_sprite, background, sfTrue);
    sfSprite_setTextureRect(background_sprite, rect);
    sfSprite_setScale(background_sprite, scale);
    crystal = sfTexture_createFromFile("res/crystal.png", NULL);
    crystal_sprite = sfSprite_create();
    sfSprite_setTexture(crystal_sprite, crystal, sfTrue);
    sfSprite_setPosition(crystal_sprite, position);
    sfSprite_setTextureRect(crystal_sprite, rect2);
    sfSprite_setScale(crystal_sprite, scale2);
    clock = sfClock_create();
    clock_sprite = sfClock_create();
}

void animate_menu_sprite(void)
{
    float seconds_sprite;
    sfTime time_sprite;

    time_sprite = sfClock_getElapsedTime(clock_sprite);
    seconds_sprite = time_sprite.microseconds / 1000000.0;
    if (seconds_sprite > 0.1) {
        sfClock_restart(clock_sprite);
        offset.x++;
        if (offset.x >= 10) {
            offset.x = 0;
            offset.y++;
        }
        if (offset.y >= 10)
            offset.y = 0;
        rect2.top = offset.y * 34;
        rect2.left = offset.x * 19;
        sfSprite_setTextureRect(crystal_sprite, rect2);
    }
}

void animate_menu(void)
{
    float seconds;
    sfTime time;
    sfVector2f position = {0, 0};

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 6.6)
        sfClock_restart(clock);
    position.x = 1210 / 2 - (19 * 4) / 2;
    position.y = (650 / 2 - (34 * 4) / 2) + 20 * cos(seconds);
    sfSprite_setPosition(crystal_sprite, position);
}

void draw_menu_background(sfRenderWindow *window, int yo)
{
    rect.top = 60 * yo;
    animate_menu_sprite();
    animate_menu();
    sfSprite_setTextureRect(background_sprite, rect);
    sfRenderWindow_drawSprite(window, background_sprite, NULL);
    draw_stars(window);
    if (!yo)
        sfRenderWindow_drawSprite(window, crystal_sprite, NULL);
    render_fire(window);
}

void clean_menu_background(void)
{
    sfClock_destroy(clock);
    sfClock_destroy(clock_sprite);
    sfSprite_destroy(background_sprite);
    sfSprite_destroy(crystal_sprite);
}
