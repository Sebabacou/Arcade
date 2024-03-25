/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.hpp
*/

#pragma once

    #include <memory>
    #include <list>
    #include "IGame.hpp"
    #include "IDisplay.hpp"

namespace Arcade {
    class Core {
        public:
            Core(std::string lib, std::string game);
            Core(const Core &obj);
            ~Core();
        public:
            void mainLoop();
            void refreshLib();
        public:
            Arcade::Core &operator=(const Core &obj);
        private:
            std::shared_ptr<IGame> _game;
            std::shared_ptr<IDisplay> _display;
            std::list<std::string> _games;
            std::list<std::string> _libs;
    };
}
