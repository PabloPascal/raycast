
#include "../headers/Engine.h"
#include "../headers/Button.h"


const int ScreenWidth = 1280;
const int ScreenHeight = 720;
float fFov = 3.1415 / 8;

int main() {


    Engine* engine = Engine::getEngine(fFov, ScreenWidth, ScreenHeight);

    engine->add_rect_to_map({ 1000,500 }, { 50,50 });
    engine->add_rect_to_map({ 10,150 }, { 1000,30 });
    engine->add_circle_to_map(50, sf::Vector2f(200, 500), sf::Color::Red);

    engine->run();
   
    
}
