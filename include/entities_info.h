/*
** EPITECH PROJECT, 2024
** entities_info
** File description:
** entities_info
*/

#ifndef ENTITIES_INFO_H_
    #define ENTITIES_INFO_H_

typedef enum plane_info {
    PLANE_TYPE,
    START_POSITION_X,
    START_POSITION_Y,
    END_POSITION_X,
    END_POSITION_Y,
    SPEED,
    DELAY
} plane_info_t;

typedef enum control_tower_info {
    TOWER_TYPE,
    POSITION_X,
    POSITION_Y,
    RADIUS
} control_tower_info_t;

#endif /* !ENTITIES_INFO_H_ */
