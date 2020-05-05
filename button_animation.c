/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Button hover animation
*/

#include "include/function.h"

static sfIntRect rect[3] = {{0, 0, 128, 32}, {0, 0, 128, 32}, {0, 0, 128, 32}};
static int offset[3] = {0, 0, 0};
static sfClock *clock;
static sfVector2i m_pos = {0, 0};

void reset_hover_animation_offset(void)
{
    for (int i = 0; i < 3; i++)
        if (offset[i] >= 20)
            offset[i] = 0;
}

void update_hover_animation(sfSprite **button_sprite, int i, int left)
{
    sfVector2f but_pos = sfSprite_getPosition(button_sprite[i]);
    sfVector2f but_scale = sfSprite_getScale(button_sprite[i]);
    if (on_button(m_pos, but_pos, but_scale) && i == 0)
        offset[i]++;
    else if (i == 0)
        offset[i] = 0;
    if (on_button(m_pos, but_pos, but_scale) && i == 1)
        offset[i]++;
    else if (i == 1)
            offset[i] = 0;
    if (on_button(m_pos, but_pos, but_scale) && i == 2)
        offset[i]++;
    else if (i == 2)
        offset[i] = 0;
    reset_hover_animation_offset();
    rect[i].top = 32 * offset[i];
    rect[i].left = (128 * i) + left;
    sfSprite_setTextureRect(button_sprite[i], rect[i]);
}

void clean_hover(void)
{
    sfClock_destroy(clock);
}

void run_hover_animation_clock(void)
{
    clock = sfClock_create();
}

void hover_animation(sfSprite **but_s, sfRenderWindow *win, int lef, int coun)
{
    float seconds;
    sfTime time;

    m_pos = sfMouse_getPositionRenderWindow(win);
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds >= 0.1) {
        for (int i = 0; i < coun; i++)
            update_hover_animation(but_s, i, lef);
        sfClock_restart(clock);
    }
    for (int i = 0; i < coun; i++)
        sfRenderWindow_drawSprite(win, but_s[i], NULL);
}
