#include <iostream>
#include "Snake.h"
#include "sdl_utility.h"

Snake::Snake(GameSettings &gameSettings)
    :gameSettings(&gameSettings)
{
    body.push_back(gameSettings.STARTING_POS);
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
        body[0].y -= gameSettings->GRID_SIZE;
        break;
    case SnakeDirection::DOWN:
        body[0].y += gameSettings->GRID_SIZE;
        break;

    case SnakeDirection::LEFT:
        body[0].x -= gameSettings->GRID_SIZE;
        break;

    case SnakeDirection::RIGHT:
        body[0].x += gameSettings->GRID_SIZE;
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

void Snake::Draw(SDL_Renderer *renderer)
{
    // Draw Snake
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // Set size of Snake
    SDL_FRect snakeBlock;

    // Set snakeBlock to snake head.
    snakeBlock.w = gameSettings->GRID_SIZE;
    snakeBlock.h = gameSettings->GRID_SIZE;
    snakeBlock.x = body[0].x;
    snakeBlock.y = body[0].y;

    // Render Snake Head
    SDL_RenderFillRect(renderer, &snakeBlock);

    // Draw rest of the body.
    for (int i = 0; i < body.size(); i++)
    {
        snakeBlock.x = body[i].x;
        snakeBlock.y = body[i].y;
        // Render each part of the body.
        SDL_RenderFillRect(renderer, &snakeBlock);
    }
}