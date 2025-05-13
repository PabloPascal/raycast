#ifndef VEC_H
#define VEC_H

#include <SFML/Graphics.hpp>


class vec2{

	sf::Vector2f m_vec;

public:
	vec2();

	vec2(sf::Vector2f);

	vec2(float x, float y);

	vec2(const vec2&);
public:

	vec2 operator+(const vec2&);
	vec2 operator*(const vec2&);
	vec2 operator/(const vec2&);
	vec2& operator=(const vec2&);

	bool operator==(const vec2&);

	vec2 operator*(float C);

public:
	sf::Vector2f getVector();

	void SetVector(sf::Vector2f);
	void SetVector(float x, float y);

	friend float length(vec2& v);
};

float length(sf::Vector2f v);

float dotProd(vec2 v1, vec2 v2);

float dotProd(sf::Vector2f v1, sf::Vector2f v2);

sf::Vector2f abs(sf::Vector2f v);

float maxcomp(sf::Vector2f v);

sf::Vector2f max(sf::Vector2f v, float p);

#endif // !VEC_H