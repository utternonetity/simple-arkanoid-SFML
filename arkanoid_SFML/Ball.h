#pragma once
#include"Point.h"
#include <SFML/Graphics.hpp>
#include "Racket.h"

constexpr double PI = 3.14159265358979323846;


class Ball{
public:
	Ball();
	Ball(const PointPosition& pos, float speed, float radius);
	void Move(sf::RenderWindow& window, Racket& paddle);
	sf::CircleShape GetBall();
	void IsCollision(sf::RenderWindow& window, Racket& paddle);
	void StartMovement();
private:
	PointPosition pos_;
	sf::CircleShape circle_;
	float speed_;
	float radius_;
	float alpha_;
	bool is_move_ = false;
	void InitCircle();
	
};

