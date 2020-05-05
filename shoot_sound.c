/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Menu sound function
*/

#include "include/function.h"

static sfSound *sound;
static float volume = 100.0;

void load_shoot_sound(void)
{
    sfSoundBuffer *soundBuffer;

    sound = sfSound_create();
    soundBuffer = sfSoundBuffer_createFromFile("res/shoot.wav");
    sfSound_setBuffer(sound, soundBuffer);
}

void set_shoot_sound_volume(sfRenderWindow *window)
{
    volume = on_volume_slider(window, volume);
    sfSound_setVolume(sound, volume);
}

void clean_shoot_sound(void)
{
    sfSound_destroy(sound);
}

void play_shoot_sound(void)
{
    sfSound_play(sound);
}
