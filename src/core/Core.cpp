/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.cpp
*/

#include <dlfcn.h>
#include <filesystem>
#include "Core.hpp"

/* ----------------------------------- CORE ------------------------------------------ */

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
    Core::CoreLib libFunctions;

    for (const auto &entry : std::filesystem::directory_iterator(libFolder)) {
        std::string libName = libFolder + (std::string)entry.path().filename();
        if (libFunctions.libIsChecked(this->_libs, libName) || libFunctions.libIsChecked(this->_games, libName))
            continue;
        void *handle = libFunctions.openLib(libName);
        if (libFunctions.isDisplayLib(handle, false)) {
            this->_libs.push_back(libName);
            libFunctions.closeLib(handle);
            continue;
        }
        if (libFunctions.isGameLib(handle)) {
            this->_games.push_back(libName);
            continue;
        }
        throw Core::CoreError("Core : The lib [" + libName + "] is not a valid lib.");
    }
}

Arcade::Core &Arcade::Core::operator=(const Arcade::Core &obj)
{
    if (&obj == this)
        return *this;
    this->_display = obj._display;
    this->_game = obj._game;
    return *this;
}

/* ----------------------------------- CORELIB ------------------------------------------ */

Arcade::Core::CoreLib::CoreLib()
{
}


Arcade::Core::CoreLib::CoreLib(const Arcade::Core::CoreLib &obj)
{
    (void)obj;
}

Arcade::Core::CoreLib::~CoreLib()
{
}

void *Arcade::Core::CoreLib::openLib(const std::string libPath) const
{
    void *handle = dlopen(libPath.c_str(), RTLD_LAZY);

    if (handle == NULL)
        throw Core::CoreError("Core : Fail to open lib [" + libPath + "].");
    return handle;
}

void Arcade::Core::CoreLib::closeLib(void *libOpened) const
{
    dlclose(libOpened);
}

bool Arcade::Core::CoreLib::isDisplayLib(void *libOpened, bool closeLib) const
{
    void *(*fptr)();
    bool result = false;

    fptr = (void*(*)())dlsym(libOpened, "entryPointDisplay");
    if (fptr != NULL)
        result = true;
    if (closeLib)
        this->closeLib(libOpened);
    return result;
}

bool Arcade::Core::CoreLib::isGameLib(void *libOpened, bool closeLib) const
{
    void *(*fptr)();
    bool result = false;

    fptr = (void*(*)())dlsym(libOpened, "entryPointGame");
    if (fptr != NULL)
        result = true;
    if (closeLib)
        this->closeLib(libOpened);
    return result;
}

bool Arcade::Core::CoreLib::libIsChecked(const std::list<std::string> libList, const std::string lib) const
{
    for (const auto &libOfList : libList) {
        if (libOfList == lib)
            return true;
    }
    return false;
}

Arcade::Core::CoreLib &Arcade::Core::CoreLib::operator=(const Arcade::Core::CoreLib &obj)
{
    (void)obj;
    return *this;
}
