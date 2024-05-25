#include "Point.h"

PointPosition::PointPosition(float x, float y){
	x_ = x;
	y_ = y;
}

float PointPosition::GetX(){
	return x_;
}

float PointPosition::GetY(){
	return y_;
}

void PointPosition::SetX(float x){
	x_ = x;
}

void PointPosition::SetY(float y){
	y_ = y;
}
