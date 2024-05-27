/*
** EPITECH PROJECT, 2023
** set_entities
** File description:
** set_entities
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "control_tower.h"
#include "plane.h"
#include "texture.h"
#include "my_radar.h"

void set_tower_circle_shape(control_tower_t *control_tower)
{
    sfVector2f position_circle = {0, 0};

    position_circle.x = control_tower->position.x - control_tower->radius +
        WIDTH_TOWER * 0.5;
    position_circle.y = control_tower->position.y - control_tower->radius +
        HEIGHT_TOWER * 0.5;
    sfCircleShape_setPosition(control_tower->circle_shape, position_circle);
    sfCircleShape_setFillColor(control_tower->circle_shape, sfTransparent);
    sfCircleShape_setOutlineColor(control_tower->circle_shape, sfWhite);
    sfCircleShape_setOutlineThickness(control_tower->circle_shape, 1.0);
    sfCircleShape_setRadius(control_tower->circle_shape,
        control_tower->radius);
}

void set_tower_sprite(game_t *game, control_tower_t *control_tower)
{
    sfVector2u size_texture = sfTexture_getSize(game->textures[TOWER]);
    sfVector2f scale = {WIDTH_TOWER / size_texture.x,
        HEIGHT_TOWER / size_texture.y};

    sfSprite_setTexture(control_tower->sprite, game->textures[TOWER], sfTrue);
    sfSprite_setPosition(control_tower->sprite, control_tower->position);
    sfSprite_setScale(control_tower->sprite, scale);
}

float compute_angle(plane_t *plane)
{
    float angle = 0.0;
    float vector_x = plane->end_position.x - plane->start_position.x;
    float vector_y = plane->end_position.y - plane->start_position.y;
    float u_value = sqrtf(pow(vector_x, 2.0) + pow(vector_y, 2.0));
    float v_value = 1.0;
    float scalar_product = (vector_x * 1.0) + (vector_y * 0.0);

    if (u_value == 0)
        return 0;
    angle = acos(scalar_product / (u_value * v_value)) * 180 / M_PI;
    if (vector_y < 0)
        angle = 360.0 - angle;
    return angle;
}

void set_plane_rect_shape(plane_t *plane)
{
    sfVector2f position = {plane->start_position.x, plane->start_position.y};
    sfVector2f size_rect = {WIDTH_PLANE, HEIGHT_PLANE};
    float angle = compute_angle(plane);

    sfRectangleShape_setPosition(plane->rect_shape, position);
    sfRectangleShape_setFillColor(plane->rect_shape, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->rect_shape, sfWhite);
    sfRectangleShape_setOutlineThickness(plane->rect_shape, 1.0);
    sfRectangleShape_setSize(plane->rect_shape, size_rect);
    sfRectangleShape_setRotation(plane->rect_shape, angle);
}

void set_plane_sprite(game_t *game, plane_t *plane)
{
    sfVector2f position = {plane->start_position.x, plane->start_position.y};
    sfVector2u size_texture = sfTexture_getSize(game->textures[PLANE]);
    sfVector2f scale = {WIDTH_PLANE / size_texture.x,
        HEIGHT_PLANE / size_texture.y};
    float angle = compute_angle(plane);

    sfSprite_setTexture(plane->sprite, game->textures[PLANE], sfTrue);
    sfSprite_setPosition(plane->sprite, position);
    sfSprite_setScale(plane->sprite, scale);
    sfSprite_setRotation(plane->sprite, angle);
}
