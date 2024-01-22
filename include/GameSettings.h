#include "SDL_rect.h"

#ifndef GAMESETTINGS
#define GAMESETTINGS

struct GameSettings {
public:
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    int GRID_SIZE;
    int FPS;
    int TICKS_PER_FRAME = 1000 / FPS;
    int TOTAL_AMOUNT_OF_CELLS_X = WINDOW_WIDTH / GRID_SIZE;
    int TOTAL_AMOUNT_OF_CELLS_Y = WINDOW_HEIGHT / GRID_SIZE;
    SDL_Point STARTING_POS;

    GameSettings(int windowWidth, int windowHeight, int gridSize, int fps);

};

#endif