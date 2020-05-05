/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Level one ennemy
*/

#include "include/function.h"

static ennemy_t enn[20];
static sfSprite *ennemy_sprite[20];
static sfIntRect ennemyRect[20];
static sfVector2f offset[20];
static const sfClock *clock;
static sfClock *clock_sprite;
static int down = 1;
static int score = 0;
static float seconds_sprite;

int get_score(void)
{
    return (score);
}

void set_lvl_one_ennemy(void)
{
    for (int i = 0; i < 20; i++) {
        ennemyRect[i].top = 0;
        ennemyRect[i].left = 0;
        ennemyRect[i].width = 32;
        ennemyRect[i].height = 32;
        offset[i].x = rand() % 8;
        offset[i].y = 0;
        if (i < 10) {
            enn[i].pos.x = 1280 + rand() % 4000;
        } else {
            enn[i].pos.x = -32 * 3 - rand() % 4000;
        }
        enn[i].pos.y = rand() % 330 + 100;
        enn[i].al = 1;
        enn[i].speed = (rand() % 3) + 2;
        sfSprite_setPosition(ennemy_sprite[i], enn[i].pos);
    }
}

void load_lvl_one_ennemy(void)
{
    sfVector2f scale = {3, 3};
    sfTexture *ennemy;

    ennemy = sfTexture_createFromFile("res/ennemy.png", NULL);
    for (int i = 0; i < 20; i++) {
        ennemy_sprite[i] = sfSprite_create();
        sfSprite_setTexture(ennemy_sprite[i], ennemy, sfTrue);
        sfSprite_setTextureRect(ennemy_sprite[i], ennemyRect[i]);
        sfSprite_setScale(ennemy_sprite[i], scale);
    }
    clock = sfClock_create();
    clock_sprite = sfClock_create();
    set_lvl_one_ennemy();
}

int update_lvl_one_ennemy(sfRenderWindow *window, int live)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(window);
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    for (int i = 0; i < 20; i++) {
        if (on_en(m_pos, enn[i].pos, live) && !down && click() && enn[i].al) {
            enn[i].al = 0;
            score ++;
        }
        if(i < 10)
            enn[i].pos.x -= enn[i].speed;
        else
            enn[i].pos.x += enn[i].speed;
        enn[i].pos.y += cos(time.microseconds / 1000000.0);
        sfSprite_setPosition(ennemy_sprite[i], enn[i].pos);
        animate_lvl_one_ennemy();
        sfRenderWindow_drawSprite(window, ennemy_sprite[i], NULL);
    }
    live = reset_ennemy(enn, live);
    down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (live);
}

void animate_lvl_one_ennemy(void)
{
    sfTime time_sprite;
    time_sprite = sfClock_getElapsedTime(clock_sprite);
    seconds_sprite = time_sprite.microseconds / 1000000.0;
    if (seconds_sprite > 0.1) {
        sfClock_restart(clock_sprite);
        for (int i = 0; i < 20; i++) {
            offset[i].x++;
            ennemyRect[i].left = offset[i].x * 32;
            sfSprite_setTextureRect(ennemy_sprite[i], ennemyRect[i]);
        }
    }
    for (int i = 0; i < 20; i++) {
        if (i < 10)
            offset[i].y = 64;
        if (offset[i].x > 7)
            offset[i].x = 0;
        ennemyRect[i].left = offset[i].x * 32;
        ennemyRect[i].top = enn[i].al ? offset[i].y : offset[i].y + 32;
        sfSprite_setTextureRect(ennemy_sprite[i], ennemyRect[i]);
    }
}
