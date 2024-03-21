/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** template.hpp
*/

#pragma once

#include "IGame.hpp"

class template_game: Arcade::IGame {
    public:
        template_game();
        ~template_game();
        std::vector<std::shared_ptr<Arcade::Object>> Turn(Arcade::Event event);
        void init();
        int getScore();
    private:
        int _score;
};
