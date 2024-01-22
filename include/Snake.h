#include <vector>
#include <SDL2/SDL.h>
#include <deque>

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

class Snake
{
public:
    Snake(SDL_Point _startingPos, int _gridSize);
    void Eat();
    void Move();
    void ChangeDirection(SnakeDirection _direction);
    Collision CheckCollisions(SDL_Point const &food, int screenWidth, int screenHeight);

    SnakeDirection direction;
    std::deque<SDL_Point> body;

private:
    int gridSize;
};
