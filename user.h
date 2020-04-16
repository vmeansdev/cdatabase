//
// Created by Nikita Kononenko on 16/04/2020.
//

#ifndef DATABASE_USER_H
#define DATABASE_USER_H

typedef struct {
    char login[32];
    char email[100];
    int age;
} User;

void print_user(User *user, int position);

User create_user(const char *login, const char *email, int age);

#endif //DATABASE_USER_H
