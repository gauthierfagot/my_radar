/*
** EPITECH PROJECT, 2023
** create_array_entity
** File description:
** create_array_entity
*/
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_radar.h"

static int pass_char(char *buffer, int i)
{
    while (buffer[i] == ' ' || buffer[i] == '\t')
        i ++;
    return i;
}

static int count_lines_entity(char *buffer)
{
    int i = 0;
    int nb_lines = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == ' ' || buffer[i] == '\t') {
            nb_lines ++;
            i = pass_char(buffer, i);
        } else {
            i ++;
        }
    }
    return nb_lines;
}

static int line_size_entity(char *buffer, int *count)
{
    int i = 0;
    int x = *count;

    while (buffer[x] != ' ' && buffer[x] != '\t' && buffer[x] != '\0') {
        i ++;
        x ++;
    }
    return i;
}

static char *read_line_entity(int *count, char *buffer)
{
    int l_size = line_size_entity(buffer, count);
    char *str = malloc(sizeof(char) * (l_size + 1));
    int i = 0;

    while (buffer[*count] != ' ' && buffer[*count] != '\t' && buffer[*count]
        != '\0') {
        str[i] = buffer[*count];
        i ++;
        *count = *count + 1;
    }
    str[i] = '\0';
    while (buffer[*count] == ' ' || buffer[*count] == '\t') {
        *count = *count + 1;
    }
    return str;
}

static int add_line_entity(char **res, int nb_lines, int *count, char *buffer)
{
    for (int i = 0; i < nb_lines; i ++) {
        res[i] = read_line_entity(count, buffer);
    }
    res[nb_lines] = NULL;
    return 0;
}

char **create_array_entity(char *buffer)
{
    int nb_lines = count_lines_entity(buffer) + 1;
    char **res = malloc(sizeof(char *) * (nb_lines + 1));
    int count = 0;

    add_line_entity(res, nb_lines, &count, buffer);
    return res;
}
