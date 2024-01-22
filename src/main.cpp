#include "Game.h"

int main()
{
    GameSettings gameSettings(1000, 1000, 20, 10);
    Game game(gameSettings);

    game.Run();

    return 0;
}