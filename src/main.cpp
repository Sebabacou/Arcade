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
    std::cout << "Hello World" << std::endl;
    Arcade::Core test("hey","hello");

    test.refreshLib();
    return 0;
}
