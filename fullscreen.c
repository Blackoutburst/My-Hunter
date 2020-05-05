/*
** EPITECH PROJECT, 2019
** My Hunter
** File description:
** Switch fullscreen (should work on macOS)
*/

#include "include/function.h"

static int fullscreen = 0;
static const sfVideoMode mode = {1280, 720, 32};

void restore_parrameter(sfRenderWindow *window)
{
    sfImage *icon = sfImage_createFromFile ("res/icon.png");
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setIcon(window, 64, 64, sfImage_getPixelsPtr(icon));
    sfRenderWindow_setFramerateLimit(window, 60);
}

int toggle_fullscreen(sfRenderWindow *window)
{
    sfVideoMode size_mode = sfVideoMode_getDesktopMode();
    sfVector2u size = {0, 0};
    sfVector2i origin = {0, 0};
    size.x = size_mode.width;
    size.y = size_mode.height;
    char *name = "Magical Hunt";

    sfRenderWindow_destroy(window);
    if (!fullscreen) {
        window = sfRenderWindow_create(mode, name, 16, NULL);
        restore_parrameter(window);
        sfRenderWindow_setSize(window, size);
        sfRenderWindow_setPosition(window, origin);
        fullscreen = 1;
    } else {
        window = sfRenderWindow_create(mode, name, sfDefaultStyle, NULL);
        restore_parrameter(window);
        fullscreen = 0;
    }
    return (fullscreen);
}
