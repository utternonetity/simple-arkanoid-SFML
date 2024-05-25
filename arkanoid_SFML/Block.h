#pragma once
#include "Point.h"
#include <SFML/Graphics.hpp>

class Block{
public:
	Block() = default;
	Block(PointPosition pos);
	sf::RectangleShape GetBlock() const;
	float GetWidth();
	float GetHeight();
	void BreakBlock();
	void InitBlock();
	PointPosition GetPosition();
	bool IsBroken() const;
	
private:
	bool is_broken_ = false;
	float width_;
	float height_;
	PointPosition pos_;
	sf::RectangleShape rectangle_;
};

