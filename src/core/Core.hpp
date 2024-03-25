/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.hpp
*/

#pragma once

    #include <vector>
    #include <list>
    #include "Object.hpp"
    #include "IGame.hpp"
    #include "IDisplay.hpp"

namespace Arcade {
    class Core {
        public:
            Core(std::string lib, std::string game);
            Core(const Arcade::Core &obj);
            ~Core();
        public:
            void mainLoop();
            void refreshLib();
        public:
            Arcade::Core &operator=(const Arcade::Core &obj);
        private:
            std::vector<Arcade::IGame> _game;
            std::vector<Arcade::IDisplay> _display;
            std::vector<Arcade::Object *> _object;
            std::list<std::string> _games;
            std::list<std::string> _libs;
    };
}
