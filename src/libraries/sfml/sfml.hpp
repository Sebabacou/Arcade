/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** sfml
*/

#pragma once
    #define NCURSES_HPP_
    #include <iostream>
    #include <memory>
    #include <IDisplay.hpp>
    #include <Event.hpp>
    #include <unistd.h>
    #include <SFML/Window.hpp>
    #include <SFML/Graphics.hpp>

    #define FONT "assets/font.ttf"

    #define SIZE 40


namespace Arcade {
    class SFML : public Arcade::IDisplay {
        public:
            SFML() : _window(sf::VideoMode(1920, 1080), "SFML window") {};
            ~SFML() { _window.close(); };

        public:
            Arcade::Event getInput() override;
            void clearWindow() override;
            void updateWindow() override;
            void draw(std::shared_ptr<Arcade::Object> object) override;
            int playTurn() override;

        private:
            void drawRectangle(const std::shared_ptr<Arcade::Object> object) override;
            void drawCircle(const std::shared_ptr<Arcade::Object> object) override;
            void drawText(const std::shared_ptr<Arcade::Object> object) override;
            static sf::Color defineColor(Arcade::Color color);
            sf::RenderWindow _window;
            sf::Clock _clock;
    };

    extern "C" Arcade::IDisplay *entryPointDisplay();
}
