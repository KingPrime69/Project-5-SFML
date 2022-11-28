#include "Button.h"

Button::Button(sf::RenderWindow* window)
{
	this->window = window;
	this->initTexture();
}

Button::~Button()
{
	for (auto& i : this->componentButtonList)
	{
		delete i.second;
	}
}

int Button::initTexture()
{
	if (!bgButtonList[0].loadFromFile("sprite/buttonKiwi.png"))return EXIT_FAILURE;
	return 0;
}

void Button::setBox(sf::Text* text, sf::Sprite buttonSPrite, int bgTexture, float x, float y, int size,
	int rectLeft, int rectTop, int rectWidth, int rectHeight, const char* action, bool alignCenter)
{
	this->text = text;
	this->text->setOutlineColor(sf::Color::Blue);

	this->Sprite = buttonSPrite;
	this->Sprite.setTexture(bgButtonList[bgTexture]);
	this->Sprite.setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
	this->Sprite.setPosition(x, y);

	this->rectButton.setPosition(sf::Vector2f(x, y));
	this->rectButton.setSize(sf::Vector2f(rectWidth, rectHeight));
	this->rectButton.setOutlineThickness(3);
	this->rectButton.setOutlineColor(sf::Color::Cyan);
	this->rectButton.setFillColor(sf::Color::Transparent);

	this->action = action;

	if (alignCenter)
	{
		int calcCenter = (this->window->getSize().x - this->Sprite.getLocalBounds().width) / 2;
		this->Sprite.setPosition(calcCenter, y);
		this->rectButton.setPosition(calcCenter, y);
	}
	else
	{
		this->Sprite.setPosition(x, y);
		this->rectButton.setPosition(x, y);
	}
}

void Button::draw()
{
	this->window->draw(this->Sprite);
	this->window->draw(this->rectButton);
}

const char* Button::getAction()
{
	return this->action;
}

bool Button::isPressed()
{
	sf::Vector2f mousePos = sf::Vector2f(this->mouse.getPosition().x - this->window->getPosition().x,
		this->mouse.getPosition().y - this->window->getPosition().y - WINDOW_BAR);
	if (this->mouse.isButtonPressed(this->mouse.Left) && this->rectButton.getGlobalBounds().contains(mousePos))
	{
		return true;
	}
	else
		return false;
}

bool Button::isHover()
{
	sf::Vector2f mousePos = sf::Vector2f(this->mouse.getPosition().x - this->window->getPosition().x,
		this->mouse.getPosition().y - this->window->getPosition().y - WINDOW_BAR);

	if (this->rectButton.getGlobalBounds().contains(mousePos)) {
		this->text->setOutlineThickness(5);
	}
	else
	{
		this->text->setOutlineThickness(0);
		return false;
	}
}

void Button::update()
{
	this->isHover();
	this->draw();
}
