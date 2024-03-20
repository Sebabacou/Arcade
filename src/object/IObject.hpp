/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IObject.hpp
*/

#pragma once

    #include <string>

enum Type {
    CIRCLE,
    SQUARE,
    TEXT
};

enum Color {
    BLUE,
    RED,
    YELLOW,
    PURPLE,
    GREY,
    GREEN,
    WHITE,
    BLACK
};

class IObject {
    public:
        virtual ~IObject() = default;
    public:
        //virtual Position getPosition() = 0;
        //virtual void setPosition(const Position newPosition) = 0;
        //virtual void setPosition(Position newPosition) = 0;
        //virtual void setPosition(int x, int y) = 0;
        virtual Type getType() = 0;
        virtual Color getColor() = 0;
        virtual std::string getAsset() = 0;
        virtual void setColor(Color newColor) = 0;
        virtual void setAsset(std::string asset) = 0;
        virtual bool assetIsSet() = 0;
};
