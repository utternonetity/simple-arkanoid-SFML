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

void Ball::Move(sf::RenderWindow& window, Racket& paddle, std::vector<Block>& blocks, float elapsed) {

	IsCollision(window, paddle, blocks);

	if (is_move_) {
		pos_.SetX(pos_.GetX() + cos(alpha_) * speed_ * elapsed / 10);
		pos_.SetY(pos_.GetY() + sin(alpha_) * speed_ * elapsed / 10);

		circle_.setPosition(pos_.GetX(), pos_.GetY());
	}
	else {
		float x = paddle.GetPosition().GetX();
		x += paddle.GetWidth() / 2 - 5.f;
		float y = paddle.GetPosition().GetY();
		y -= paddle.GetHeight() / 2 + 7.6;
		pos_ = PointPosition(x, y);

		circle_.setPosition(pos_.GetX(), pos_.GetY());
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

PointPosition Ball::GetPosition(){
	return pos_;
}

float Ball::GetRadius(){
	return radius_;
}

void Ball::IsCollision(sf::RenderWindow& window, Racket& paddle, std::vector<Block>& blocks){

	size_t right_border = window.getSize().x;
	size_t left_border = 0;
	size_t top_border = 0;
	size_t bottom_border = window.getSize().y;

	SideDirection collision_side_block = IsCollisionWithBlock(blocks);
	SideDirection collision_side_racket = IsCollisionWithRacket(paddle);
	SideDirection collision_side = SideDirection::ERROR;
	if (collision_side_block != SideDirection::ERROR) {
		collision_side = collision_side_block;
	}
	if (collision_side_racket != SideDirection::ERROR) {
		collision_side = collision_side_racket;
	}

	if (collision_side == SideDirection::CORNER) {
		alpha_ = PI - alpha_;
	}

	if (pos_.GetY() < top_border || collision_side == SideDirection::TOP||
		collision_side ==SideDirection::BOTTOM) {
		alpha_ = -alpha_;
	}
	if (pos_.GetX() + 2 * radius_ >= right_border || pos_.GetX() <= left_border||
		collision_side == SideDirection::LEFT || collision_side == SideDirection::RIGHT) {
		alpha_ = PI - alpha_;
	}

	if (pos_.GetY() > bottom_border+150) {
		is_move_ = false;
		alpha_ = -1;
		speed_ = 0;
	}
}

SideDirection Ball::IsCollisionWithRacket(Racket& paddle) {

	auto [distance, collision_side] = DistanceNearestCollision(paddle);
	if (distance <= radius_) {
		return collision_side;
	}
	return  SideDirection::ERROR;
}



SideDirection Ball::IsCollisionWithBlock(std::vector<Block>& blocks){


	for (auto& block : blocks) {
		if (!block.IsBroken()) {
			auto [distance, collision_side] = DistanceNearestCollision(block);
			if (distance <= radius_) {
				block.BreakBlock();
				return collision_side;;
			}
		}
	}
	
	return SideDirection::ERROR;
	
}

void Ball::StartMovement(){
	speed_ = 5;
	is_move_ = true;
}

template<typename triangle>
std::tuple<float, SideDirection> Ball:: DistanceNearestCollision(triangle& block) {
	PointPosition nearest_point;
	float distance;
	SideDirection collision_side = SideDirection::ERROR;

	nearest_point.SetX(std::max(block.GetPosition().GetX(),
		std::min(pos_.GetX() + radius_, block.GetPosition().GetX() + block.GetWidth())));
	nearest_point.SetY(std::max(block.GetPosition().GetY(),
		std::min(pos_.GetY() + radius_, block.GetPosition().GetY() + block.GetHeight())));
	distance = sqrt(pow(pos_.GetX() + radius_ - nearest_point.GetX(), 2) +
		pow(pos_.GetY() + radius_ - nearest_point.GetY(), 2));
	
	bool left_top_corner = (nearest_point.GetX() == block.GetPosition().GetX())
		&& (nearest_point.GetY() == block.GetPosition().GetY());

	bool left_bot_corner = (nearest_point.GetX() == block.GetPosition().GetX())
		&& (nearest_point.GetY() == block.GetPosition().GetY() + block.GetHeight());

	bool right_top_corner = (nearest_point.GetX() == block.GetPosition().GetX()+block.GetWidth())
		&& (nearest_point.GetY() == block.GetPosition().GetY() + block.GetHeight());

	bool right_bot_corner = (nearest_point.GetX() == block.GetPosition().GetX() + block.GetWidth())
		&& (nearest_point.GetY() == block.GetPosition().GetY() + block.GetHeight());

	if (left_top_corner || left_bot_corner || right_bot_corner || right_top_corner) {
		collision_side = SideDirection::CORNER;
	} 
	else if (nearest_point.GetX() == block.GetPosition().GetX()) {
		collision_side = SideDirection::LEFT;
	}
	else if (nearest_point.GetX() == block.GetPosition().GetX() + block.GetWidth()) {
		collision_side = SideDirection::RIGHT;
	}
	else if (nearest_point.GetY() == block.GetPosition().GetY()) {
		collision_side = SideDirection::TOP;
	}
	else {
		collision_side = SideDirection::BOTTOM;
	}

	return std::tie(distance, collision_side);
}
