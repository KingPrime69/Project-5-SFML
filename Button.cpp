#include "Button.h"

Button::Button(sf::RenderWindow* window)
{
	this->window = window;
	this->initTexture();
}

Button::~Button()
{
}

int Button::initTexture()
{
	if (!bgButtonList[0].loadFromFile("sprite/buttonKiwi.png"))return EXIT_FAILURE;
	return 0;
}

void Button::setBox(sf::Sprite buttonSPrite, int bgTexture, float x, float y, int size)
{
	this->Sprite = buttonSPrite;
	this->Sprite.setTexture(bgButtonList[bgTexture]);
	this->Sprite.setTextureRect(sf::IntRect(17, 98, 263, 103));
	this->Sprite.setPosition(x, y);
}

void Button::draw()
{
	this->window->draw(this->Sprite);
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
