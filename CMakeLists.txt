cmake_minimum_required(VERSION 3.29)
project(Revisao C)

set(CMAKE_C_STANDARD 99)

add_executable(Revisao main.c
        implementations/list.c
        interfaces/list.h
        interfaces/stack_vector.h
        implementations/stack_vector.c
        interfaces/stack.h
        implementations/stack.c
        interfaces/queue.h
        implementations/queue_vector.c
        interfaces/queue_vector.h
        implementations/queue.c)
