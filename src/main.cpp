
#include "../headers/Engine.h"

const int ScreenWidth = 1080;
const int ScreenHeight = 720;


float fFov = 3.1415 / 4.f; //угол поля зрения 
float fAngle = 0; //угол направления взгляда персонажа


int main() {

	Engine* engine = Engine::getEngine(fFov, ScreenWidth, ScreenHeight);

	engine->add_circle_to_map(20, { 200, 200 }, sf::Color::Red);
	engine->add_circle_to_map(30, { 300, 200 }, sf::Color::Red);
	engine->add_circle_to_map(50, { 200, 500 }, sf::Color::Red);

	engine->add_rect_to_map({ 100,100 }, { 50,50 });
	engine->add_rect_to_map({ 500,500 }, { 100,50 });



	engine->run();


}