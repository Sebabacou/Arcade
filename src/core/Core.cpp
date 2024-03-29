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
    if (this->_games.size() != 0)
        this->_gameInUse = this->_games.front();
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
            this->switchNextLib<IDisplay>(this->_libs, this->_libInUse, this->_display);
            break;
        case Event::NEXT_GAME:
            //this->switchNextLib<IGame>(this->_games, this->_gameInUse, this->_game);
            break;
        case Event::MENU:
            this->_isDisplayMenu = true;
            break;
        case Event::ESCAPE:
            this->_isPlaying = false;
            break;
        case Event::PREV_GAME:
            //this->switchPrevLib<IGame>(this->_games, this->_gameInUse, this->_game);
            break;
        case Event::PREV_LIB:
            this->switchPrevLib<IDisplay>(this->_libs, this->_libInUse, this->_display);
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

/* ----------------------------------- MENU MANAGER ------------------------------------------ */

std::vector<std::shared_ptr<Arcade::Object>> Arcade::Core::menuManager() const
{
    std::vector<std::shared_ptr<Object>> objects;
    Arcade::Object::Position pos(6, 5);

    objects.push_back(std::make_shared<Object>(Object(16, 1, Type::Text, Color::WHITE, "Arcade")));
    this->displayLibs(pos, objects);
    this->displayGames(pos, objects);
    objects.push_back(std::make_shared<Object>(Object(pos, Type::Text, Color::WHITE, "Username :")));
    return objects;
}

void Arcade::Core::displayLibs(Object::Position &pos, std::vector<std::shared_ptr<Object>> &objects) const
{
    std::shared_ptr<Object> display = std::make_shared<Object>(Object(1, 5, Type::Text, Color::WHITE, "Display :"));

    objects.push_back(display);
    for (auto displayLib : this->_libs) {
        objects.push_back(std::make_shared<Object>(Object(pos, Arcade::Type::Text,
        displayLib == this->_libInUse ? Arcade::Color::GREEN : Arcade::Color::WHITE, this->getLibName(displayLib))));
        if (pos.getX() + 5 >= 30) {
            pos.setX(display->getPosition().getX() + 5);
            pos.setY(pos.getY() + 2);
        } else {
            pos.setX(pos.getX() + 5);
        }
    }
    pos.setX(display->getPosition().getX());
    pos.setY(pos.getY() + 3);
}

void Arcade::Core::displayGames(Object::Position &pos, std::vector<std::shared_ptr<Object>> &objects) const
{
    std::shared_ptr<Object> game = std::make_shared<Object>(Object(pos, Type::Text, Color::WHITE, "Game :"));

    objects.push_back(game);
    pos.setX(pos.getX() + 5);
    for (auto gameLib : this->_games) {
        objects.push_back(std::make_shared<Object>(Object(pos, Arcade::Type::Text,
        gameLib == this->_gameInUse ? Arcade::Color::GREEN : Arcade::Color::WHITE, gameLib)));
        if (pos.getX() + 5 >= 30) {
            pos.setX(game->getPosition().getX() + 5);
            pos.setY(pos.getY() + 2);
        } else {
            pos.setX(pos.getX() + 5);
        }
    }
    pos.setX(1);
    pos.setY(20);
}

std::string Arcade::Core::getLibName(const std::string lib) const
{
    std::string result = lib;

    if (result.compare(0, 6, "./lib/") == 0)
        result.replace(0, 6, "");
    if (result.compare(result.length() - 3, 3, ".so") == 0)
        result.replace(result.length() - 3, 3, "");
    return result;
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

