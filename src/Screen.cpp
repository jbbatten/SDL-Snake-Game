#include "Screen.h"
#include "SDL3/SDL.h"
#include <iostream>

Screen::Screen(GameSettings &gameSettings)
    : gameSettings(&gameSettings)
{

    // Initialize SDL. SDL_Init will return -1 if it fails.
    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }


    // Create a window
    sdl_window = SDL_CreateWindow("SDL Window Example",
                                  gameSettings.WINDOW_WIDTH, 
                                  gameSettings.WINDOW_HEIGHT,
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

void Screen::Render()
{
    // Set the draw color to gray (R=255, G=0, B=0, A=255)
    SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);

    // Clear the screen
    SDL_RenderClear(sdl_renderer);

    // Draw the Grid
    SDL_SetRenderDrawColor(sdl_renderer, 10, 10, 10, 0xFF);
    for (int i = 0; i < gameSettings->WINDOW_WIDTH; i += gameSettings->GRID_SIZE)
    {
        SDL_RenderLine(sdl_renderer, i, 0, i, gameSettings->WINDOW_HEIGHT);
    }

    for (int j = 0; j < gameSettings->WINDOW_HEIGHT; j += gameSettings->GRID_SIZE)
    {
        SDL_RenderLine(sdl_renderer, 0, j, gameSettings->WINDOW_WIDTH, j);
    }

    // Workout position of new food.
    SDL_Point food;
    food.x = (rand() % gameSettings->TOTAL_AMOUNT_OF_CELLS_X) * gameSettings->GRID_SIZE;
    food.y = (rand() % gameSettings->TOTAL_AMOUNT_OF_CELLS_Y) * gameSettings->GRID_SIZE;


    for(int i = 0; i < renderQueue.size(); i++){
        renderQueue[i]->Draw(sdl_renderer);
    }

    
    // Update the screen
    SDL_RenderPresent(sdl_renderer);
}