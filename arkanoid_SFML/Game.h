#pragma once
#include "Racket.h"
#include <SFML/Graphics.hpp>
#include "Functions.h"
#include "Ball.h"

class Game{
public:
	Game() = default;
	void InitGame(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void ProcessEvent(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
private:
	Racket paddle_;
	Ball ball_;
	SideDirection side_;
	bool flag_paddle_move_ = false;
};

