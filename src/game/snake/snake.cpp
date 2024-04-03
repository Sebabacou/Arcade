/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** snake
*/

#include "snake.hpp"

Arcade::snake::snake()
{
    init();
}

Arcade::snake::~snake()
{
}

std::vector<std::shared_ptr<Arcade::Object>> Arcade::snake::Turn(Arcade::Event event)
{
    std::cout << "Event for snake: " << event << std::endl;
    switch (event) {
        case Arcade::Event::GAME_LEFT:
            _define_direction(LEFT);
            break;
        case Arcade::Event::GAME_RIGHT:
            _define_direction(RIGHT);
            break;
        case Arcade::Event::GAME_RESTART:
            init();
            break;
        default:
            break;
    }
    return _game;
}

void Arcade::snake::init()
{
    _score = 0;
    _direction = RIGHT;
    _game.clear();
    for (int i = 0; i < MAP_X; i++) {
        for (int j = 0; j < MAP_Y; j++) {
            if (i == 0 || i == MAP_X - 1 || j == 0 || j == MAP_Y - 1) {
                std::shared_ptr<Arcade::Object> wall = std::make_shared<Arcade::Object>(Arcade::Object::Position(i, j), Arcade::Type::Rectangle, Arcade::Color::WHITE);
                wall->setAsset("librairies/assets/snake/wall.jpg");
                _game.push_back(wall);

            } else {
                _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(i, j), Arcade::Type::Rectangle, Arcade::Color::GREEN));
            }
        }
    }
    _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(MAP_X / 2, MAP_Y / 2), Arcade::Type::Rectangle, Arcade::Color::RED));
    _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(MAP_X / 2 - 1, MAP_Y / 2), Arcade::Type::Rectangle, Arcade::Color::PURPLE));
}

int Arcade::snake::getScore()
{
    return _score;
}

void Arcade::snake::_move_snake(int x, int y)
{
    for (auto &object : _game) {
        if (object->getColor() == Arcade::Color::RED) {
            int oldX = object->getPosition().getX();
            int oldY = object->getPosition().getY();

            object->setPosition(oldX + x, oldY + y);

            _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(oldX, oldY), Arcade::Type::Rectangle, Arcade::Color::GREEN));
        }
    }
}

void Arcade::snake::_set_direction(int direction)
{
    if (direction == UP && _direction != DOWN) {
        _direction = UP;
    } else if (direction == DOWN && _direction != UP) {
        _direction = DOWN;
    } else if (direction == LEFT && _direction != RIGHT) {
        _direction = LEFT;
    } else if (direction == RIGHT && _direction != LEFT) {
        _direction = RIGHT;
    }
}

void Arcade::snake::_define_direction(int direction)
{
    _set_direction(direction);
    switch (_direction) {
        case UP:
            _move_snake(0, -1);
            break;
        case DOWN:
            _move_snake(0, 1);
            break;
        case LEFT:
            _move_snake(-1, 0);
            break;
        case RIGHT:
            _move_snake(1, 0);
            break;
    }
}

extern "C" Arcade::IGame *entryPointGame()
{
    return (new Arcade::snake());
}