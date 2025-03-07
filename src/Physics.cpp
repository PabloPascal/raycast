#include "../headers/Engine.h"

void Engine::collision(float dt) {

	if (map(m_player.getPosition()).x < m_player.getRadius()) {

		sf::Vector2f norm = findNormal(m_player.getPosition());

		m_player.getPlayerSprite().move(1.1 * m_player.getSpeed() * norm.x * dt, 1.1 * m_player.getSpeed() * norm.y * dt);
		//m_player.getPlayerSprite().setPosition({ 50, 50 });


	}

}

sf::Vector2f boxNormal(const sf::RectangleShape& box, sf::Vector2f pos) {
	float x_b = box.getPosition().x;
	float y_b = box.getPosition().y;

	float w = box.getSize().x;
	float h = box.getSize().y;

	if (pos.x > x_b - w / 2 && pos.x < x_b + w / 2) {

		if (pos.y - y_b >= 0) return { 0, 1 };
		else return { 0, -1 };
	}

	if (pos.y > y_b - h && pos.y < y_b + h) {
		if (pos.x - x_b > 0) return { 1,0 };
		else return { -1,0 };

	}

}


sf::Vector2f Engine::findNormal(sf::Vector2f currentPos) {

	int id = map(currentPos).y;

	if (m_Circles.find(id) == m_Circles.end()) {

		return boxNormal(m_Rectangles[id], currentPos);

	}
	vec2 normal = currentPos - m_Circles[id].getPosition();

	normal = normal * (1 / length(normal));

	return normal.getVector();
}
