#include "Screen.h"
#include "Snake.h"
#include "Food.h"

class Game
{
public:
    Game(GameSettings &gameSettings);
    ~Game();
    void Run();

private:
    GameSettings *gameSettings;
    Screen *screen;
    Snake *snake;
    Food *food;

    Uint32 startTime;
    Uint32 endTime;
};