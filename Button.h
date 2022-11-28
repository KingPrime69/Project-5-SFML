#pragma once

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(sf::RenderWindow* window, sf::Text content, sf::Color color, int font, const char* text,
		float x, float y, int size);
	Button();
	~Button();
	bool isPressed();
	bool isHover();
	void update();
protected:

private:
	sf::RenderWindow* window;
};

