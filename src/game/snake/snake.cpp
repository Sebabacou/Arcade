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
    switch (event) {
        case Arcade::Event::GAME_LEFT:
            if (!_alive)
                return _is_dead();
            _do_movement(LEFT);
            break;
        case Arcade::Event::GAME_RIGHT:
            if (!_alive)
                return  _is_dead();
            _do_movement(RIGHT);
            break;
        case Arcade::Event::GAME_RESTART:
            init();
            break;
        default:
            if (!_alive)
                return _is_dead();
            _do_movement(0);
            break;
    }
    return _game;
}

void Arcade::snake::init()
{
    _score = 0;
    _direction = RIGHT;
    _len = 4;
    _alive = true;
    _game.clear();
    for (int i = 0; i < MAP_X; i++) {
        for (int j = 0; j < MAP_Y; j++) {
            if (i == 0 || i == MAP_X - 1 || j == 0 || j == MAP_Y - 1) {
                std::shared_ptr<Arcade::Object> wall = std::make_shared<Arcade::Object>(Arcade::Object::Position(i, j), Arcade::Type::Rectangle, Arcade::Color::WHITE, "librairies/assets/snake/wall.jpg");
                _game.push_back(wall);

            } else {
                _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(i, j), Arcade::Type::Rectangle, Arcade::Color::GREEN));
            }
        }
    }
    _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(MAP_X / 2, MAP_Y / 2), Arcade::Type::Rectangle, Arcade::Color::RED));
    _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(MAP_X - 2, MAP_Y / 2), Arcade::Type::Rectangle, Arcade::Color::PURPLE));
    _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(MAP_X + 1, 1), Arcade::Type::Text, Arcade::Color::WHITE, "Score: " + std::to_string(_score)));
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

            if (_check_colide(oldX + x, oldY + y)) {
                for (auto &i : _game) {
                    if (i->getPosition().getX() == oldX + x && i->getPosition().getY() == oldY + y) {
                        i->setPosition(oldX, oldY);
                    }
                }
                object->setPosition(oldX + x, oldY + y);
            } else {
                _alive = false;
            }
        }
    }
}

void Arcade::snake::_set_direction(int direction)
{
    switch (_direction) {
        case LEFT:
            if (direction == LEFT)
                _direction = DOWN;
            if (direction == RIGHT)
                _direction = UP;
            break;
        case RIGHT:
            if (direction == LEFT)
                _direction = UP;
            if (direction == RIGHT)
                _direction = DOWN;
            break;
        case UP:
            if (direction == LEFT)
                _direction = LEFT;
            if (direction == RIGHT)
                _direction = RIGHT;
            break;
        case DOWN:
            if (direction == LEFT)
                _direction = RIGHT;
            if (direction == RIGHT)
                _direction = LEFT;
            break;
        default:
            break;
    }
}

void Arcade::snake::_do_movement(int direction)
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

bool Arcade::snake::_check_colide(int x, int y)
{
    for (auto &object : _game) {
        if (object->getPosition().getX() == x && object->getPosition().getY() == y) {
            if (object->getColor() == Arcade::Color::RED)
                return false;
            if (object->getColor() == Arcade::Color::WHITE)
                return false;
            if (object->getColor() == Arcade::Color::PURPLE) {
                _score++;
                object->setPosition(rand() % (MAP_X - 1), rand() % (MAP_Y - 1));
                if (object->getPosition().getX() == 0)
                    object->setPosition(1, object->getPosition().getY());
                if (object->getPosition().getY() == 0)
                    object->setPosition(object->getPosition().getX(), 1);
                for (auto &i : _game) {
                    if (i->getColor() == Arcade::Color::WHITE)
                        i->setAsset("Score: " + std::to_string(_score));
                }
            }
        }
    }
    return true;
}

std::vector<std::shared_ptr<Arcade::Object>> Arcade::snake::_is_dead()
{
    if (_alive == false) {
        _game.clear();
        _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(MAP_X + 1, MAP_Y / 2), Arcade::Type::Text, Arcade::Color::RED, "You died"));
        _game.push_back(std::make_shared<Arcade::Object>(Arcade::Object::Position(MAP_X + 1, MAP_Y / 2 + 1), Arcade::Type::Text, Arcade::Color::WHITE, "Score: " + std::to_string(_score)));
    }
    return _game;
}

extern "C" Arcade::IGame *entryPointGame()
{
    return (new Arcade::snake());
}