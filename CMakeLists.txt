cmake_minimum_required(VERSION 3.24)

project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

add_subdirectory("lib/SDL")

include_directories("include" "lib/SDL/include" "lib/SDL_ttf/include" "lib/SDL_image/include")


set(SOURCES
        "src/main.cpp"
        "src/GameSettings.cpp"
        "src/Game.cpp"
        "src/Screen.cpp"
        "src/Snake.cpp"
        "src/Food.cpp"
)

add_executable(SnakeGame ${SOURCES})

target_link_libraries(SnakeGame PRIVATE SDL3::SDL3)