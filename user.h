//
// Created by Nikita Kononenko on 16/04/2020.
//

#ifndef DATABASE_USER_H
#define DATABASE_USER_H

struct User {
    char login[32];
    char email[100];
    int age;
};

void print_user(struct User *user, int position);
struct User create_user(const char *login, const char *email, int age);

#endif //DATABASE_USER_H
