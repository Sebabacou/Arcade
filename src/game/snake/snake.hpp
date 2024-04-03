/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** snake
*/

#pragma once

#include "IGame.hpp"
#include <map>

#define MAP_X 21
#define MAP_Y 21

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

namespace Arcade {
    class snake: public Arcade::IGame {
        public:
            snake();
            ~snake();
            std::vector<std::shared_ptr<Arcade::Object>> Turn(Arcade::Event event);
            void init();
            int getScore();
        private:
            void _move_snake(int direction_x, int direction_y);
            void _define_direction(int direction);
            void _set_direction(int direction);
        private:
            int _score;
            std::vector<std::shared_ptr<Arcade::Object>> _game;
            int _direction;
    };
}
extern "C" Arcade::IGame *entryPointGame();
