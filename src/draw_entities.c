/*
** EPITECH PROJECT, 2023
** draw_entities
** File description:
** draw_entities
*/
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include "key_status.h"
#include "status.h"
#include "my_radar.h"

void draw_control_towers(sfRenderWindow *window, game_t *game, int i)
{
    if (game->key_event.key_S == ENABLE)
        sfRenderWindow_drawSprite(window,
        game->control_towers[i]->sprite, NULL);
    if (game->key_event.key_L == ENABLE)
        sfRenderWindow_drawCircleShape(window,
        game->control_towers[i]->circle_shape, NULL);
}

void draw_planes(sfRenderWindow *window, game_t *game, int i)
{
    if (game->planes[i]->status == ALIVE || game->planes[i]->status == SAFE) {
        if (game->key_event.key_S == ENABLE)
            sfRenderWindow_drawSprite(window, game->planes[i]->sprite, NULL);
        if (game->key_event.key_L == ENABLE)
            sfRenderWindow_drawRectangleShape(window,
            game->planes[i]->rect_shape, NULL);
    }
}

void draw_entities(sfRenderWindow *window, game_t *game, sfSprite *background,
    sfText *time)
{
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawText(window, time, NULL);
    for (int i = 0; game->control_towers[i] != NULL; i ++) {
        draw_control_towers(window, game, i);
    }
    for (int i = 0; game->planes[i] != NULL; i ++) {
        draw_planes(window, game, i);
    }
}
