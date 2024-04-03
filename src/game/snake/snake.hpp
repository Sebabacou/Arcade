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
            void _do_movement(int direction);
            void _set_direction(int direction);
            bool _check_colide(int x, int y);
        private:
            int _score;
            std::vector<std::shared_ptr<Arcade::Object>> _game;
            int _direction;
            int _len;
    };
}
extern "C" Arcade::IGame *entryPointGame();
/*
// Créer un nouveau segment de tête pour le serpent
std::shared_ptr<Arcade::Object> newHead = std::make_shared<Arcade::Object>(Arcade::Object::Position(_game[0]->getPosition().getX() + x, _game[0]->getPosition().getY() + y), Arcade::Type::Rectangle, Arcade::Color::RED);

// Insérer le nouveau segment de tête au début du serpent
_game.insert(_game.begin(), newHead);

// Supprimer le dernier segment du serpent pour maintenir la même longueur
for (auto it = _game.begin() + _len + 1; it != _game.end(); ++it) {
   if ((*it)->getColor() == Arcade::Color::RED) {
       _game.erase(it);
       break;
   }
}
*/