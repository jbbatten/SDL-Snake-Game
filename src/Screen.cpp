#include <Screen.h>

#include <SDL3/SDL.h>
#include <iostream>


Screen::Screen(int _screenWidth, int _screenHeight, int _gridSize)
    : screenWidth(_screenWidth),
      screenHeight(_screenHeight),
      gridSize(_gridSize)
{

    // Initialize SDL. SDL_Init will return -1 if it fails.
    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }

    // Create a window
    sdl_window = SDL_CreateWindow("SDL Window Example",
                                  screenWidth, 
                                  screenHeight,
                                  SDL_WINDOW_BORDERLESS);
    if (sdl_window == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, NULL, SDL_RENDERER_ACCELERATED);

    if (nullptr == sdl_renderer)
    {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";

        SDL_DestroyWindow(sdl_window);
        SDL_Quit();
    }
}

Screen::~Screen()
{
    SDL_DestroyWindow(sdl_window);
    SDL_DestroyRenderer(sdl_renderer);
    SDL_Quit();
}

void Screen::Render(SDL_Point const &food, Snake const &snake)
{

    // Set the draw color to red (R=255, G=0, B=0, A=255)
    SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);

    // Clear the screen
    SDL_RenderClear(sdl_renderer);

    // Draw the Grid
    SDL_SetRenderDrawColor(sdl_renderer, 10, 10, 10, 0xFF);
    for (int i = 0; i < screenWidth; i += gridSize)
    {
        SDL_RenderLine(sdl_renderer, i, 0, i, screenHeight);
    }

    for (int j = 0; j < screenHeight; j += gridSize)
    {
        SDL_RenderLine(sdl_renderer, 0, j, screenWidth, j);
    }

    // Draw Food
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    // Set size of food
    SDL_FRect foodBlock;
    foodBlock.w = gridSize;
    foodBlock.h = gridSize;
    foodBlock.x = food.x;
    foodBlock.y = food.y;
    SDL_RenderFillRect(sdl_renderer, &foodBlock);

    // Draw Snake
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // Set size of Snake
    SDL_FRect snakeBlock;

    // Set snakeBlock to snake head.
    snakeBlock.w = gridSize;
    snakeBlock.h = gridSize;
    snakeBlock.x = snake.body[0].x;
    snakeBlock.y = snake.body[0].y;

    // Render Snake Head
    SDL_RenderFillRect(sdl_renderer, &snakeBlock);

    // Draw rest of the body.
    for (int i = 0; i < snake.body.size(); i++)
    {
        snakeBlock.x = snake.body[i].x;
        snakeBlock.y = snake.body[i].y;
        // Render each part of the body.
        SDL_RenderFillRect(sdl_renderer, &snakeBlock);
    }
    
    // Draw Score

    
    // Update the screen
    SDL_RenderPresent(sdl_renderer);
}