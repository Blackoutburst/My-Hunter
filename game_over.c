/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Draw game over
*/

#include "include/function.h"

static sfSound *song;
static sfText *text;
static float volume = 100.0;
static int playing = 0;

void load_game_over(void)
{
    sfSoundBuffer *soundBuffer;
    sfVector2f position = {1150 / 2, 710 / 2};
    sfVector2f scale = {1, 1};
    sfFont *font;

    font = sfFont_createFromFile("res/font.ttf");
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setPosition(text, position);
    sfText_setScale(text, scale);
    sfText_setColor(text, sfGreen);
    song = sfSound_create();
    soundBuffer = sfSoundBuffer_createFromFile("res/game_over.wav");
    sfSound_setBuffer(song, soundBuffer);
}

void set_game_over_song_volume(sfRenderWindow *window)
{
    volume = on_volume_slider(window, volume);
    sfSound_setVolume(song, volume);
}

void clean_game_over(void)
{
    sfText_destroy(text);
    sfSound_destroy(song);
}

void game_over(sfRenderWindow *window)
{
    sfText_setString(text, "Game Over");
    sfRenderWindow_drawText(window, text, NULL);
}

void play_game_over_song(void)
{
    if (!playing) {
        playing = 1;
        sfSound_play(song);
    } else {
        playing = 0;
        sfSound_stop(song);
    }
}
