#include "Game.h"


Game::Game()
    :window_(sf::VideoMode::getDesktopMode(), "Arkanoid", sf::Style::Fullscreen)
{
    window_.setMouseCursorVisible(false);
    window_.setFramerateLimit(144);
    window_.setVerticalSyncEnabled(true);
    for (size_t i = 0; i < 18; i++) {
        blocks_.push_back(Block(PointPosition(100.f * static_cast<float>(i) + static_cast<float>(i) * 5.f, 200.f)));
    }
}


void Game::Update(){
    float elapsed = clock_.restart().asMilliseconds();

    if (flag_paddle_move_) {
        paddle_.Move(side_, window_);
    }
    ball_.Move(window_, paddle_, blocks_, elapsed);
    ball_.Move(window_, paddle_, blocks_, elapsed);
}

void Game::ProcessEvent(){
    flag_paddle_move_ = false;


    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window_.close();
       
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E) {
                window_.close();
            }
        }
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

void Game::Render(){
    window_.clear();
    window_.draw(paddle_.GetRacket());
    window_.draw(ball_.GetBall());
    for (const auto& block : blocks_) {
        if (!block.IsBroken()) {
            window_.draw(block.GetBlock());
        }
    }
    window_.display();
}

void Game::run(){
    while (window_.isOpen()) {
        ProcessEvent();
        Update();
        Render();
    }
}
