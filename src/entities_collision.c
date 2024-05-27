/*
** EPITECH PROJECT, 2023
** planes_collision
** File description:
** planes_collision
*/
#include <math.h>
#include "square.h"
#include "my_radar.h"

square_t create_square(plane_t *plane)
{
    sfVector2f top_left = sfRectangleShape_getPosition(plane->rect_shape);
    float angle = compute_angle(plane);
    sfVector2f vect = {cos(angle * M_PI / 180.0), sin(angle * M_PI / 180.0)};
    sfVector2f top_right = {top_left.x + WIDTH_PLANE * vect.x,
    top_left.y + HEIGHT_PLANE * vect.y};
    sfVector2f bottom_left = {top_left.x - WIDTH_PLANE * vect.y,
    top_left.y + HEIGHT_PLANE * vect.x};
    sfVector2f bottom_right = {top_left.x + WIDTH_PLANE * vect.x -
    WIDTH_PLANE * vect.y,
    top_left.y + HEIGHT_PLANE * vect.y + HEIGHT_PLANE * vect.x};
    sfVector2f center = {(top_left.x + bottom_right.x) / 2,
    (top_right.y + bottom_left.y) / 2};
    square_t square = {top_left, top_right, bottom_left, bottom_right,
    center, angle};

    return square;
}

void analyze_collision(game_t *game)
{
    for (int i = 0; game->planes[i] != NULL; i ++) {
        check_safe_place(game, i);
        if (game->planes[i]->status == ALIVE)
            check_collision(game, i);
    }
}
