#include "Button.h"

Button::Button(sf::RenderWindow* window, sf::Text content, sf::Color color, int font, const char* text,
	float x, float y, int size)
{

	this->window = window;
}

Button::Button()
{
}

Button::~Button()
{
}

bool Button::isPressed()
{
	return false;
}

bool Button::isHover()
{
	return false;
}

void Button::update()
{
}
