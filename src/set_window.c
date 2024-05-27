/*
** EPITECH PROJECT, 2024
** set_window
** File description:
** set_window
*/
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "texture.h"
#include "my_radar.h"

void update_time(sfText *time, sfClock *clock, double *last_time,
    float *delta_time)
{
    *delta_time = (sfClock_getElapsedTime(clock)).microseconds -
        *last_time;
    *last_time = (sfClock_getElapsedTime(clock)).microseconds;
    sfText_setString(time,
    int_to_str(sfClock_getElapsedTime(clock).microseconds / 1000000));
}

void set_window_entities(game_t *game, sfText *time, sfSprite *background)
{
    sfVector2f time_position = {1850.0, 30.0};
    sfFont *font = sfFont_createFromFile(FONT);

    sfSprite_setTexture(background, game->textures[BACKGROUND], sfTrue);
    sfText_setPosition(time, time_position);
    sfText_setFont(time, font);
    sfText_setColor(time, sfWhite);
}
