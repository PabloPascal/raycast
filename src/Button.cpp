#include "../headers/Button.h"


#include <iostream>


Button::Button(sf::Vector2f pos, std::string font_path, float text_size) {

	length = 0;

	m_font.loadFromFile(font_path);

	m_text.setString("");
	m_text.setFillColor(sf::Color::White);
	m_text.setPosition(pos.x, pos.y);
	//m_text.setOrigin(pos.x / 2, pos.y / 2);
	m_text.setCharacterSize(text_size);
	m_text.setFont(m_font);

}


void Button::draw(sf::RenderTarget& target) {

	target.draw(m_text);

}


void Button::addButton(float size, sf::Vector2f pos) {

}


bool Button::pressed(sf::RenderWindow& window) {
	float mouse_x = sf::Mouse::getPosition(window).x;
	float mouse_y = sf::Mouse::getPosition(window).y;

	float size = m_text.getCharacterSize();

	//std::cout << "textPos = " << m_text.getPosition().x;
	//std::cout << " mousePos = " << mouse_x << std::endl;

	bool isPressedX = mouse_x > m_text.getPosition().x && mouse_x < m_text.getPosition().x + length * size;
	bool isPressedY = mouse_y > m_text.getPosition().y && mouse_y < m_text.getPosition().y + length * size;

	return isPressedX && isPressedY;
}


void Button::setText(std::string text) {

	m_text.setString(text);
	length = text.length();
}


void Button::click(sf::RenderWindow& window, std::function<void(void)> callBack) {

	if (pressed(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_text.setFillColor(sf::Color::Red);
		if (callBack != nullptr)
			callBack();
	}
	else {
		m_text.setFillColor(sf::Color::White);
	}
}


std::string Button::getText() {
	return m_text.getString();
}