/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include <iostream>
#include "Core.hpp"

int main(void)
{
    try {
        std::cout << "Hello World" << std::endl;
        Arcade::Core test("hey","hello");
        test.refreshLib();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
