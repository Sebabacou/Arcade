/*
** EPITECH PROJECT, 2023
** Arcade [WSL: Ubuntu-22.04]
** File description:
** Core.hpp
*/

#pragma once

    #include <memory>
    #include <list>
    #include <exception>
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
        public:
            class CoreError : public std::exception {
                public:
                    CoreError(std::string msg) : _msg(msg) {};
                    ~CoreError() {};
                private:
                    const char *what() const noexcept override {return _msg.c_str();};
                private:
                    std::string _msg;
            };
        private:
            bool libIsChecked(const std::list<std::string> libList, const std::string lib) const;
        private:
            std::shared_ptr<IGame> _game;
            std::shared_ptr<IDisplay> _display;
            std::list<std::string> _games;
            std::list<std::string> _libs;
    };
}
