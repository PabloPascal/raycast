#ifndef WIDGETS_H
#define WIDGETS_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <functional>

class Button {

	sf::Font m_font;
	sf::Text m_text;
	int length;

public:
	Button(sf::Vector2f pos, std::string font_path, float text_size);
	
	void addButton(float size, sf::Vector2f pos);

	void draw(sf::RenderTarget& target);

	void setText(std::string text);

	void click(sf::RenderWindow& window, std::function<void(void)> callBack = nullptr);
	
	std::string getText();

private:

	bool pressed(sf::RenderWindow& window);

};



#endif //WIDGETS_H