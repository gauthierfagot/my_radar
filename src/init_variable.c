/*
** EPITECH PROJECT, 2023
** initialisation_varaible
** File description:
** initialisation_variable
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "control_tower.h"
#include "plane.h"
#include "entities_info.h"
#include "texture.h"
#include "array_texture.h"
#include "key_status.h"
#include "status.h"
#include "my_radar.h"

static control_tower_t *init_tower(game_t *game, char **array_entity)
{
    control_tower_t *control_tower = malloc(sizeof(control_tower_t));

    control_tower->sprite = sfSprite_create();
    control_tower->circle_shape = sfCircleShape_create();
    control_tower->position.x = str_to_int(array_entity[POSITION_X]);
    control_tower->position.y = str_to_int(array_entity[POSITION_Y]);
    control_tower->radius = str_to_int(array_entity[RADIUS]) * WIDTH / 100;
    set_tower_sprite(game, control_tower);
    set_tower_circle_shape(control_tower);
    return control_tower;
}

static sfVector2f compute_speed(plane_t *plane, char **array_entity)
{
    sfVector2f speed = {0, 0};
    float vector_x = plane->end_position.x - plane->start_position.x;
    float vector_y = plane->end_position.y - plane->start_position.y;
    float u_value = sqrtf(pow(vector_x, 2.0) + pow(vector_y, 2.0));

    if (u_value == 0)
        return speed;
    speed.x = vector_x / u_value * str_to_int(array_entity[SPEED]);
    speed.y = vector_y / u_value * str_to_int(array_entity[SPEED]);
    return speed;
}

static plane_t *init_plane(game_t *game, char **array_entity)
{
    plane_t *plane = malloc(sizeof(plane_t));

    plane->sprite = sfSprite_create();
    plane->rect_shape = sfRectangleShape_create();
    plane->start_position.x = str_to_int(array_entity[START_POSITION_X]);
    plane->start_position.y = str_to_int(array_entity[START_POSITION_Y]);
    plane->end_position.x = str_to_int(array_entity[END_POSITION_X]);
    plane->end_position.y = str_to_int(array_entity[END_POSITION_Y]);
    plane->speed = compute_speed(plane, array_entity);
    plane->delay = str_to_int(array_entity[DELAY]);
    plane->status = INIT;
    set_plane_sprite(game, plane);
    set_plane_rect_shape(plane);
    return plane;
}

static int array_len(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        i ++;
    }
    return i;
}

static int check_entity(char **array_entity)
{
    if (array_entity[0][0] != 'A' && array_entity[0][0] != 'T')
        return 84;
    if (array_entity[0][0] == 'A') {
        if (array_len(array_entity) != 7)
            return 84;
    }
    if (array_entity[0][0] == 'T') {
        if (array_len(array_entity) != 4)
            return 84;
    }
    return 0;
}

int init_entities(game_t *game, char **array_entities)
{
    int nb_planes = 0;
    int nb_towers = 0;
    char **array_entity = NULL;

    for (int i = 0; array_entities[i] != NULL; i ++) {
        array_entity = create_array_entity(array_entities[i]);
        if (check_entity(array_entity) == 84)
            return 84;
        if (array_entity[PLANE_TYPE][0] == 'A') {
            game->planes[nb_planes] = init_plane(game, array_entity);
            nb_planes ++;
        }
        if (array_entity[TOWER_TYPE][0] == 'T') {
            game->control_towers[nb_towers] = init_tower(game, array_entity);
            nb_towers ++;
        }
        free_array(array_entity);
    }
    return 0;
}

static int create_game(game_t *game, int nb_planes, int nb_towers)
{
    key_event_t key_event = {ENABLE, ENABLE};

    game->planes = NULL;
    game->control_towers = NULL;
    game->textures = malloc(sizeof(sfTexture *) * ARRAY_TEXTURE_SIZE);
    for (int i = 0; i < ARRAY_TEXTURE_SIZE; i ++) {
        game->textures[i] = sfTexture_createFromFile(ARRAY_TEXTURE[i], NULL);
        if (game->textures[i] == NULL)
            return 84;
    }
    game->key_event = key_event;
    game->nb_crashed_planes = 0;
    game->nb_planes = nb_planes;
    game->nb_towers = nb_towers;
    return 0;
}

int init_game(game_t *game, char **array_entities)
{
    int nb_planes = 0;
    int nb_towers = 0;

    for (int i = 0; array_entities[i] != NULL; i ++) {
        if (array_entities[i][PLANE_TYPE] == 'A')
            nb_planes ++;
        if (array_entities[i][TOWER_TYPE] == 'T')
            nb_towers ++;
    }
    if (create_game(game, nb_planes, nb_towers) == 84 || nb_planes == 0)
        return 84;
    return 0;
}

int init_variable(char **argv, game_t *game)
{
    char *buffer = NULL;
    char **array_entities = NULL;

    buffer = read_buffer(argv[1]);
    if (buffer == NULL)
        return 84;
    array_entities = create_array(buffer);
    if (init_game(game, array_entities) == 84)
        return 84;
    game->planes = malloc(sizeof(plane_t *) * (game->nb_planes + 1));
    game->control_towers = malloc(sizeof(control_tower_t *) *
        (game->nb_towers + 1));
    if (init_entities(game, array_entities) == 84)
        return 84;
    game->planes[game->nb_planes] = NULL;
    game->control_towers[game->nb_towers] = NULL;
    free(buffer);
    free_array(array_entities);
    return 0;
}
