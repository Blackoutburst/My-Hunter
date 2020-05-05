/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Button function
*/

#include "include/function.h"

int click()
{
    return (sfMouse_isButtonPressed(sfMouseLeft));
}

int on_button(sfVector2i mouse_pos, sfVector2f but_pos, sfVector2f but_scale)
{
    int on = 0;
    int width = 128 * but_scale.x + but_pos.x;
    int height = 32 * but_scale.y + but_pos.y;
    if (mouse_pos.x >= but_pos.x && mouse_pos.y >= but_pos.y)
        if (mouse_pos.x <= width && mouse_pos.y <= height)
            on = 1;
    return (on);
}
