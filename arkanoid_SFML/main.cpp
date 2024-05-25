#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Racket.h"

int main(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    Game new_game;
   

    new_game.InitGame(window);

    while (window.isOpen()){

        new_game.ProcessEvent(window);
        new_game.Update(window);
       
       
        new_game.Render(window);
    }

    return 0;
}