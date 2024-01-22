cmake_minimum_required(VERSION 3.24)

project(SnakeGame)


add_subdirectory("lib/SDL")

include_directories("include" "lib/SDL/include")


set(SOURCES 
    "src/main.cpp"
    "src/Screen.cpp"
    "src/Snake.cpp"
)

add_executable(SnakeGame ${SOURCES})

target_link_libraries(SnakeGame PRIVATE SDL3::SDL3)