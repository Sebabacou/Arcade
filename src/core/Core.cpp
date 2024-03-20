/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.cpp
*/

#include "Core.hpp"

Arcade::Core::Core(std::string display, std::string game)
{
    (void)display;
    (void)game;
}

Arcade::Core::Core(const Arcade::Core &obj)
{
    (void)obj;
    //this->_display = obj.display;
    //this->_game = obj.game;
    //this->_object = obj.object;
}

Arcade::Core::~Core()
{
}

void Arcade::Core::mainLoop()
{
}

void Arcade::Core::refreshLib()
{
}

Arcade::Core &Arcade::Core::operator=(const Arcade::Core &obj)
{
    if (&obj == this)
        return *this;
    //this->_display = obj.display;
    //this->_game = obj.game;
    //this->_object = obj.object;
    return *this;
}