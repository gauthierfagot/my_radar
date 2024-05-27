/*
** EPITECH PROJECT, 2024
** square
** File description:
** square
*/

#ifndef SQUARE_H_
    #define SQUARE_H_

    #include <SFML/Graphics.h>

typedef struct square_s {
    sfVector2f top_left;
    sfVector2f top_right;
    sfVector2f bottom_left;
    sfVector2f bottom_right;
    sfVector2f center;
    float angle;
} square_t;

#endif /* !SQUARE_H_ */
