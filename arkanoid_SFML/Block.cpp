#include "Block.h"

Block::Block(PointPosition pos){
	pos_ = pos;

	InitBlock();
}

sf::RectangleShape Block::GetBlock() const {
	return rectangle_;
}

float Block::GetWidth(){
	return width_;
}

float Block::GetHeight(){
	return height_;
}

void Block::BreakBlock(){
	is_broken_ = true;
}

void Block::InitBlock(){
	rectangle_.setSize(sf::Vector2f(100.f, 25.f));
	rectangle_.setFillColor(sf::Color::Magenta);
	height_ = rectangle_.getSize().y;
	width_ = rectangle_.getSize().x;
	rectangle_.setPosition(pos_.GetX(), pos_.GetY());
}

PointPosition Block::GetPosition(){
	return pos_;
}

bool Block::IsBroken() const{
	return is_broken_;
}
