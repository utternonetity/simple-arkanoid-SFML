#pragma once
#include <algorithm>
#include <iostream>
#include"Point.h"
#include <SFML/Graphics.hpp>
#include "Racket.h"
#include "Block.h"
#include "Functions.h"
#include <vector>
#include <tuple>

constexpr double PI = 3.14159265358979323846;


class Ball{
public:
	Ball();
	Ball(const PointPosition& pos, float speed, float radius);
	void Move(sf::RenderWindow& window, Racket& paddle,std::vector<Block>& blocks, float elapsed);
	sf::CircleShape GetBall();
	PointPosition GetPosition();
	float GetRadius();
	void StartMovement();
	
private:
	PointPosition pos_;
	sf::CircleShape circle_;
	float speed_;
	float radius_;
	float alpha_;
	bool is_move_ = false;
	void InitCircle();
	void IsCollision(sf::RenderWindow& window, Racket& paddle, std::vector<Block>& blocks);
	SideDirection IsCollisionWithRacket(Racket& paddle);
	SideDirection IsCollisionWithBlock(std::vector<Block>& blocks);
	template<typename triangle>
	std::tuple<float, SideDirection> DistanceNearestCollision(triangle& block);
	
};

