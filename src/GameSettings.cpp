#include <iostream>
#include "GameSettings.h"

GameSettings::GameSettings(int windowWidth, int windowHeight, int gridSize, int fps)
    : WINDOW_WIDTH(windowWidth),
      WINDOW_HEIGHT(windowHeight),
      GRID_SIZE(gridSize),
      FPS(fps),
      TICKS_PER_FRAME(1000 / fps),
      TOTAL_AMOUNT_OF_CELLS_X(windowWidth / gridSize),
      TOTAL_AMOUNT_OF_CELLS_Y(windowHeight / gridSize),
      STARTING_POS{(TOTAL_AMOUNT_OF_CELLS_X / 2) * GRID_SIZE,
                   (TOTAL_AMOUNT_OF_CELLS_Y / 2) * GRID_SIZE}
{
}
