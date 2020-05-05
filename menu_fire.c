/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Menu fire on pillar
*/

#include "include/function.h"

static sfSprite *fire_sprite[2];
static sfClock *clock;
static int x = 0;
static sfIntRect rect = {0, 0, 9, 9};

void clean_menu_fire(void)
{
    sfClock_destroy(clock);
    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(fire_sprite[i]);
    }
}

void render_fire(sfRenderWindow *window)
{
    float seconds;
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.1) {
        x++;
        if (x >=10)
            x = 0;
        sfClock_restart(clock);
    }
    rect.left = 9 * x;
    for (int i = 0; i < 2; i++) {
        sfSprite_setTextureRect(fire_sprite[i], rect);
        sfRenderWindow_drawSprite(window, fire_sprite[i], NULL);
    }
}

void load_menu_fire(void)
{
    sfTexture *fire;
    sfVector2f scale = {10, 10};
    sfVector2f pos[2] = {{165, 378}, {1050, 378}};

    fire = sfTexture_createFromFile("res/fire.png", NULL);
    for (int i = 0; i < 2; i++) {
        fire_sprite[i] = sfSprite_create();
        sfSprite_setTexture(fire_sprite[i], fire, sfTrue);
        sfSprite_setTextureRect(fire_sprite[i], rect);
        sfSprite_setScale(fire_sprite[i], scale);
        sfSprite_setPosition(fire_sprite[i], pos[i]);
    }
    clock = sfClock_create();
}
