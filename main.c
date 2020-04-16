#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database constants

const size_t DB_SIZE = 64;

// Define `User` structure

struct User {
    char login[32];
    char email[100];
    int age;
};

// Declare User related functions

void print_user(struct User *user, int position);
struct User create_user(const char *login, const char *email, int age);

// Define `MenuOptions` enum

enum MenuOptions {
    SHOW_USERS = 1,
    ADD_USER,
    EDIT_USER,
    REMOVE_USER,
    SHOW_MENU
};

// Declare UI related functions

void show_menu();
int obtain_option();

// Declare database related functions
void show_users_list(struct User *db, int users_count);
void obtain_user_data(char *login, char *email, int *age);
void add_user(struct User *db, struct User user, int *count);
void edit_user_data(struct User *db, int position);
void remove_user(struct User *db, int position, int *count);

// Declare helper functions

void display_list(char **list, size_t list_size);

// Entry point

int main() {
    struct User *database = (struct User *)malloc(DB_SIZE * sizeof(struct User));
    int default_count = 0;
    int *users_count = &default_count;
    while (1) {
        show_menu();
        int chosen_option = obtain_option();
        switch (chosen_option) {
            case SHOW_USERS:
                show_users_list(database, *users_count);
                break;
            case ADD_USER: {
                char *login = (char *)malloc(32 * sizeof(char));
                char *email = (char *)malloc(100 * sizeof(char));
                int default_age = 0;
                int *age = &default_age;
                obtain_user_data(login, email, age);
                struct User user = create_user(login, email, *age);
                add_user(database, user, users_count);
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
            case SHOW_MENU:
                break;
            default:
                printf("No such option. Good bye!\n");
                return 0;
        }
    }
}

// UI related functions implementation

void show_menu() {
    const size_t arr_length = 5;
    char *options[arr_length] = {
            "Show users list",
            "Add new user",
            "Edit user data",
            "Remove user",
            "Show menu"
    };
    display_list(options, arr_length);
}

int obtain_option() {
    int option;
    printf("Choose menu option: ");
    scanf("%d", &option);
    return option;
}

// Database related functions implementation

void show_users_list(struct User *db, int users_count) {
    if (users_count == 0) {
        printf("There are no any users.\n");
        return;
    }
    for (int i = 0; i < users_count; i++) {
        struct User *user = &db[i];
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

void add_user(struct User *db, struct User user, int *count) {
    if (*count >= (int)DB_SIZE) {
        printf("Database is full");
        return;
    }
    db[*count] = user;
    *count += 1;
}

void edit_user_data(struct User *db, int position) {
    if (position >= DB_SIZE) {
        printf("Incorrect position");
        return;
    }
    struct User *user = &db[position];
    if (user == NULL) {
        printf("There is no user at the given position %d", position);
        return;
    }
    // TODO: Edit user's data here
}

void remove_user(struct User *db, int position, int *count) {
    if (position >= DB_SIZE) {
        printf("Incorrect position");
        return;
    }
    struct User *user = &db[position];
    if (user == NULL) {
        printf("There is no user at the given position %d", position);
        return;
    }
    // TODO: Remove user at the given position
}

// User related functions implementation

struct User create_user(const char *login, const char *email, int age) {
    struct User new_user;
    strcpy(new_user.login, login);
    strcpy(new_user.email, email);
    new_user.age = age;

    return new_user;
}

void print_user(struct User *user, int position) {
    printf("%d. User { login = %s, email = %s, age = %d }\n", position, user->login, user->email, user->age);
}

// Helper functions implementation

void display_list(char **list, const size_t list_size) {
    printf("\n");
    for (int i = 0; i < list_size; i++) {
        char *item = list[i];
        int position = i + 1;
        printf("%d. %s\n", position, item);
    }
}