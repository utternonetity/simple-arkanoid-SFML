#pragma once
#include "Racket.h"
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include "Functions.h"
#include "Ball.h"
#include "Block.h"
#include <vector>


class Game{
public:
	Game();
	void Update();
	void ProcessEvent();
	void Render();
	void run();
private:
	sf::RenderWindow window_;
	Racket paddle_;
	Ball ball_;
	std::vector<Block> blocks_;
	SideDirection side_ = SideDirection::ERROR;
	bool flag_paddle_move_ = false;
	sf::Clock clock_;
};

