#include <Snake.h>
#include <iostream>
#include <sdl_utility.h>

Snake::Snake(SDL_Point _startingPos, int _gridSize)
    : gridSize(_gridSize)
{
    body.push_front(_startingPos);
}

void Snake::Eat()
{
    // Move the head of the snake when it eats to the back of the body.
    body.push_back(body[0]);
}

void Snake::ChangeDirection(SnakeDirection _direction)
{
    direction = _direction;
}

void Snake::Move()
{
    // When the body has more than 1 part run this loop to move all elements up.
    if (body.size() > 1)
    {
        // start from back of the list and move down until i is 1.
        for (int i = body.size() - 1; i > 0; i--)
        {
            // Move element to the element in front of it.
            body[i] = body[i - 1];
        }
    }

    // Update the head of the snake and move it to a new position.
    switch (direction)
    {
    case SnakeDirection::UP:
        body[0].y -= gridSize;
        break;
    case SnakeDirection::DOWN:
        body[0].y += gridSize;
        break;

    case SnakeDirection::LEFT:
        body[0].x -= gridSize;
        break;

    case SnakeDirection::RIGHT:
        body[0].x += gridSize;
        break;

    default:
        break;
    }
}

Collision Snake::CheckCollisions(SDL_Point const &food, int screenWidth, int screenHeight)
{
    if (body[0] == food)
    {
        return Collision::FoodCollision;
    }

    for (int i = 1; i < body.size(); i++)
    {
        if (body[0] == body[i])
        {
            return Collision::BodyCollision;
        }
    }

    if (body[0].x < 0 || body[0].x > screenWidth || body[0].y < 0 || body[0].y > screenHeight)
    {
        return Collision::WallCollision;
    }

    return Collision::NoCollision;
}