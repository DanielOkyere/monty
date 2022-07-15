cmake_minimum_required(VERSION 3.22)
project(monty C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(monty ./tests/000.m)
