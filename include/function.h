/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** All function prototype
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct star {
    sfSprite *sprite;
    sfColor color;
    float alpha;
    sfVector2f position;

} start_t;

typedef struct ennemy {
    sfVector2f pos;
    int al;
    float speed;
} ennemy_t;

int my_nbr_to_str(int nb, char *str, int i);
void update(sfRenderWindow *window, sfEvent event, int scene);
int update_scene(int scene, sfRenderWindow *window);
void init(void);
void clear(sfRenderWindow *window);
void poll_event(sfRenderWindow *window, sfEvent event);
void option_menu(sfRenderWindow *window);
void option_button_animation(void);
void clean_menu_option(void);
void load_option_menu(void);
int option_button_action(int scene, sfRenderWindow *window);
int main(void);
void main_menu(sfRenderWindow *window);
void main_button_animation(void);
void clean_menu(void);
void load_main_menu(void);
int main_button_action(int scene, sfRenderWindow *window);
void cursor(sfRenderWindow *window);
int on_button(sfVector2i mouse_pos, sfVector2f but_pos, sfVector2f but_scale);
int click(void);
void load_cursor(void);
void load_menu_background(void);
void draw_menu_background(sfRenderWindow *window, int yo);
void clean_menu_background(void);
void animate_menu(void);
void animate_menu_sprite(void);
void load_stars(void);
void draw_stars(sfRenderWindow *window);
void set_stars_position(void);
void clean_hover(void);
void update_hover_animation(sfSprite **button_sprite, int i, int left);
void run_hover_animation_clock(void);
void load_menu_fire(void);
void render_fire(sfRenderWindow *window);
void clean_menu_fire(void);
void clean_star(void);
void hover_animation(sfSprite **but_s, sfRenderWindow *win, int lef, int coun);
int play_button_action(int scene, sfRenderWindow *window);
void load_play_menu(void);
void clean_play_menu(void);
void play_button_animation(void);
void play_menu(sfRenderWindow *window);
void load_title(void);
void clean_title(void);
void render_title(sfRenderWindow *window);
int toggle_fullscreen(sfRenderWindow *window);
void load_option(void);
void clean_option(void);
void update_option(sfRenderWindow *window);
void clean_checkbox(void);
void load_checkbox(void);
void update_checkbox(sfRenderWindow *window);
void load_red_slider(void);
void render_red_slider(sfRenderWindow *window);
void clean_red_slider(void);
void load_green_slider(void);
void render_green_slider(sfRenderWindow *window);
void clean_green_slider(void);
void load_blue_slider(void);
void render_blue_slider(sfRenderWindow *window);
void clean_blue_slider(void);
int on_red_slider(sfRenderWindow *window, int red);
int on_green_slider(sfRenderWindow *window, int green);
int on_blue_slider(sfRenderWindow *window, int blue);
void load_volume_slider(void);
void render_volume_slider(sfRenderWindow *window);
void clean_volume_slider(void);
float on_volume_slider(sfRenderWindow *window, float volume);
void play_menu_song(void);
void clean_menu_song(void);
void set_menu_song_volume(sfRenderWindow *window);
void load_menu_song(void);
void load_size_slider(void);
void render_size_slider(sfRenderWindow *window);
void clean_size_slider(void);
float on_size_slider(sfRenderWindow *window, float volume);
void load_endl_lvl_one(void);
void clean_endl_lvl_one(void);
void endl_lvl_one(sfRenderWindow *window);
void play_level_one_song(void);
void clean_level_one_song(void);
void set_level_one_song_volume(sfRenderWindow *window);
void load_level_one_song(void);
void load_lvl_one_ennemy(void);
void load_many_thing(void);
int update_lvl_one_ennemy(sfRenderWindow *window, int live);
void animate_lvl_one_ennemy(void);
void update_cursor(sfRenderWindow *window);
int on_en(sfVector2i mouse_pos, sfVector2f position, int live);
int reset_ennemy(ennemy_t *enn, int live);
void load_shoot_sound(void);
void play_shoot_sound(void);
void clean_shoot_sound(void);
void set_shoot_sound_volume(sfRenderWindow *window);
int hit_crystal(ennemy_t *enn, int live);
void loop_level_one_song(void);
void load_score(void);
void draw_score(sfRenderWindow *window);
int get_score(void);
void load_game_over(void);
void clean_game_over(void);
void game_over(sfRenderWindow *window);
void play_game_over_song(void);
void set_game_over_song_volume(sfRenderWindow *window);
void load_moon(void);
void clean_moon(void);
void draw_moon(sfRenderWindow *window);
