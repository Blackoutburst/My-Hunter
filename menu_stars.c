/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Menu stars in the sky
*/

#include "include/function.h"
#include <time.h>

static sfClock *clocke;
static start_t star[40];

void clean_star(void)
{
    sfClock_destroy(clocke);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(star[i].sprite);
    clean_moon();
}

void set_stars_position(void)
{
    for (int i = 0; i < 40; i++) {
        star[i].position.x = rand() % 1280;
        star[i].position.y = rand() % 330;
        star[i].color.r = 255;
        star[i].color.g = 255;
        star[i].color.b = 255;
        star[i].color.a = rand() % 256;
    }
}

void shine_stars_animation(void)
{
    float seconds;
    sfTime timer;

    timer = sfClock_getElapsedTime(clocke);
    seconds = timer.microseconds / 1000000.0;
    if (seconds > 6.3)
        sfClock_restart(clocke);
    for (int i = 0; i < 40; i++) {
        star[i].color.a = 255 * fabs(cos(star[i].position.x + seconds));
        sfSprite_setColor(star[i].sprite, star[i].color);
    }
}

void load_stars(void)
{
    sfTexture *stars;
    sfVector2f scale = {4, 4};

    srand(time(NULL));
    set_stars_position();
    stars = sfTexture_createFromFile("res/star.png", NULL);
    for (int i = 0; i < 40; i++) {
        star[i].sprite = sfSprite_create();
        sfSprite_setTexture(star[i].sprite, stars, sfTrue);
        sfSprite_setPosition(star[i].sprite, star[i].position);
        sfSprite_setColor(star[i].sprite, star[i].color);
        sfSprite_setScale(star[i].sprite, scale);
    }
    clocke = sfClock_create();
    load_moon();
}

void draw_stars(sfRenderWindow *window)
{
    shine_stars_animation();
    for (int i = 0; i < 40; i++) {
        sfRenderWindow_drawSprite(window, star[i].sprite, NULL);
    }
    draw_moon(window);
}
