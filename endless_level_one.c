/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Endlesss mode level one
*/

#include "include/function.h"

static int live = 3;
static sfSprite *life_sprite;
static sfIntRect lifebar = {0, 0, 64, 8};

void load_endl_lvl_one(void)
{
    sfTexture *life;
    sfVector2f position = {0, 688};
    sfVector2f scale = {4, 4};

    life = sfTexture_createFromFile("res/life.png", NULL);
    life_sprite = sfSprite_create();
    sfSprite_setTexture(life_sprite, life, sfTrue);
    sfSprite_setTextureRect(life_sprite, lifebar);
    sfSprite_setPosition(life_sprite, position);
    sfSprite_setScale(life_sprite, scale);
}

void clean_endl_lvl_one(void)
{
    sfSprite_destroy(life_sprite);
}

void animate_life_bar(void)
{
    if (live == 3)
        lifebar.top = 0;
    if (live == 2)
        lifebar.top = 8;
    if (live == 1)
        lifebar.top = 16;
    if (live == 0)
        lifebar.top = 24;
}

void endl_lvl_one(sfRenderWindow *window)
{
    if (live > 0)
        draw_menu_background(window, 0);
    else
        draw_menu_background(window, 1);
    animate_life_bar();
    loop_level_one_song();
    sfSprite_setTextureRect(life_sprite, lifebar);
    sfRenderWindow_drawSprite(window, life_sprite, NULL);
    draw_score(window);
    live = update_lvl_one_ennemy(window, live);
    if (live <= 0)
        game_over(window);
}
