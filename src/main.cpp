#include <iostream>
#include <SDL3/SDL.h>
#include <Screen.h>


const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 400;
const int GRID_SIZE = 20;
const int FPS = 10;
const int TICKS_PER_FRAME = 1000 / FPS;
const int TOTAL_AMOUNT_OF_CELLS_X = WINDOW_WIDTH / GRID_SIZE;
const int TOTAL_AMOUNT_OF_CELLS_Y = WINDOW_HEIGHT / GRID_SIZE;

int main()
{
    Screen screen(WINDOW_WIDTH, WINDOW_HEIGHT, GRID_SIZE);

    Uint32 startTime = 0;
    Uint32 endTime = 0;

    bool quit = false;

    // Workout starting position of head.
    SDL_Point startingHeadPos;
    startingHeadPos.x = (TOTAL_AMOUNT_OF_CELLS_X / 2) * GRID_SIZE;
    startingHeadPos.y = (TOTAL_AMOUNT_OF_CELLS_Y / 2) * GRID_SIZE;

    // Create Snake.
    Snake snake(startingHeadPos, GRID_SIZE);

    // Workout position of new food.
    SDL_Point food;
    food.x = (rand() % TOTAL_AMOUNT_OF_CELLS_X) * GRID_SIZE;
    food.y = (rand() % TOTAL_AMOUNT_OF_CELLS_Y) * GRID_SIZE;

    // Main loop
    while (!quit)
    {
        startTime = SDL_GetTicks();

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT || (event.type == SDL_EVENT_KEY_DOWN) && event.key.keysym.sym == SDLK_ESCAPE)
            {
                quit = true;
            }

            if (event.type == SDL_EVENT_KEY_DOWN && event.key.keysym.sym == SDLK_UP)
            {
                snake.ChangeDirection(SnakeDirection::UP);
            };

            if (event.type == SDL_EVENT_KEY_DOWN && event.key.keysym.sym == SDLK_DOWN)
            {
                snake.ChangeDirection(SnakeDirection::DOWN);
            }

            if (event.type == SDL_EVENT_KEY_DOWN && event.key.keysym.sym == SDLK_RIGHT)
            {
                snake.ChangeDirection(SnakeDirection::RIGHT);
            }

            if (event.type == SDL_EVENT_KEY_DOWN && event.key.keysym.sym == SDLK_LEFT)
            {
                snake.ChangeDirection(SnakeDirection::LEFT);
            }
        }

        snake.Move();

        // Check Collisions
        switch (snake.CheckCollisions(food, WINDOW_WIDTH, WINDOW_HEIGHT))
        {
        case Collision::FoodCollision:

            snake.Eat();

            // Generate new food location
            food.x = (rand() % TOTAL_AMOUNT_OF_CELLS_X) * GRID_SIZE;
            food.y = (rand() % TOTAL_AMOUNT_OF_CELLS_Y) * GRID_SIZE;

            break;

        case Collision::BodyCollision:
            std::cout << "Body Collision" << std::endl;
            quit = true;
            break;

        case Collision::WallCollision:
            std::cout << "Wall Collision" << std::endl;
            quit = true;
            break;
        }

        screen.Render(food, snake);

        // Cap the frame rate
        endTime = SDL_GetTicks();
        Uint32 elapsedTime = endTime - startTime;

        if (elapsedTime < TICKS_PER_FRAME)
        {
            SDL_Delay(TICKS_PER_FRAME - elapsedTime);
        }
    }

    return 0;
}