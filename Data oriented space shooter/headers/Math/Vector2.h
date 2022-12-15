#pragma once
#include <iostream>
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
	Vector2 operator*(const float& other)
	{
		return { x * other, y * other };
	}
	Vector2 operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Vector2 operator/(const float& other)
	{
		return {x / other, y / other};
	}
	
};
