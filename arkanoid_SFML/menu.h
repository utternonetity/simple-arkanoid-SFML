#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu{
public:
	Menu();
	void run();
	void ProcessEvent();
	void Update();
	void Render();
	bool IsGameStart();
private:
	bool is_game_ = false;
	sf::Text start_game_;
	sf::Text exit_game_;
	sf::RenderWindow window_;
	sf::Font font_;
};

