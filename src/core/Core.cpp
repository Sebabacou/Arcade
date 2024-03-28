/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.cpp
*/

#include <filesystem>
#include <iostream>
#include "Core.hpp"

/* ----------------------------------- CORE ------------------------------------------ */

Arcade::Core::Core(std::string display) : _libInUse(display)
{
    this->refreshLib();
}

Arcade::Core::Core(const Arcade::Core &obj)
{
    this->_games = obj._games;
    this->_libs = obj._libs;
    this->_libInUse = obj._libInUse;
}

Arcade::Core::~Core()
{
}

void Arcade::Core::mainLoop()
{
    CoreLib libManager;
    std::vector<std::shared_ptr<Object>> objects;
    this->_display = std::unique_ptr<IDisplay>(libManager.libLoader<IDisplay>(this->_libInUse));
    Arcade::Event lastEvent = Event::NONE;

    while (_isPlaying) {
        Event input = this->_display->getInput();
        if (input != Event::NONE)
            lastEvent = input;
        for (int turnToPlay = this->_display->playTurn(); turnToPlay > 0; turnToPlay--) {
            if (_isDisplayMenu)
                objects = this->menuManager();
            else
                objects = this->menuManager();
            this->manageInput(lastEvent, objects);
        }
    }
}

void Arcade::Core::manageInput(Arcade::Event &userInput, std::vector<std::shared_ptr<Object>> objects)
{
    switch (userInput) {
        case Event::NEXT_LIB:
            break;
        case Event::NEXT_GAME:
            break;
        case Event::MENU:
            this->_isDisplayMenu = true;
            break;
        case Event::ESCAPE:
            this->_isPlaying = false;
            break;
        case Event::PREV_GAME:
            break;
        case Event::PREV_LIB:
            break;
        case Event::REFRESH:
            this->refreshLib();
            break;
        default:
            this->_display.get()->clearWindow();
            for (auto object : objects) {
                this->_display.get()->draw(object);
            }
            this->_display.get()->updateWindow();
            break;
        }
        userInput = Event::NONE;
}

std::vector<std::shared_ptr<Arcade::Object>> Arcade::Core::menuManager() const
{
    std::vector<std::shared_ptr<Object>> objects;

    objects.push_back(std::make_shared<Object>(Object(20, 11, Type::Rectangle, Color::WHITE)));
    return objects;
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
    }
}

Arcade::Core &Arcade::Core::operator=(const Arcade::Core &obj)
{
    if (&obj == this)
        return *this;
    this->_games = obj._games;
    this->_libs = obj._libs;
    this->_libInUse = obj._libInUse;
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

void *Arcade::Core::CoreLib::openLib(const std::string libPath, const bool throwOnError) const
{
    void *handle = dlopen(libPath.c_str(), RTLD_NOW | RTLD_NODELETE);

    if (handle == NULL && throwOnError)
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

    if (!libOpened)
        return result;
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

    if (!libOpened)
        return result;
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
