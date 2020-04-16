cmake_minimum_required(VERSION 3.16)
project(database C)

set(CMAKE_C_STANDARD 99)

add_executable(database main.c menu.h menu.c user.c user.h db.c db.h)