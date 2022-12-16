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
	Vector2 operator-(const Vector2& other)
	{
		return { x - other.x, y - other.y };
	}
	Vector2 operator*(const float& other)
	{
		return { x * other, y * other };
	}
	
	Vector2 operator/(const float& other)
	{
		return {x / other, y / other};
	}
	
};

static float Length(const Vector2 v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}
static Vector2 Normalize(Vector2 v)
{
	float length = Length(v);
	v.x = v.x / length;
	v.y = v.y / length;
	return v;
}
