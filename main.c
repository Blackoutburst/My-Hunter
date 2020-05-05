/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Main class
*/

#include "include/function.h"

void load_many_thing2(void)
{
    load_lvl_one_ennemy();
    load_shoot_sound();
    load_score();
    load_game_over();
}

void load_many_thing(void)
{
    load_menu_background();
    load_cursor();
    load_option();
    load_main_menu();
    load_option_menu();
    load_stars();
    load_checkbox();
    run_hover_animation_clock();
    load_menu_fire();
    load_play_menu();
    load_title();
    load_red_slider();
    load_green_slider();
    load_blue_slider();
    load_volume_slider();
    load_size_slider();
    load_menu_song();
    load_endl_lvl_one();
    load_level_one_song();
    load_many_thing2();
}

int main(void)
{
    load_many_thing();
    init();
    return (0);
}
