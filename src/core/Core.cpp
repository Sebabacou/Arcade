/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.cpp
*/

#include <compare>
#include <filesystem>
#include "Core.hpp"

Arcade::Core::Core(std::string display, std::string game)
{
    (void)display;
    (void)game;
}

Arcade::Core::Core(const Arcade::Core &obj)
{
    this->_display = obj._display;
    this->_game = obj._game;
    this->_object = obj._object;
}

Arcade::Core::~Core()
{
}

void Arcade::Core::mainLoop()
{
}

void Arcade::Core::refreshLib()
{
    std::string libFolder = "./lib/";

    for (const auto &entry : std::filesystem::directory_iterator)
        std::cout << entry.path().filename() << std::endl;
}

Arcade::Core &Arcade::Core::operator=(const Arcade::Core &obj)
{
    if (&obj == this)
        return *this;
    this->_display = obj._display;
    this->_game = obj._game;
    this->_object = obj._object;
    return *this;
}