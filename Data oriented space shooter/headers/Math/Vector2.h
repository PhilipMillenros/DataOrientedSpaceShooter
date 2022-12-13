#pragma once
struct Vector2
{
public:
	float x, y;

	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}

	Vector2 operator+(const Vector2 &other)
	{
		return {other.x + x, other.y + y};
	}
};