/*
** EPITECH PROJECT, 2024
** control_tower
** File description:
** control_tower
*/

#ifndef CONTROL_TOWWER_H_
    #define CONTROL_TOWWER_H_

    #include <SFML/Graphics.h>

typedef struct control_tower_s {
    sfSprite *sprite;
    sfCircleShape *circle_shape;
    sfVector2f position;
    int radius;
} control_tower_t;

#endif /* !CONTROL_TOWWER_H_ */
