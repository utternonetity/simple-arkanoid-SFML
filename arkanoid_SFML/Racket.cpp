#include "Racket.h"

Racket::Racket() {
	pos_ = PointPosition(897.5f, 1055.f);

	speed_ = 0.5;

	InitTriangle();
}

Racket::Racket(PointPosition pos, float speed){
	pos_ = pos;
	speed_ = speed;

	InitTriangle();
}

void Racket::Move(SideDirection side, sf::RenderWindow& window) {
	if (pos_.GetX() >= 0 && pos_.GetX()+racket_.getSize().x<= window.getSize().x) {
		float delta;
		(side == SideDirection::LEFT) ? delta = -30.f : delta = 30.f;
		pos_.SetX(pos_.GetX() + delta * speed_);
		racket_.setPosition(pos_.GetX(), pos_.GetY());
	}
	else if (pos_.GetX() < 0) {
		pos_.SetX(0);
	}
	else {
		pos_.SetX(window.getSize().x - racket_.getSize().x);
	}
}

sf::RectangleShape Racket::GetRacket(){
	return racket_;
}

PointPosition Racket::GetPosition(){
	return pos_;
}

float Racket::GetHeight(){
	return height_;
}

float Racket::GetWidth(){
	return width_;
}

void Racket::InitTriangle(){
	racket_.setSize(sf::Vector2f(125.f, 25.f));
	racket_.setFillColor(sf::Color::Blue);
	racket_.setPosition(pos_.GetX(), pos_.GetY());

	width_ = racket_.getSize().x;
	height_ = racket_.getSize().y;
}
