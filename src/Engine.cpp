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

		

		collision(dt);

		m_window.clear();

		RenderingObjects();
		render();
		m_window.draw(&lights[0], lights.size(), sf::Lines);
		m_window.draw(m_player.getPlayerSprite());

		m_window.display();
	}

}


void Engine::add_circle_to_map(float radius, sf::Vector2f c_pos, sf::Color color){

	sf::CircleShape circle(radius);

	circle.setOrigin(radius, radius);
	circle.setFillColor(color);
	circle.setPosition(c_pos);

	m_Circles.insert(std::make_pair(object_count, circle));
	object_count++;
}


void Engine::add_rect_to_map(sf::Vector2f first, sf::Vector2f second) {

	object_count++;

	sf::RectangleShape rect(first);
	rect.setPosition(first);
	rect.setSize(second);
	rect.setOrigin(second.x / 2, second.y / 2);
	rect.setFillColor(sf::Color::Blue);

	m_Rectangles.insert(std::make_pair(object_count, rect));

}



void Engine::RenderingObjects() {
	for (auto ob : m_Circles) {
		m_window.draw(ob.second);
	}
	for (auto ob : m_Rectangles) {
		m_window.draw(ob.second);
	}

}


void Engine::collision(float dt) {
	
	if (map(m_player.getPosition()).x < m_player.getRadius()) {
		
		sf::Vector2f norm = findNormal(m_player.getPosition());

		m_player.getPlayerSprite().move(2*m_player.getSpeed()*norm.x * dt, 2*m_player.getSpeed()*norm.y * dt);
		//m_player.getPlayerSprite().setPosition({ 50, 50 });

		
	}

}



