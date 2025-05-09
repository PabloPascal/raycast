#ifndef ENGINE_H
#define ENGINE_H


#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>

#include "vec.h"
#include "player.h"
#include "Button.h"
#include "Physics.h"



class Engine{
private:

	static Engine* m_engine;
	[[maybe_unused]] Engine() = default;

private:

	sf::RenderWindow m_window;
	int m_ScreenWidth;
	int m_ScreenHeight;

	int object_count = 0;
	std::map<int, sf::CircleShape> m_Circles;
	std::map<int, sf::RectangleShape> m_Rectangles;

	float m_fFov;

	std::vector<sf::Vertex> lights;

	Player m_player;

	int currentID;

private:

	Button* play_button;

public:
	static bool isPlay;

	Engine(const Engine&) = delete;

	static Engine* getEngine(float fFov, int Width, int Height);

	~Engine();

public:

	void run();

	void add_circle_to_map(float radius, sf::Vector2f c_pos, sf::Color);

	void add_rect_to_map(sf::Vector2f first, sf::Vector2f end);

private: //raycast and rendering

	sf::Vector2f rayCast(sf::Vector2f pos, sf::Vector2f dir);
	
	void render();
	
	sf::Vector2f map(sf::Vector2f current_pos);

	void Engine::RenderingObjects();
	
	sf::Vector2f min_dist_to_Wall(sf::Vector2f current_pos);



private:

	void collision(float dt);
	sf::Vector2f findNormal(sf::Vector2f currentPos);

};


#endif // !ENGINE_H
