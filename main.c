#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "user.h"
#include "db.h"

void add_new_user(User *db, int *count) {
    char *login = (char *)malloc(32 * sizeof(char));
    char *email = (char *)malloc(100 * sizeof(char));
    int default_age = 0;
    int *age = &default_age;
    obtain_user_data(login, email, age);
    User user = create_user(login, email, *age);
    add_user(db, user, count);
    free(login);
    free(email);
}

int start_application(User *database, int *users_count) {
    while (1) {
        show_menu();
        int chosen_option = obtain_option();
        switch (chosen_option) {
            case SHOW_USERS:
                show_users_list(database, *users_count);
                break;
            case ADD_USER: {
                add_new_user(database, users_count);
                break;
            }
            case EDIT_USER: {
                int user_position = 0;
                edit_user_data(database, user_position);
                break;
            }
            case REMOVE_USER: {
                int user_position = 0;
                remove_user(database, user_position, users_count);
                break;
            }
            case EXIT: {
                free(database);
                printf("Good bye!\n");
                return 0;
            }
            default:
                printf("Sorry?\n");
                break;
        }
    }
}

int main() {
    User *database = init_database(DB_SIZE);
    int default_count = 0;
    int *users_count = &default_count;
    return start_application(database, users_count);
}
