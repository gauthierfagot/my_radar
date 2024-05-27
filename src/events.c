/*
** EPITECH PROJECT, 2023
** events
** File description:
** events
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "key_status.h"
#include "status.h"
#include "my_radar.h"

int check_end_game(game_t *game, sfClock *clock)
{
    int count = 0;

    for (int i = 0; game->planes[i] != NULL; i ++) {
        if (game->planes[i]->status == DEAD)
            count ++;
        if (game->planes[i]->status == INIT && game->planes[i]->delay <=
        (sfClock_getElapsedTime(clock)).microseconds / 1000000.0) {
            game->planes[i]->status = ALIVE;
        }
    }
    if (count == game->nb_planes)
        return 1;
    return 0;
}

void key_event(sfEvent *event, game_t *game)
{
    if (event->key.code == sfKeyL && game->key_event.key_L == ENABLE) {
        game->key_event.key_L = DISABLE;
        return;
    }
    if (event->key.code == sfKeyL && game->key_event.key_L == DISABLE) {
        game->key_event.key_L = ENABLE;
        return;
    }
    if (event->key.code == sfKeyS && game->key_event.key_S == ENABLE) {
        game->key_event.key_S = DISABLE;
        return;
    }
    if (event->key.code == sfKeyS && game->key_event.key_S == DISABLE) {
        game->key_event.key_S = ENABLE;
        return;
    }
}

int analyze_events(sfRenderWindow *window, sfEvent *event, game_t *game,
    sfClock *clock)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            return 1;
        if ((event->key.code == sfKeyL || event->key.code == sfKeyS)
        && event->key.type == sfEvtKeyPressed)
            key_event(event, game);
    }
    if (check_end_game(game, clock) == 1)
            return 1;
    return 0;
}
