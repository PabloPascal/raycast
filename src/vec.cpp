#include "../headers/vec.h"


//constructor
vec2::vec2() {
	m_vec.x = 0;
	m_vec.y = 0;
}


vec2::vec2(sf::Vector2f v) 
{
	m_vec = v;
}

vec2::vec2(float x, float y) {
	m_vec.x = x;
	m_vec.y = y;
}


vec2::vec2(const vec2& v) {
	m_vec = v.m_vec;
}


//operators
vec2 vec2::operator+(const vec2& v) {
	return m_vec + v.m_vec;
}


vec2 vec2::operator*(const vec2& v) {
	return sf::Vector2f(m_vec.x * v.m_vec.x, m_vec.y * v.m_vec.y);
}


vec2 vec2::operator/(const vec2& v) {
	return sf::Vector2f(m_vec.x / v.m_vec.x, m_vec.y / v.m_vec.y);
}

vec2& vec2::operator=(const vec2& v) {
	m_vec = v.m_vec;
	return *this;
}


//methods
sf::Vector2f vec2::getVector() {
	return m_vec;
}


void vec2::SetVector(sf::Vector2f v) {
	m_vec = v;
}


void vec2::SetVector(float x, float y) {
	m_vec.x = x;
	m_vec.y = y;
}



//functions

float length(vec2& v) {
	return sqrt(pow(v.m_vec.x,2)  + pow(v.m_vec.y,2));
}

float length(sf::Vector2f v) {
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}


float dotProd(vec2 v1, vec2 v2) {
	return v1.getVector().x * v2.getVector().x + v1.getVector().y * v2.getVector().y;
}


float dotProd(sf::Vector2f v1, sf::Vector2f v2) {
	return v1.x * v2.x + v1.y * v1.y;
}

