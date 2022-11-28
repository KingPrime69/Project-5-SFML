#include "Button.h"

Button::Button(sf::RenderWindow* window)
{
	this->window = window;
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
