#include <SFML/Graphics.hpp>
#include "Game.h"
#include "menu.h"

int main(){
    
    Menu menu;
    menu.run();

    if (menu.IsGameStart()) {
        Game new_game;
        new_game.run();
    }

 

    return 0;
}