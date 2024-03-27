/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** template.cpp
*/

#include "template.hpp"

Arcade::template_game::template_game()
{
    _score = 0;
}

Arcade::template_game::~template_game()
{
}

std::vector<std::shared_ptr<Arcade::Object>> Arcade::template_game::Turn(Arcade::Event event)
{
    (void)event;
    std::vector<std::shared_ptr<Arcade::Object>> objects;
    return objects;
}

void Arcade::template_game::init()
{
}

int Arcade::template_game::getScore()
{
    return _score;
}
