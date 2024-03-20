/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Position
*/

#pragma once

/**
 * @file Position.hpp
 * @brief Position class for the Arcade project
 */

namespace Arcade {

    /**
     * @class Position
     * @brief A class to represent a position in a 2D space.
     *
     * This class contains two integers, x and y, to represent a position in a 2D space.
     */
    class Position {
        public:
            /**
             * @brief Construct a new Position object with given x and y coordinates.
             *
             * @param x The x coordinate of the position.
             * @param y The y coordinate of the position.
             */
            Position(int x, int y) : x(x), y(y) {};

            /**
             * @brief Copy constructor for the Position class.
             *
             * This constructor creates a new Position object by copying the x and y coordinates from another Position object.
             *
             * @param pos The Position object to copy from.
             */
            Position(Position const &pos) : x(pos.x), y(pos.y) {};

            /**
             * @brief Set the X coordinate of the position.
             *
             * @param x The new X coordinate.
             */
            void setX(int x) {this->x = x;}

            /**
             * @brief Set the Y coordinate of the position.
             *
             * @param y The new Y coordinate.
             */
            void setY(int y) {this->y = y;}

            /**
             * @brief Get the X coordinate of the position.
             *
             * @return The X coordinate.
             */
            int getX() const {return x;}

            /**
             * @brief Get the Y coordinate of the position.
             *
             * @return The Y coordinate.
             */
            int getY() const {return y;}

        private:
            int x; ///< The X coordinate of the position.
            int y; ///< The Y coordinate of the position.
    };
}
