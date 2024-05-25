#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Functions.h"

class Racket{
public:
	Racket();
	Racket(PointPosition pos, float speed);
	void Move(SideDirection side, sf::RenderWindow& window);
	sf::RectangleShape GetRacket();
	PointPosition GetPosition();
	float GetHeight();
	float GetWidth();
	
private:
	PointPosition pos_;
	float speed_;
	sf::RectangleShape racket_;
	float height_;
	float width_;

	void InitTriangle();
};

