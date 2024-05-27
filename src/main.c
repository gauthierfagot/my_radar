/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "control_tower.h"
#include "plane.h"
#include "key_status.h"
#include "my_radar.h"

void central_loop(sfRenderWindow *window, game_t *game, sfClock *clock)
{
    sfEvent event;
    sfSprite *background = sfSprite_create();
    sfText *time = sfText_create();
    double last_time = 0.0;
    float delta_time = 0.0;

    set_window_entities(game, time, background);
    while (sfRenderWindow_isOpen(window)) {
        update_time(time, clock, &last_time, &delta_time);
        if (analyze_events(window, &event, game, clock) == 1)
            break;
        draw_entities(window, game, background, time);
        sfRenderWindow_display(window);
        move_entities(game, &delta_time);
        analyze_collision(game);
        sfRenderWindow_clear(window, sfBlack);
    }
    destroy_window_entities(background, time);
}

int main(int argc, char **argv, char **env)
{
    game_t game;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = NULL;
    sfClock *clock = sfClock_create();

    if (env[0] == NULL || error_handling(argc, argv) == 84)
        return 84;
    if (init_variable(argv, &game) == 84)
        return 84;
    window = sfRenderWindow_create(mode, "Radar", sfResize | sfClose, NULL);
    if (!window)
        return 84;
    sfRenderWindow_setFramerateLimit(window, FRAME);
    central_loop(window, &game, clock);
    display_result(&game, clock);
    sfRenderWindow_close(window);
    destroy_variable(window, &game, clock);
    return 0;
}
