/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** my_radar
*/

#ifndef MY_RADAR_
    #define MY_RADAR_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include "plane.h"
    #include "control_tower.h"
    #include "key_status.h"
    #include "status.h"
    #include "square.h"

    #define WIDTH 1920
    #define HEIGHT 1080
    #define FRAME 30

    #define FONT "font/text.ttf"

    #define WIDTH_PLANE 20.0
    #define HEIGHT_PLANE 20.0

    #define WIDTH_TOWER 50.0
    #define HEIGHT_TOWER 50.0

typedef struct game_s {
    plane_t **planes;
    control_tower_t **control_towers;
    sfTexture **textures;
    key_event_t key_event;
    int nb_crashed_planes;
    int nb_planes;
    int nb_towers;
} game_t;

int str_to_int(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *int_to_str(int nb);

int error_handling(int argc, char **argv);
void display_result(game_t *game, sfClock *clock);

char *read_buffer(char *filepath);
char **create_array(char *buffer);
char **create_array_entity(char *buffer);
int count_lines(char *buffer);
int init_variable(char **argv, game_t *game);

void set_tower_sprite(game_t *game, control_tower_t *control_tower);
void set_tower_circle_shape(control_tower_t *control_tower);
void set_plane_sprite(game_t *game, plane_t *plane);
void set_plane_rect_shape(plane_t *plane);
void set_window_entities(game_t *game, sfText *time, sfSprite *background);

void update_time(sfText *time, sfClock *clock, double *last_time,
    float *delta_time);
int analyze_events(sfRenderWindow *window, sfEvent *event, game_t *game,
    sfClock *clock);
void move_entities(game_t *game, float *delta_time);
void draw_entities(sfRenderWindow *window, game_t *game, sfSprite *background,
    sfText *time);

void analyze_collision(game_t *game);
square_t create_square(plane_t *plane);
void check_collision(game_t *game, int i);
void check_safe_place(game_t *game, int i);

void free_array(char **array);
void destroy_window_entities(sfSprite *background, sfText *time);
void destroy_variable(sfRenderWindow *window, game_t *game, sfClock *clock);

float compute_angle(plane_t *plane);

#endif /* !MY_RADAR_ */
