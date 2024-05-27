/*
** EPITECH PROJECT, 2023
** create_array
** File description:
** create_array
*/
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_radar.h"

int count_lines(char *buffer)
{
    int i = 0;
    int nb_lines = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            nb_lines ++;
        i ++;
    }
    return nb_lines;
}

static int line_size(char *buffer, int *count)
{
    int i = 0;
    int x = *count;

    while (buffer[x] != '\n' && buffer[x] != '\0') {
        i ++;
        x ++;
    }
    return i;
}

static char *read_line(int *count, char *buffer)
{
    int l_size = line_size(buffer, count);
    char *str = malloc(sizeof(char) * (l_size + 1));
    int i = 0;

    while (buffer[*count] != '\n' && buffer[*count] != '\0') {
        str[i] = buffer[*count];
        i ++;
        *count = *count + 1;
    }
    str[i] = '\0';
    *count = *count + 1;
    return str;
}

static int add_line(char **res, int nb_lines, int *count, char *buffer)
{
    for (int i = 0; i < nb_lines; i ++) {
        res[i] = read_line(count, buffer);
    }
    res[nb_lines] = NULL;
    return 0;
}

char **create_array(char *buffer)
{
    int nb_lines = count_lines(buffer);
    char **res = malloc(sizeof(char *) * (nb_lines + 1));
    int count = 0;

    add_line(res, nb_lines, &count, buffer);
    return res;
}
