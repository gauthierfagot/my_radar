/*
** EPITECH PROJECT, 2024
** key_status
** File description:
** key_status
*/

#ifndef KEY_STATUS_H_
    #define KEY_STATUS_H_

typedef enum key_status {
    ENABLE,
    DISABLE
} key_status_t;

typedef struct key_event {
    key_status_t key_L;
    key_status_t key_S;
} key_event_t;

#endif /* !KEY_STATUS_H_ */
