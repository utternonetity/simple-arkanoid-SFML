#include "Game.h"


void Game::InitGame(sf::RenderWindow& window) {

    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(true);
}

void Game::Update(sf::RenderWindow& window){
    if (flag_paddle_move_) {
        paddle_.Move(side_, window);
    }
    ball_.Move(window, paddle_);
}

void Game::ProcessEvent(sf::RenderWindow& window){
    flag_paddle_move_ = false;


    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)|| sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            side_ = SideDirection::RIGHT;
        }
        else {
            side_ = SideDirection::LEFT;
        }
       
        flag_paddle_move_ = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        ball_.StartMovement();
    }
    

}

void Game::Render(sf::RenderWindow& window){
    window.clear();
    window.draw(paddle_.GetRacket());
    window.draw(ball_.GetBall());
    window.display();
}
