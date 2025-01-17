#include "../headers/Engine.h"


sf::Vector2f Engine::rayCast(sf::Vector2f pos, sf::Vector2f dir) {
	float fdelta = 0;
	bool bHit = false;

	float epsilon = 0.0001;

	sf::Vector2f vTest;

	while (!bHit == true)
	{
		vTest = sf::Vector2f({ pos.x + fdelta * dir.x,pos.y + fdelta * dir.y });
		fdelta += abs(map(vTest));
		//fdelta += 0.5;
		if (map(vTest) <= epsilon) {
			bHit = true;
		}

		if (vTest.x < 0 || vTest.x > m_ScreenWidth || vTest.y < 0 || vTest.y > m_ScreenHeight) {
			bHit = true;
		}

	}

	return vTest;
}


void Engine::render() {

	float m_fCameraAngle = m_player.getAngle();
	sf::Vector2f pl_pos = m_player.getPosition();

	lights.clear();

	for (int j = 0; j < 30; j++) {
		float fRayAngle = (m_fCameraAngle - m_fFov / 2.f) + (float)j / (100.f) * m_fFov;


		lights.push_back(sf::Vertex());
		lights.back().position = pl_pos;

		lights.push_back(sf::Vertex());

		sf::Vector2f dir = sf::Vector2f(cos(fRayAngle), sin(fRayAngle));

		lights.back().position = rayCast(pl_pos, dir);
	}
}


float Engine::min_dist_to_Wall(sf::Vector2f current_pos) {

	sf::Vector2f LEFT(m_ScreenWidth, 0);
	sf::Vector2f Right_High(0, 0);
	sf::Vector2f Bottom(0, m_ScreenHeight);

	float distToWalls1 = length(current_pos - LEFT);
	float distToWalls2 = length(current_pos - Right_High);
	float distToWalls3 = length(current_pos - Bottom);

	return std::min(std::min(distToWalls1, distToWalls2), std::min(distToWalls2, distToWalls3));
}


float Engine::map(sf::Vector2f current_pos) {

	float min = 100000;

	for (auto ob : m_Objects) {
		if (length(current_pos - ob.getPosition()) < min) {
			min = length(current_pos - ob.getPosition()) - ob.getRadius();

		}
	}

	//std::cout << std::min(min, min_dist_to_Wall(current_pos)) << std::endl;

	return std::min(min, min_dist_to_Wall(current_pos));
}