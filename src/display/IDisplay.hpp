/*
** EPITECH PROJECT, 2024
** Arcade [WSL: Ubuntu]
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
    #define IDISPLAY_HPP_
    #include "Color.hpp"
    #include "IObject.hpp"
    #include "Input.hpp"

namespace Arcade {
    class IDisplay {
        public:
            virtual ~IDisplay() = default;

        public:
            virtual Input getInput(); //Cette fonction retourne un objet de type Input. 
            virtual void draw(const IObject *object); // Cette fonction prend un pointeur constant vers un objet de type IObject
            virtual void drawCircle(const IObject *object); // Cette fonction prend un pointeur constant vers un objet de type IObject
            virtual void drawRextangle(const IObject *object); // Cette fonction prend un pointeur constant vers un objet de type IObject
            virtual void drawText(const IObject *object); // Cette fonction prend un pointeur constant vers un objet de type IObject
            virtual void clearWindow(); // Cette fonction efface le contenu de la fenêtre d'affichage.
            virtual void updateWindow(); // Cette fonction met à jour le contenu de la fenêtre d'affichage après avoir effectué tous les dessins nécessaires.
            virtual bool playTurn(); //  Cette fonction effectue une itération de jeu, généralement utilisée dans le contexte d'un jeu vidéo ou d'une simulation.
    };
}

#endif /* !IDISPLAY_HPP_ */
