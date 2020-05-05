/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Ennemy shoot
*/

#include "include/function.h"

int on_en(sfVector2i mouse_pos, sfVector2f pos, int live)
{
    if (live <= 0)
        return (0);
    int on = 0;
    int width = 32 * 3 + pos.x;
    int height = 32 * 3 + pos.y;
    if (mouse_pos.x >= pos.x && mouse_pos.y >= pos.y)
        if (mouse_pos.x <= width && mouse_pos.y <= height)
            on = 1;
    return (on);
}

int hit_crystal(ennemy_t *enn, int live)
{
    for (int i = 0; i < 10; i++) {
        if (enn[i].pos.x < (1280 / 2) && enn[i].al) {
            enn[i].al = 0;
            live--;
        }
    }
    for (int i = 10; i < 20; i++) {
        if (enn[i].pos.x > (1280 / 2) - (32 * 3) && enn[i].al) {
            enn[i].al = 0;
            live--;
        }
    }
    if(live <= 0) {
        play_level_one_song();
        play_game_over_song();
    }
    return live;
}

int reset_ennemy(ennemy_t *enn, int live)
{
    if (live <= 0)
        return (0);
    for (int i = 0; i < 10; i++) {
        if (enn[i].pos.x < -32 * 3) {
            enn[i].pos.x = 1280 + rand() % 4000;
            enn[i].al = 1;
            enn[i].speed += 0.1f;
        }
    }
    for (int i = 10; i < 20; i++) {
        if (enn[i].pos.x > 1280) {
            enn[i].pos.x = -32 * 3 - rand() % 4000;
            enn[i].al = 1;
            enn[i].speed += 0.1f;
        }
    }
    live = hit_crystal(enn, live);
    return (live);
}
