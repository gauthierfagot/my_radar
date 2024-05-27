/*
** EPITECH PROJECT, 2023
** planes_collision
** File description:
** planes_collision
*/
#include <math.h>
#include "square.h"
#include "plane.h"
#include "status.h"
#include "my_radar.h"

static int check_inside_square(sfVector2f *point, sfVector2f *center)
{
    float distance = 0.0;

    distance = sqrtf(pow(point->x - center->x, 2.0) +
    pow(point->y - center->y, 2.0));
    if (distance < (WIDTH_PLANE * sqrtf(2.0)) / 2)
        return 1;
    return 0;
}

int is_intersecting_planes(plane_t *plane1, plane_t *plane2)
{
    square_t square1 = create_square(plane1);
    square_t square2 = create_square(plane2);

    if (check_inside_square(&square1.top_left, &square2.center) == 1 ||
    check_inside_square(&square1.top_right, &square2.center) == 1 ||
    check_inside_square(&square1.bottom_left, &square2.center) == 1 ||
    check_inside_square(&square1.bottom_right, &square2.center) == 1 ||
    check_inside_square(&square2.top_left, &square1.center) == 1 ||
    check_inside_square(&square2.top_right, &square1.center) == 1 ||
    check_inside_square(&square2.bottom_left, &square1.center) == 1 ||
    check_inside_square(&square2.bottom_right, &square1.center) == 1)
        return 1;
    return 0;
}

void check_collision(game_t *game, int i)
{
    for (int j = 0; game->planes[j] != NULL; j++) {
        check_safe_place(game, j);
        if (i != j && game->planes[j]->status == ALIVE &&
        is_intersecting_planes(game->planes[i], game->planes[j]) == 1) {
            game->planes[i]->status = DEAD;
            game->planes[j]->status = DEAD;
            game->nb_crashed_planes += 2;
            return;
        }
    }
}
