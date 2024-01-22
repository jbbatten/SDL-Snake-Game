#include "Game.h"
#include <SDL3/SDL.h>
#include <cstdlib>
#include <iostream>

Game::Game(GameSettings &gameSettings)
    : gameSettings(&gameSettings)
{
    // Create Screen
    // Create Snake
    screen = new Screen(gameSettings);
    snake = new Snake(gameSettings);
    food = new Food(gameSettings);

    // Add drawables to render queue on screen.
    screen->renderQueue.push_back(snake);
    screen->renderQueue.push_back(food);
}

Game::~Game()
{
    delete screen;
    delete snake;
}

void Game::Run()
{
    bool quit = false;

    // Main loop
    while (!quit)
    {
        startTime = SDL_GetTicks();

        // INPUT NEEDS TO BE REFACTORED
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT || (event.type == SDL_EVENT_KEY_DOWN) && event.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }

            if (event.type == SDL_EVENT_KEY_DOWN && event.key.keysym.sym == SDLK_UP)
            {
                snake->ChangeDirection(SnakeDirection::UP);
            };

            if (event.type == SDL_EVENT_KEY_DOWN && event.key.keysym.sym == SDLK_DOWN)
            {
                snake->ChangeDirection(SnakeDirection::DOWN);
            }

            if (event.type == SDL_EVENT_KEY_DOWN && event.key.keysym.sym == SDLK_RIGHT)
            {
                snake->ChangeDirection(SnakeDirection::RIGHT);
            }

            if (event.type == SDL_EVENT_KEY_DOWN && event.key.keysym.sym == SDLK_LEFT)
            {
                snake->ChangeDirection(SnakeDirection::LEFT);
            }
        }

        // Check Movement
        snake->Move();


        // Check Collisions
        switch (snake->CheckCollisions(food->position, gameSettings->WINDOW_WIDTH, gameSettings->WINDOW_HEIGHT))
        {
        case Collision::FoodCollision:

            snake->Eat();

            // Generate new food location
            food->position.x = (rand() % gameSettings->TOTAL_AMOUNT_OF_CELLS_X) * gameSettings->GRID_SIZE;
            food->position.y = (rand() % gameSettings->TOTAL_AMOUNT_OF_CELLS_Y) * gameSettings->GRID_SIZE;

            break;

        case Collision::BodyCollision:
            std::cout << "Body Collision" << std::endl;
            quit = true;
            break;

        case Collision::WallCollision:
            std::cout << "Wall Collision" << std::endl;
            quit = true;
            break;
            case Collision::NoCollision:
                break;
        }

        // Render
        screen->Render();

        // Cap the frame rate
        endTime = SDL_GetTicks();
        Uint32 elapsedTime = endTime - startTime;

        if (elapsedTime < gameSettings->TICKS_PER_FRAME)
        {
            SDL_Delay(gameSettings->TICKS_PER_FRAME - elapsedTime);
        }
    }
}
