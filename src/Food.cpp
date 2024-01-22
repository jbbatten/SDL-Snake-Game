#include "Food.h"


void Food::Draw(SDL_Renderer *renderer) {
    // Draw Food
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xCC, 0x00, 0xFF);
    // Set size of food
    SDL_FRect foodBlock;
    foodBlock.w = gameSettings->GRID_SIZE;
    foodBlock.h = gameSettings->GRID_SIZE;
    foodBlock.x = position.x;
    foodBlock.y = position.y;
    SDL_RenderFillRect(renderer, &foodBlock);
}

Food::Food(GameSettings &gameSettings)
        : gameSettings(&gameSettings) {

}
