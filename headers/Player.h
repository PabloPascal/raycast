#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "vec.h"


class Player
{
private:
	sf::Vector2f m_pos;
	float m_fFov;
	float m_fAngle;

	float m_speed;

	sf::Vector2f direct;

	float r;

	sf::CircleShape player;

	
public:
	Player() = default;

	Player(sf::Vector2f pos, float fFov);

	void update(sf::RenderWindow& window, float dt);

	void move(sf::RenderWindow& window, float dt);

	sf::Vector2f getPosition();

	void setPos(sf::Vector2f pos);

	sf::CircleShape getPlayerSprite();

	float getAngle();

	float getRadius();

	sf::Vector2f getDirect();
};



#endif // !PLAYER_H
