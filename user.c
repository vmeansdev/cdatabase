//
// Created by Nikita Kononenko on 16/04/2020.
//

#include <stdio.h>
#include <string.h>
#include "user.h"

void print_user(struct User *user, int position) {
    printf("%d. User { login = %s, email = %s, age = %d }\n", position, user->login, user->email, user->age);
}

struct User create_user(const char *login, const char *email, int age) {
    struct User new_user;
    strcpy(new_user.login, login);
    strcpy(new_user.email, email);
    new_user.age = age;

    return new_user;
}
