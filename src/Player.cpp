#include "../headers/Player.h"


Player::Player(sf::Vector2f pos, float fFov) {
	m_fFov = fFov;
	m_pos = pos;

	player.setPosition(m_pos);
	r = 20;
	player.setRadius(r);
	player.setOrigin(r, r);
	m_fAngle = 0;

	m_speed = 150;
	direct = { 0,0 };
}



sf::Vector2f Player::getPosition() {
	return m_pos;
}


void Player::setPos(sf::Vector2f pos) {
	m_pos = pos;
	player.setPosition(m_pos);
}


void Player::update(sf::RenderWindow& window, float dt){
	m_pos = player.getPosition();
	move(window, dt);

}



void Player::move(sf::RenderWindow& window, float dt) {
	float m_ScreenWidth = window.getSize().x;
	float m_ScreenHeight = window.getSize().y;



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player.move(0, -m_speed * dt);
		if (m_pos.y - r < 0) {
			player.move(0, m_speed * dt);
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player.move(0, m_speed *dt);

		if (m_pos.y + r > m_ScreenHeight) {
			player.move(0, -m_speed * dt);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player.move(-m_speed * dt, 0);

		if (m_pos.x - r < 0) {
			player.move(m_speed * dt, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.move(m_speed * dt, 0);

		if (m_pos.x + r > m_ScreenWidth) {
			player.move(-m_speed * dt, 0);
		}
	}

	direct = { 0,0 };

	//mouse control
	m_fAngle = atan2f(sf::Mouse::getPosition(window).y - m_ScreenHeight / 2.0, 
					  sf::Mouse::getPosition(window).x - m_ScreenWidth / 2.0  );

}


sf::CircleShape& Player::getPlayerSprite() {
	return player;
}


float Player::getAngle() {
	return m_fAngle;
}

float Player::getRadius() {
	return r;
}


sf::Vector2f Player::getDirect() {
	return direct;
}


float Player::getSpeed() {
	return m_speed;
}