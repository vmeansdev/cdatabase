//
// Created by Nikita Kononenko on 16/04/2020.
//

#ifndef DATABASE_MENU_H
#define DATABASE_MENU_H

typedef enum MenuOptions {
    SHOW_USERS = 1,
    ADD_USER,
    EDIT_USER,
    REMOVE_USER,
    EXIT
} MenuOptions;

void show_menu();

int obtain_option();

#endif //DATABASE_MENU_H
