/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Input
*/

#pragma once

/**
 * @file Input.hpp
 * @brief Input enumeration for the Arcade project
 */

namespace Arcade {

    /**
     * @enum Input
     * @brief An enumeration to standardize inputs across libraries.
     *
     * This enumeration contains all possible inputs that can be used in the Arcade project.
     * It includes all the letters of the alphabet from A to Z, as well as special keys like UP, DOWN, LEFT, RIGHT, etc.
     */
    enum Input {
        A, ///< Represents the 'A' key
        B, ///< Represents the 'B' key
        C, ///< Represents the 'C' key
        D, ///< Represents the 'D' key
        E, ///< Represents the 'E' key
        F, ///< Represents the 'F' key
        G, ///< Represents the 'G' key
        H, ///< Represents the 'H' key
        I, ///< Represents the 'I' key
        J, ///< Represents the 'J' key
        K, ///< Represents the 'K' key
        L, ///< Represents the 'L' key
        M, ///< Represents the 'M' key
        N, ///< Represents the 'N' key
        O, ///< Represents the 'O' key
        P, ///< Represents the 'P' key
        Q, ///< Represents the 'Q' key
        R, ///< Represents the 'R' key
        S, ///< Represents the 'S' key
        T, ///< Represents the 'T' key
        U, ///< Represents the 'U' key
        V, ///< Represents the 'V' key
        W, ///< Represents the 'W' key
        X, ///< Represents the 'X' key
        Y, ///< Represents the 'Y' key
        Z, ///< Represents the 'Z' key
        UP, ///< Represents the 'UP' key
        DOWN, ///< Represents the 'DOWN' key
        LEFT, ///< Represents the 'LEFT' key
        RIGHT, ///< Represents the 'RIGHT' key
        ESCAPE, ///< Represents the 'ESCAPE' key
        SPACE, ///< Represents the 'SPACE' key
        RESTART, ///< Represents the 'RESTART' key
        ENTER, ///< Represents the 'ENTER' key
        BACKSPACE, ///< Represents the 'BACKSPACE' key
        PREV_GAME, ///< Represents the 'PREV_GAME' key
        NEXT_GAME, ///< Represents the 'NEXT_GAME' key
        PREV_LIB, ///< Represents the 'PREV_LIB' key
        NEXT_LIB, ///< Represents the 'NEXT_LIB' key
        MENU, ///< Represents the 'MENU' key
        NONE, ///< Represents no key
    };
}
