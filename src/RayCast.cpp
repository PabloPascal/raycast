#include "../headers/Engine.h"


sf::Vector2f Engine::rayCast(sf::Vector2f pos, sf::Vector2f dir) {
	float fdelta = 0;
	bool bHit = false;

	float epsilon = 0.0001;

	sf::Vector2f vTest;

	sf::Vector2f mapRes;

	while (!bHit == true)
	{
		vTest = sf::Vector2f({ pos.x + fdelta * dir.x,pos.y + fdelta * dir.y });
		mapRes = map(vTest);
		fdelta += abs(mapRes.x);
		//fdelta += 0.5;
		if (mapRes.x <= epsilon) {
			bHit = true;
		}

		if (vTest.x < 0 || vTest.x > m_ScreenWidth || vTest.y < 0 || vTest.y > m_ScreenHeight) {
			bHit = true;
		}

	}

	currentID = (int)mapRes.y;

	return vTest;
}


void Engine::render() {

	float m_fCameraAngle = m_player.getAngle();
	sf::Vector2f pl_pos = m_player.getPosition();

	lights.clear();

	for (int j = 0; j < 30; j++) {
		float fRayAngle = (m_fCameraAngle - m_fFov / 2.f) + (float)j / (30.f) * m_fFov;


		lights.push_back(sf::Vertex());
		lights.back().position = pl_pos;

		lights.push_back(sf::Vertex());

		sf::Vector2f dir = sf::Vector2f(cos(fRayAngle), sin(fRayAngle));

		lights.back().position = rayCast(pl_pos, dir);
	}
}


sf::Vector2f Engine::min_dist_to_Wall(sf::Vector2f current_pos) {

	sf::Vector2f LEFT(m_ScreenWidth, 0);
	sf::Vector2f Right_High(0, 0);
	sf::Vector2f Bottom(0, m_ScreenHeight);

	float distToWalls1 = length(current_pos - LEFT);
	float distToWalls2 = length(current_pos - Right_High);
	float distToWalls3 = length(current_pos - Bottom);

	return { std::min(std::min(distToWalls1, distToWalls2), std::min(distToWalls2, distToWalls3)), -1};
}



float boxDist(sf::Vector2f p, const sf::RectangleShape& box) {

	float x_b = box.getPosition().x;
	float y_b = box.getPosition().y;

	float w = box.getSize().x;
	float h = box.getSize().y;

	if (abs(p.x - x_b) - w / 2.f > 0 && abs(p.y - y_b) - h / 2.f > 0) {
		return sqrt(std::pow(abs(p.x - x_b) - w / 2.f, 2) + std::pow(abs(p.y - y_b) - h / 2.f, 2));
	}

	else {
		if (abs(p.x - x_b) - w / 2 < 0) {
			return abs(p.y - y_b) - h / 2.f;
		}

		if (abs(p.y - y_b) - h / 2.f < 0) {
			return abs(p.x - x_b) - w / 2;
		}

	}


}


sf::Vector2f Engine::map(sf::Vector2f current_pos) {

	float min = 100000;
	int id = 0;

	float dist;

	for (auto ob : m_Circles) {
		dist = length(current_pos - ob.second.getPosition());
		if (dist < min) {
			min = dist - ob.second.getRadius();
			id = ob.first;
		}
	}
	

	for (auto ob : m_Rectangles) {
		dist = boxDist(current_pos, ob.second);
		if (dist < min) {

			min = dist;
			id = ob.first;
			
		}
	}

	//std::cout << std::min(min, min_dist_to_Wall(current_pos)) << std::endl;
	sf::Vector2f min_wall = min_dist_to_Wall(current_pos);

	if (std::min(min, min_wall.x) == min_wall.x) return min_wall;

	return { min, (float)id };
}
