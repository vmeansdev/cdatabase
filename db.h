//
// Created by Nikita Kononenko on 16/04/2020.
//

#ifndef DATABASE_DB_H
#define DATABASE_DB_H

static const size_t DB_SIZE = 64;

struct User;

void show_users_list(struct User *db, int users_count);

void obtain_user_data(char *login, char *email, int *age);

void add_user(struct User *db, struct User user, int *count);

void edit_user_data(struct User *db, int position);

void remove_user(struct User *db, int position, int *count);

#endif //DATABASE_DB_H
