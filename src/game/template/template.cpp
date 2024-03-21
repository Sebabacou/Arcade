/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** template.cpp
*/

#include "template.hpp"

template_game::template_game()
{
    _score = 0;
}

template_game::~template_game()
{
}

std::vector<std::shared_ptr<Arcade::Object>> template_game::Turn(Arcade::Event event)
{
    (void)event;
    std::vector<std::shared_ptr<Arcade::Object>> objects;
    return objects;
}

void template_game::init()
{
}

int template_game::getScore()
{
    return _score;
}
