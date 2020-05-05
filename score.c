/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Ennemy shoot
*/

#include "include/function.h"

static sfText *text;

void load_score(void)
{
    sfFont *font;
    sfVector2f position = {0,0};
    sfVector2f scale = {1,1};
    font = sfFont_createFromFile("res/font.ttf");
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setPosition(text, position);
    sfText_setScale(text, scale);
    sfText_setColor(text, sfGreen);
}

void clean_score(void)
{
    sfText_destroy(text);
}

int get_nb_size(int nb)
{
    int size = 1;
    int len = 0;

    while (size*10 <= nb) {
        size = size * 10;
        len ++;
    }
    return (len);
}

int my_nbr_to_str(int nb, char *str, int i)
{
    if (nb < 0) {
        str[i] = '-';
        return (my_nbr_to_str(-nb, str, i - 1));
    }
    if (nb >= 10) {
        str[i] = (nb % 10) + 48;
        return (my_nbr_to_str(nb / 10, str, i - 1));
    } else {
        str[i] = (nb % 10) + 48;
        return (0);
    }
}

void draw_score(sfRenderWindow *window)
{
    char string[18];
    int offset = 8 + get_nb_size(get_score());

    string[0] = 'S';
    string[1] = 'c';
    string[2] = 'o';
    string[3] = 'r';
    string[4] = 'e';
    string[5] = ' ';
    string[6] = ':';
    string[7] = ' ';
    my_nbr_to_str(get_score(), string, offset);
    sfText_setString(text, string);
    sfRenderWindow_drawText(window, text, NULL);
}
