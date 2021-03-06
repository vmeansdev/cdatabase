//
// Created by Nikita Kononenko on 16/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "db.h"

User* init_database(size_t size) {
    return (User *)malloc(size * sizeof(User));
}

void show_users_list(User *db, int users_count) {
    if (users_count == 0) {
        printf("There are no any users.\n");
        return;
    }
    for (int i = 0; i < users_count; i++) {
        User *user = &db[i];
        print_user(user, i + 1);
    }
}

void obtain_user_data(char *login, char *email, int *age) {
    printf("Enter user login: ");
    scanf("%s", login);
    printf("Enter user email: ");
    scanf("%s", email);
    printf("Enter user age: ");
    scanf("%d", age);
}

void add_user(User *db, User user, int *count) {
    if (*count >= DB_SIZE) {
        printf("Sorry. Database is full.");
        return;
    }
    db[*count] = user;
    *count += 1;
}

void edit_user_data(User *db, int position) {
    if (position >= DB_SIZE) {
        printf("Incorrect position");
        return;
    }
    User *user = &db[position];
    if (user == NULL) {
        printf("There is no user at the given position %d", position);
        return;
    }
    // TODO: Edit user's data here
}

void remove_user(User *db, int position, int *count) {
    if (position >= DB_SIZE) {
        printf("Incorrect position");
        return;
    }
    User *user = &db[position];
    if (user == NULL) {
        printf("There is no user at the given position %d", position);
        return;
    }
    // TODO: Remove user at the given position
}