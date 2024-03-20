/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.hpp
*/

#pragma once

    #include <string>
    #include <vector>

class Core {
    public:
        Core(std::string lib, std::string game);
        Core(const Core &obj);
        ~Core();
    public:
        void mainLoop();
        void refreshLib();
    public:
        Core &operator=(const Core &obj);
    private:
        //std::vector<IGame> _game;
        //std::vector<IDisplay> _display;
        //std::vector<IObject *> _object;
};
