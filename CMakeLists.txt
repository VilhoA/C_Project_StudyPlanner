cmake_minimum_required(VERSION 4.1)
project(C_Project_StudyPlanner C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_Project_StudyPlanner
        main.c
        schedule.c
        utils.c)
