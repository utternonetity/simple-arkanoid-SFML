#include "Ball.h"

Ball::Ball(){
	speed_ = 0;
	pos_ = PointPosition(395.f, 295.f);
	radius_ = 10.f;
	alpha_ = -1;
	InitCircle();
}

Ball::Ball(const PointPosition& pos, float speed, float radius){
	pos_ = pos;
	radius_ = radius;
	speed_ = speed;
	alpha_ = 1;

	InitCircle();
}

void Ball::Move(sf::RenderWindow& window, Racket& paddle){
	
	IsCollision(window, paddle);
	
	if (is_move_) {
		pos_.SetX(pos_.GetX() + cos(alpha_) * speed_);
		pos_.SetY(pos_.GetY() + sin(alpha_) * speed_);

		circle_.setPosition(pos_.GetX(), pos_.GetY());
	}
	else {
		float x = paddle.GetPosition().GetX();
		x += paddle.GetWidth()/ 2-5.f;
		float y = paddle.GetPosition().GetY();
		y -= paddle.GetHeight() / 2 + 7.6;
		pos_ = PointPosition(x, y);

		circle_.setPosition(pos_.GetX(),pos_.GetY());
	}
}

void Ball::InitCircle(){
	circle_.setRadius(radius_);
	circle_.setFillColor(sf::Color::Green);
	circle_.setPosition(pos_.GetX(), pos_.GetY());
}

sf::CircleShape Ball::GetBall(){
	return circle_;
}

void Ball::IsCollision(sf::RenderWindow& window, Racket& paddle){

	float right_border = window.getSize().x;
	float left_border = 0;
	float top_border = 0;
	float bottom_border = window.getSize().y;


	if (pos_.GetY() < top_border|| IsCollisionWithRacket(paddle)) {
		alpha_ = -alpha_;
	}
	if (pos_.GetX() + 2 * radius_ >= right_border || pos_.GetX() <= left_border) {
		alpha_ = PI - alpha_;
	}

	if (pos_.GetY() > bottom_border+150) {
		is_move_ = false;
		alpha_ = -1;
		speed_ = 0;
	}
}

bool Ball::IsCollisionWithRacket(Racket& paddle){
	
	bool collision_y = (pos_.GetY() + 2*radius_)>= paddle.GetPosition().GetY()&& 
		(pos_.GetY() + 2*radius_) < paddle.GetPosition().GetY()+paddle.GetHeight();
	bool collision_x = (pos_.GetX() + radius_) >= paddle.GetPosition().GetX() && 
		(pos_.GetX() - radius_) < paddle.GetPosition().GetX() + paddle.GetWidth();

	return collision_x&&collision_y&&is_move_;

}

void Ball::StartMovement(){
	speed_ = 5;
	is_move_ = true;
}
