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
    #include <dlfcn.h>
    #include "IGame.hpp"
    #include "IDisplay.hpp"

namespace Arcade {
    class Core {
        public:
            Core(std::string display);
            Core(const Core &obj);
            ~Core();
        public:
            void mainLoop();
            void refreshLib();
            std::vector<std::shared_ptr<Object>> menuManager() const;
            void manageInput(Event &userInput, std::vector<std::shared_ptr<Object>> objects);
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

            class CoreLib {
                public:
                    CoreLib();
                    CoreLib(const CoreLib &obj);
                    ~CoreLib();
                public:
                    void *openLib(const std::string libPath, const bool throwOnError = false) const;
                    void closeLib(void *libOpened) const;
                    bool isDisplayLib(void *libOpened, bool closeLib = true) const;
                    bool isGameLib(void *libOpened, bool closeLib = true) const;
                    bool libIsChecked(const std::list<std::string> libList, const std::string lib) const;
                    template<typename T>
                    T *libLoader(const std::string pathToLib) {
                        void *handler = this->openLib(pathToLib);
                        void *(*fptr)();

                        if (this->isDisplayLib(handler, false))
                            fptr = (void*(*)())dlsym(handler, "entryPointDisplay");
                        else
                            fptr = (void*(*)())dlsym(handler, "entryPointGame");
                        return ((T *)fptr());
                    };
                public:
                    CoreLib &operator=(const CoreLib &obj);
            };
        private:
            std::unique_ptr<IGame> _game;
            std::unique_ptr<IDisplay> _display;
            std::list<std::string> _games;
            std::list<std::string> _libs;
            std::string _libInUse;
            std::string _gameInUse = "";
            bool _isPlaying = true;
            bool _isDisplayMenu = true;
    };
}
