#include "../headers/Engine.h"

Engine* Engine::m_engine = nullptr;


Engine* Engine::getEngine(float fFov, int Width, int Height) {
	if (m_engine == nullptr) {

		m_engine = new Engine;

		m_engine->m_ScreenHeight = Height;
		m_engine->m_ScreenWidth = Width;

		m_engine->m_fFov = fFov;
		m_engine->m_player = Player(sf::Vector2f(100,100), fFov);

		m_engine->m_window.create(sf::VideoMode(Width, Height), "Raycast");
	}

	return m_engine;
}



void Engine::run() {

	sf::Clock clock;

	while (m_window.isOpen()) {

		sf::Time time = clock.restart();

		float dt = time.asSeconds();

		sf::Event event;
		while (m_window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				m_window.close();
			}

		}

		m_player.update(m_window, dt);

		//collision(dt);

		m_window.clear();

		RenderingObjects();
		render();

		m_window.draw(&lights[0], lights.size(), sf::Lines);
		m_window.draw(m_player.getPlayerSprite());
		m_window.display();
	}

}


void Engine::add_obj_to_map(float radius, sf::Vector2f c_pos, sf::Color color){

	sf::CircleShape object(radius);

	object.setOrigin(radius, radius);
	object.setFillColor(color);
	object.setPosition(c_pos);

	m_Objects.push_back(object);
}


void Engine::RenderingObjects() {
	for (auto ob : m_Objects) {
		m_window.draw(ob);
	}
}


void Engine::collision(float dt) {
	float epsilon = 0.1f;
	

	
	if (map(m_player.getPosition()) < m_player.getRadius()) {

		return;
	}
	else {
		m_player.update(m_window, dt);
	}

}

