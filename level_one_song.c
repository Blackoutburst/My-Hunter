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

void load_level_one_song(void)
{
    sfSoundBuffer *soundBuffer;

    song = sfSound_create();
    soundBuffer = sfSoundBuffer_createFromFile("res/level_one.wav");
    sfSound_setBuffer(song, soundBuffer);
}

void set_level_one_song_volume(sfRenderWindow *window)
{
    volume = on_volume_slider(window, volume);
    sfSound_setVolume(song, volume);
}

void clean_level_one_song(void)
{
    sfSound_destroy(song);
}

void loop_level_one_song(void)
{
    int offset = sfTime_asMilliseconds(sfSound_getPlayingOffset(song));
    sfTime begin = sfMilliseconds(90800);
    sfTime end = sfMilliseconds(175400);
    if (offset > sfTime_asMilliseconds(end))
        sfSound_setPlayingOffset(song, begin);
}

void play_level_one_song(void)
{
    if (!playing) {
        playing = 1;
        sfSound_play(song);
    } else {
        playing = 0;
        sfSound_stop(song);
    }
}
