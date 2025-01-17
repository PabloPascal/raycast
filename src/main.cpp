
#include "../headers/Engine.h"

const int ScreenWidth = 640;
const int ScreenHeight = 480;


float fFov = 3.1415 / 4.f; //угол поля зрения 
float fAngle = 0; //угол направления взгляда персонажа


int main() {

	Engine* engine = Engine::getEngine(fFov, ScreenWidth, ScreenHeight);

	engine->add_obj_to_map(20, { 200, 200 }, sf::Color::Red);
	engine->add_obj_to_map(30, { 300, 200 }, sf::Color::Red);
	engine->add_obj_to_map(50, { 200, 500 }, sf::Color::Red);

	engine->run();


}