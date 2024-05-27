/*
** EPITECH PROJECT, 2023
** towers_collision.c
** File description:
** towers_collision.c
*/
#include <math.h>
#include "control_tower.h"
#include "plane.h"
#include "square.h"
#include "status.h"
#include "my_radar.h"

static int check_inside_circle(sfVector2f *point, control_tower_t *tower)
{
    float distance = 0.0;
    sfVector2f center = {tower->position.x,
                        tower->position.y};

    distance = sqrtf(pow(point->x - center.x, 2.0) +
    pow(point->y - center.y, 2.0));
    if (distance < tower->radius)
        return 1;
    return 0;
}

static int is_inside_circle(square_t *square, control_tower_t *tower)
{
    if (check_inside_circle(&square->top_left, tower) == 1 ||
    check_inside_circle(&square->top_right, tower) == 1 ||
    check_inside_circle(&square->bottom_left, tower) == 1 ||
    check_inside_circle(&square->bottom_right, tower) == 1)
        return 1;
    return 0;
}

int is_intersecting_circles(plane_t *plane, control_tower_t *tower)
{
    square_t square = create_square(plane);

    if (is_inside_circle(&square, tower) == 1)
        return 1;
    return 0;
}

void check_safe_place(game_t *game, int i)
{
    for (int j = 0; game->control_towers[j] != NULL; j++) {
        if (game->planes[i]->status == SAFE &&
        is_intersecting_circles(game->planes[i],
        game->control_towers[j]) == 0) {
            game->planes[i]->status = ALIVE;
            return;
        }
        if (game->planes[i]->status == ALIVE &&
        is_intersecting_circles(game->planes[i],
        game->control_towers[j]) == 1) {
            game->planes[i]->status = SAFE;
            return;
        }
    }
}
