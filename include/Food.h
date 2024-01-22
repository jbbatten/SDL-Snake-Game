
#include "IDrawable.h"
#include "GameSettings.h"
#include "SDL_render.h"

class Food : public IDrawable
{
public:
    explicit Food(GameSettings &gameSettings);

    void Draw(SDL_Renderer *renderer) override;

    SDL_Point position{};

private:
    GameSettings *gameSettings;

};