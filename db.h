//
// Created by Nikita Kononenko on 16/04/2020.
//

#ifndef DATABASE_DB_H
#define DATABASE_DB_H

#include "user.h"

static const size_t DB_SIZE = 64;

User* init_database(size_t size);

void show_users_list(User *db, int users_count);

void obtain_user_data(char *login, char *email, int *age);

void add_user(User *db, User user, int *count);

void edit_user_data(User *db, int position);

void remove_user(User *db, int position, int *count);

#endif //DATABASE_DB_H
