#pragma once
class PointPosition{
public:
	PointPosition() = default;
	PointPosition(float x, float y);
	float GetX();
	float GetY();
	void SetX(float x);
	void SetY(float y);
private:
	float x_;
	float y_;
};

