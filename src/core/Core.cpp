/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.cpp
*/

#include "Core.hpp"

Core::Core(std::string display, std::string game)
{
    (void)display;
    (void)game;
}

Core::Core(const Core &obj)
{
    (void)obj;
    //this->_display = obj.display;
    //this->_game = obj.game;
    //this->_object = obj.object;
}

Core::~Core()
{
}

void Core::mainLoop()
{
}

void Core::refreshLib()
{
}

Core &Core::operator=(const Core &obj)
{
    if (&obj == this)
        return *this;
    //this->_display = obj.display;
    //this->_game = obj.game;
    //this->_object = obj.object;
    return *this;
}