/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.cpp
*/

#include <dlfcn.h>
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
    void *handle;
    void *(*fptr)();

    for (const auto &entry : std::filesystem::directory_iterator(libFolder)) {
        std::string libName = libFolder + (std::string)entry.path().filename();
        if (this->libIsChecked(this->_libs, libName) || this->libIsChecked(this->_games, libName))
            continue;
        handle = dlopen(libName.c_str(), RTLD_LAZY);
        if (handle == NULL)
            throw Core::CoreError("Core : Fail to open lib [" + libName + "].");
        fptr = (void*(*)())dlsym(handle, "entryPointDisplay");
        if (fptr != NULL) {
            this->_libs.push_back(libName);
            dlclose(handle);
            continue;
        }
        fptr = (void*(*)())dlsym(handle, "entryPointGame");
        if (fptr != NULL) {
            this->_games.push_back(libName);
            dlclose(handle);
            continue;
        }
        dlclose(handle);
        throw Core::CoreError("Core : The lib [" + libName + "] is not a valid lib.");
    }
}

bool Arcade::Core::libIsChecked(const std::list<std::string> libList, const std::string lib) const
{
    for (const auto &libInList : libList) {
        if (libInList == lib)
            return true;
    }
    return false;
}

Arcade::Core &Arcade::Core::operator=(const Arcade::Core &obj)
{
    if (&obj == this)
        return *this;
    this->_display = obj._display;
    this->_game = obj._game;
    return *this;
}
