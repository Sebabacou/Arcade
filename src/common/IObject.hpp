/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IObject.hpp
*/
/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** IObject
*/

#pragma once

#include <iostream>
#include "Color.hpp"
#include "Position.hpp"

/**
** @file IObject.hpp
** @brief IObject class for the Arcade project
**/

namespace Arcade {
    
    /**
     * @enum Type
     * @brief An enumeration to standardize types across libraries.
     *
     * This enumeration contains all possible types that can be used in the Arcade project.
     */
     enum Type {
         Circle, ///< Represents a circle
         Rectangle, ///< Represents a rectangle
         Text, ///< Represents a text
         Unknown ///< Represents an unknown type
     };

    /**
     * @class IObject
     * @brief A class to represent an object in the Arcade project.
     *
     * This class contains a position, a type, and a color to represent an object in the Arcade project.
     */
    class IObject {
    public:
        /**
         * @brief Get the Position of the object.
         *
         * This is a pure virtual function that needs to be implemented by any class that inherits from IObject.
         *
         * @return The Position of the object.
         */
        virtual Position getPosition() const = 0;

        /**
         * @brief Set the Position of the object.
         *
         * This is a pure virtual function that needs to be implemented by any class that inherits from IObject.
         *
         * @param newPosition The new Position of the object.
         */
        virtual void setPosition(Position const newPosition) = 0;

        /**
         * @brief Set the Position of the object.
         *
         * This is a pure virtual function that needs to be implemented by any class that inherits from IObject.
         *
         * @param x The new x-coordinate of the object.
         * @param y The new y-coordinate of the object.
         */
        virtual void setPosition(int const x, int const y) = 0;

        /**
         * @brief Get the Type of the object.
         *
         * This is a pure virtual function that needs to be implemented by any class that inherits from IObject.
         *
         * @return The Type of the object.
         */
        virtual Type getType() = 0;

        /**
         * @brief Get the Color of the object.
         *
         * This is a pure virtual function that needs to be implemented by any class that inherits from IObject.
         *
         * @return The Color of the object.
         */
        virtual Color getColor() = 0;

        /**
         * @brief Set the Color of the object.
         *
         * This is a pure virtual function that needs to be implemented by any class that inherits from IObject.
         *
         * @param color The new Color of the object.
         */
        virtual void setColor(Color color) = 0;

        /**
         * @brief Set the asset of the object.
         *
         * This is a pure virtual function that needs to be implemented by any class that inherits from IObject.
         *
         * @param asset The new asset of the object.
         */
        virtual void setAsset(std::string asset) = 0;

        /**
         * @brief Get the asset of the object.
         *
         * This is a pure virtual function that needs to be implemented by any class that inherits from IObject.
         *
         * @return The asset of the object.
         */
        virtual std::string getAsset() = 0;

        /**
         * @brief Check if the asset is set.
         *
         * This is a pure virtual function that needs to be implemented by any class that inherits from IObject.
         *
         * @return True if the asset is set, false otherwise.
         */
        virtual bool assetIsSet() = 0;
    };
}
