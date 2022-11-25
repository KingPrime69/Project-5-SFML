#include "Menu.h"



Menu::Menu(WindowManager* window) : ViewManager(window)
{
	this->window = window;
}

Menu::~Menu()
{

}

int Menu::initComponent()
{
	float width = this->window->getSize().x;
	float height = this->window->getSize().y;

	if (!title.loadFromFile("pokemonSolid.ttf"))return EXIT_FAILURE;
	componentText[0].setFont(title);
	componentText[0].setFillColor(sf::Color::Yellow);
	componentText[0].setString("Poke Moon");
	componentText[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	componentText[0].setCharacterSize(100);

	if (!title2.loadFromFile("pokemonHollow.ttf"))return EXIT_FAILURE;
	componentText[1].setFont(title2);
	componentText[1].setFillColor(sf::Color::Blue);
	componentText[1].setString("Poke Moon");
	componentText[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	componentText[1].setCharacterSize(100);



	for (unsigned int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		componentTextList[i] = componentText[i];
	}
}

void Menu::draw()
{
	for (unsigned int i = 0; i < componentTextList.size(); i++)
	{
		this->window->drawText(componentTextList[i]);
	}
}
