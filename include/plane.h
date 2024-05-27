/*
** EPITECH PROJECT, 2024
** plane
** File description:
** plane
*/

#ifndef PLANE_H_
    #define PLANE_H_

    #include <SFML/Graphics.h>
    #include "status.h"

typedef struct plane_s {
    sfSprite *sprite;
    sfRectangleShape *rect_shape;
    sfVector2f start_position;
    sfVector2f end_position;
    sfVector2f speed;
    int delay;
    status_t status;
} plane_t;

#endif /* !PLANE_H_ */
