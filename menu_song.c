/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Menu song function
*/

#include "include/function.h"

static sfSound *song;
static float volume = 100.0;
static int playing = 0;

void load_menu_song(void)
{
    sfSoundBuffer *soundBuffer;
    song = sfSound_create();
    soundBuffer = sfSoundBuffer_createFromFile("res/menu.wav");
    sfSound_setBuffer(song, soundBuffer);
    sfSound_setLoop (song, sfTrue);
}

void set_menu_song_volume(sfRenderWindow *window)
{
    volume = on_volume_slider(window, volume);
    sfSound_setVolume(song, volume);
}

void clean_menu_song(void)
{
    sfSound_destroy(song);
}

void play_menu_song(void)
{
    if (!playing) {
        playing = 1;
        sfSound_play(song);
    } else {
        playing = 0;
        sfSound_stop(song);
    }
}
