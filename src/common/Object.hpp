/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Object.hpp
*/


#pragma once

#include <iostream>
#include "Color.hpp"

/**
** @file IObject.hpp
** @brief IObject class for the Arcade project
**/

namespace Arcade {
    
     enum Type {
         Circle, ///< Represents a circle
         Rectangle, ///< Represents a rectangle
         Text, ///< Represents a text
         Unknown ///< Represents an unknown type
     };

    class Object {
        public:
            class Position {
                public:
                    Position(int x, int y) : x(x), y(y) {};
                    Position(const Position &pos) : x(pos.x), y(pos.y) {};
                public:
                    Position& operator=(const Position &pos) {
                        if (this != &pos) {
                            x = pos.x;
                            y = pos.y;
                        }
                        return *this;
                    };
                public:
                    void setX(int x) {this->x = x;};
                    void setY(int y) {this->y = y;};
                    int getX() const {return x;};
                    int getY() const {return y;};
                private:
                    int x; ///< The X coordinate of the position.
                    int y; ///< The Y coordinate of the position.
            };
        public:
            Object(const Position &position, const Type &type, const Color &color) : _position(position), _type(type), _color(color) {};
            Object(const int x, const int y, const Type &type, const Color &color) : _position(x, y), _type(type), _color(color) {};
            Object(const int x, const int y, const Type &type, const Color &color, std::string asset) : _position(x, y), _type(type), _color(color), _asset(asset) {};
            ~Object() {};
        public:
            Position getPosition() const {return _position;};
            void setPosition(const Position newPosition) {_position = newPosition;};
            void setPosition(const int x, const int y) {_position.setX(x); _position.setY(y);};
            Type getType() {return _type;};
            Color getColor() {return _color;};
            void setColor(Color color) {_color = color;};
            void setAsset(std::string asset) {_asset = asset;};
            std::string getAsset() {return _asset;};
            bool assetIsSet() {return !_asset.empty();};
        private:
            Position _position; ///< The position of the object.
            Type _type; ///< The type of the object.
            Color _color; ///< The color of the object.
            std::string _asset; ///< The asset of the object.
    };
}
