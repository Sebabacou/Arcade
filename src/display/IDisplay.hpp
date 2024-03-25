/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IDisplay
*/

#pragma once

#include <iostream>
#include <memory>
#include "Event.hpp"
#include "Object.hpp"

/**
 * @file IDisplay.hpp
 * @brief IDisplay class for the Arcade project
 **/



namespace Arcade {
/**
 * @class IDisplay
 * @brief A class to represent a display in the Arcade project.
 *
 * This class contains methods to get the input, draw an object, clear the window, update the window, and play the turn.
 */
    class IDisplay {
        public:
            virtual ~IDisplay() = default;
        public:
            virtual Event getInput() = 0;
            virtual void draw(std::shared_ptr<Object> object) = 0;
            virtual void clearWindow() = 0;
            virtual void updateWindow() = 0;
            virtual int playTurn() = 0;
        private:
            virtual void drawRectangle(const std::shared_ptr<Object> object) = 0;
            virtual void drawCircle(const std::shared_ptr<Object> object) = 0;
            virtual void drawText(const std::shared_ptr<Object> object) = 0;
    };
}
