/*
** EPITECH PROJECT, 2023
** free_variable
** File description:
** free_variable
*/
#include <stddef.h>
#include <stdlib.h>
#include "plane.h"
#include "control_tower.h"
#include "texture.h"
#include "my_radar.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i ++) {
        free(array[i]);
    }
    free(array);
}

static void destroy_planes(plane_t **planes)
{
    for (int i = 0; planes[i] != NULL; i ++) {
        sfSprite_destroy(planes[i]->sprite);
        sfRectangleShape_destroy(planes[i]->rect_shape);
    }
}

static void destroy_control_towers(control_tower_t **control_towers)
{
    for (int i = 0; control_towers[i] != NULL; i ++) {
        sfSprite_destroy(control_towers[i]->sprite);
        sfCircleShape_destroy(control_towers[i]->circle_shape);
    }
}

static void free_planes(plane_t **planes)
{
    for (int i = 0; planes[i] != NULL; i ++) {
        free(planes[i]);
    }
    free(planes);
}

static void free_control_towers(control_tower_t **control_towers)
{
    for (int i = 0; control_towers[i] != NULL; i ++) {
        free(control_towers[i]);
    }
    free(control_towers);
}

static void destroy_texture(game_t *game)
{
    for (int i = 0; i < ARRAY_TEXTURE_SIZE; i ++) {
        sfTexture_destroy(game->textures[i]);
    }
    free(game->textures);
}

void destroy_window_entities(sfSprite *background, sfText *time)
{
    sfText_destroy(time);
    sfSprite_destroy(background);
}

void destroy_variable(sfRenderWindow *window, game_t *game, sfClock *clock)
{
    sfRenderWindow_destroy(window);
    destroy_planes(game->planes);
    destroy_control_towers(game->control_towers);
    destroy_texture(game);
    free_planes(game->planes);
    free_control_towers(game->control_towers);
    sfClock_destroy(clock);
}
