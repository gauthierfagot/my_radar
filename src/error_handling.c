/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** error_handling
*/
#include <stdio.h>
#include <stdlib.h>
#include "my_radar.h"

int info_error(void)
{
    my_putstr("./my_radar: bad arguments: 0 given but 84 is required\n");
    my_putstr("retry with -h\n");
    return 84;
}

int info_help(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("\t./my_radar [OPTIONS] path_to_script\n");
    my_putstr("\tpath_to_script\tThe path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("\t-h\tprint the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\t'L' key\tenable/disable hitboxes and areas.\n");
    my_putstr("\t's' key\tenable/disable sprites.\n");
    return 0;
}

void display_result(game_t *game, sfClock *clock)
{
    int nb_landed_planes = game->nb_planes - game->nb_crashed_planes;
    int percent_crashed_planes = game->nb_crashed_planes * 100 /
        game->nb_planes;
    int percent_landed_planes = nb_landed_planes * 100 / game->nb_planes;

    my_putstr("\nSummary\n------------------------------\nTime:\t");
    my_putstr(int_to_str(sfClock_getElapsedTime(clock).microseconds /
        1000000));
    my_putstr("s\n------------------------------\nLanded planes:\t");
    my_putstr(int_to_str(nb_landed_planes));
    my_putstr("\n\t\t");
    my_putstr(int_to_str(percent_landed_planes));
    my_putstr("%\n------------------------------\nCrashed planes:\t");
    my_putstr(int_to_str(game->nb_crashed_planes));
    my_putstr("\n\t\t");
    my_putstr(int_to_str(percent_crashed_planes));
    my_putstr("%\n------------------------------\nTotal planes:\t");
    my_putstr(int_to_str(game->nb_planes));
    my_putstr("\n------------------------------\n\n");
}

int error_handling(int argc, char **argv)
{
    if (argc == 1)
        return info_error();
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        return info_help();
    if (argc >= 3)
        return 84;
    return 0;
}
