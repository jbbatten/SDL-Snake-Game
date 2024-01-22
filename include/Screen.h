#include <SDL2/SDL.h>
#include <Snake.h>

class Screen
{

public:
    Screen(int screenWidth, int screenHeight, int gridSize);
    ~Screen();

    void Render(SDL_Point const &food, Snake const &snake);

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const int screenWidth;
    const int screenHeight;
    const int gridSize;
};