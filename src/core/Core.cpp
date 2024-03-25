/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.cpp
*/

//#include <compare>
//#include <experimental/filesystem>
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
}

Arcade::Core::~Core()
{
}

void Arcade::Core::mainLoop()
{
}

void Arcade::Core::refreshLib()
{
    //std::string libFolder = "./lib/";
//
    //for (const auto &entry : std::experimental::filesystem::directory_iterator(libFolder))
    //    std::cout << entry.path().filename() << std::endl;
}

Arcade::Core &Arcade::Core::operator=(const Arcade::Core &obj)
{
    if (&obj == this)
        return *this;
    this->_display = obj._display;
    this->_game = obj._game;
    return *this;
}