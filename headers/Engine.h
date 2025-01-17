#ifndef ENGINE_H
#define ENGINE_H


#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "vec.h"
#include "player.h"

class Engine{
private:

	static Engine* m_engine;
	Engine() = default;

private:

	sf::RenderWindow m_window;
	int m_ScreenWidth;
	int m_ScreenHeight;


	std::list<sf::CircleShape> m_Objects;

	float m_fFov;

	std::vector<sf::Vertex> lights;

	Player m_player;

	std::map<int, float> object_holder; //на будущее

public:

	Engine(const Engine&) = delete;

	static Engine* getEngine(float fFov, int Width, int Height);

public:

	void run();

	void add_obj_to_map(float radius, sf::Vector2f c_pos, sf::Color);

public: //raycast and rendering

	sf::Vector2f rayCast(sf::Vector2f pos, sf::Vector2f dir);
	
	void render();
	
	float map(sf::Vector2f current_pos);

	void Engine::RenderingObjects();
	
	float min_dist_to_Wall(sf::Vector2f current_pos);

public: //collision

	void collision(float dt);
};


#endif // !ENGINE_H
