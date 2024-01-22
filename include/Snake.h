
#include <deque>
#include "IDrawable.h"
#include "GameSettings.h"

enum class SnakeDirection{
    UP = 1,
    DOWN = 2,
    LEFT = 3, 
    RIGHT = 4
};


enum class Collision{
    FoodCollision = 1,
    WallCollision = 2,
    BodyCollision = 3, 
    NoCollision = 4
};

class Snake : public IDrawable
{
public:
    Snake(GameSettings &gameSettings);
    void Eat();
    void Move();
    void ChangeDirection(SnakeDirection _direction);
    void Draw(SDL_Renderer *renderer) override;
    Collision CheckCollisions(SDL_Point const &food, int screenWidth, int screenHeight);

    SnakeDirection direction;
    std::deque<SDL_Point> body;

private:
    GameSettings *gameSettings;
};
