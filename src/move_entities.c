/*
** EPITECH PROJECT, 2023
** move_entities
** File description:
** move_entities
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "plane.h"
#include "status.h"
#include "my_radar.h"

void move_plane(plane_t *plane, float *delta_time)
{
    sfVector2f speed = {plane->speed.x * *delta_time / 1000000.0,
    plane->speed.y * *delta_time / 1000000.0};

    if (speed.x == 0 && speed.y == 0)
        plane->status = DEAD;
    sfSprite_move(plane->sprite, speed);
    sfRectangleShape_move(plane->rect_shape, speed);
}

void analyze_planes_status(game_t *game, int i)
{
    sfVector2f position = sfSprite_getPosition(game->planes[i]->sprite);
    float rotation = sfSprite_getRotation(game->planes[i]->sprite);

    if (rotation >= 90 && rotation <= 180)
        if (position.x <= game->planes[i]->end_position.x &&
        position.y >= game->planes[i]->end_position.y)
            game->planes[i]->status = DEAD;
    if (rotation <= 90 && rotation <= 180)
        if (position.x >= game->planes[i]->end_position.x &&
        position.y >= game->planes[i]->end_position.y)
            game->planes[i]->status = DEAD;
    if (rotation >= 180 && rotation >= 270)
        if (position.x >= game->planes[i]->end_position.x &&
        position.y <= game->planes[i]->end_position.y)
            game->planes[i]->status = DEAD;
    if (rotation >= 180 && rotation <= 270)
        if (position.x <= game->planes[i]->end_position.x &&
        position.y <= game->planes[i]->end_position.y)
            game->planes[i]->status = DEAD;
}

void move_entities(game_t *game, float *delta_time)
{
    for (int i = 0; game->planes[i] != NULL; i++) {
        if (game->planes[i]->status == ALIVE ||
        game->planes[i]->status == SAFE) {
            move_plane(game->planes[i], delta_time);
            analyze_planes_status(game, i);
        }
    }
}
