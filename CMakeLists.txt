cmake_minimum_required(VERSION 3.12)

project(SnakeGame)


find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} "include")


set(SOURCES 
    "src/main.cpp"
    "src/Screen.cpp"
    "src/Snake.cpp"
)

add_executable(SnakeGame ${SOURCES})

target_link_libraries(SnakeGame ${SDL2_LIBRARIES})