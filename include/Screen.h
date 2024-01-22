#include <vector>
#include "GameSettings.h"
#include "IDrawable.h"

class Screen
{

public:
    Screen(GameSettings &gameSettings);
    ~Screen();

    void Render();
    
    std::vector<IDrawable*> renderQueue;

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    GameSettings *gameSettings;
};