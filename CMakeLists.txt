cmake_minimum_required(VERSION 3.9)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

include_directories(
        libftprintf/libft/includes
        libftprintf/includes
        includes
)

link_directories(libftprintf)
link_libraries(ftprintf)

set(HEADERS
        includes/lem_in.h
        )

set(SOURCES
        sources/main.c
        )

add_executable(lem_in ${SOURCES} ${HEADERS})