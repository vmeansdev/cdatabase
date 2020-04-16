//
// Created by Nikita Kononenko on 16/04/2020.
//

#include <stdio.h>
#include "menu.h"

void display_list(char **list, size_t list_size);

void show_menu() {
    const size_t arr_length = 5;
    char *options[arr_length] = {
            "Show users list",
            "Add new user",
            "Edit user data",
            "Remove user",
            "Exit"
    };
    display_list(options, arr_length);
}

int obtain_option() {
    int option;
    printf("Choose menu option: ");
    scanf("%d", &option);
    return option;
}

void display_list(char **list, const size_t list_size) {
    printf("\n");
    for (int i = 0; i < list_size; i++) {
        char *item = list[i];
        int position = i + 1;
        printf("%d. %s\n", position, item);
    }
}