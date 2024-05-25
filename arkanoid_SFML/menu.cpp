#include "menu.h"

  Menu::Menu()
	:window_(sf::VideoMode(800, 600), "Menu", sf::Style::None)
  {
	  window_.setFramerateLimit(144);
	  window_.setVerticalSyncEnabled(true);
	  
	  std::string path = "E:/petprojects/arkanoid_SFML/resources/Roboto-Black.ttf";
	
	  if (!font_.loadFromFile(path)) {
	       abort();
	  }
	
	  start_game_.setFont(font_);
	  start_game_.setString("START GAME");
	  start_game_.setCharacterSize(50);
	  start_game_.setPosition(350.f, 200.f);
	  start_game_.setFillColor(sf::Color::White);
	
	  exit_game_.setFont(font_);
	  exit_game_.setString("EXIT");
	  exit_game_.setCharacterSize(50);
	  exit_game_.setPosition(350.f, 300.f);
	  exit_game_.setFillColor(sf::Color::White);
  }


  void Menu::Update(){
  }

  void Menu::run(){
	  while (window_.isOpen()) {
		  ProcessEvent();
		  Update();
		  Render();
	  }
  }

  void Menu::Render(){
    window_.clear();
    window_.draw(start_game_);
    window_.draw(exit_game_);
    window_.display();
  }

  bool Menu::IsGameStart(){
	  return is_game_;
  }

  void Menu::ProcessEvent(){
      sf::Event event;
      while (window_.pollEvent(event)) {
          if (event.type == sf::Event::Closed ||
              (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
              window_.close();
          }

		 
          if (event.type == sf::Event::MouseButtonPressed) {
              if (start_game_.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  is_game_ = true;
				  window_.close();
              }
              if (exit_game_.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  window_.close();
              }
          }
		  
      }
  }
