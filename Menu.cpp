#include "Menu.h"



Menu::Menu(sf::RenderWindow* window) : InterfaceTemplate(window)
{
	this->window = window;
	initComponent();
}

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::initComponent()
{	
	//### Title ###//
	this->addText(componentText[0], sf::Color::Yellow, 0, "Poke Moon", (this->window->getSize().x / 3), (this->window->getSize().y / (3 * 2)), 100);
	this->addText(componentText[1], sf::Color::Blue, 1, "Poke Moon", (this->window->getSize().x / 3), (this->window->getSize().y / (3 * 2)), 100);
	//### ~Title ###//

	//### Game Button ###//

	//### ~Game Button ###//

	//float width = this->window->getSize().x;
	//float height = this->window->getSize().y;

	//if (!title.loadFromFile("pokemonSolid.ttf"))return EXIT_FAILURE;
	//componentText[0].setFont(title);
	//componentText[0].setFillColor(sf::Color::Yellow);
	//componentText[0].setString("Poke Moon");
	//componentText[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	//componentText[0].setCharacterSize(100);
	//if (!title2.loadFromFile("pokemonHollow.ttf"))return EXIT_FAILURE;
	//componentText[1].setFont(title2);
	//componentText[1].setFillColor(sf::Color::Blue);
	//componentText[1].setString("Poke Moon");
	//componentText[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	//componentText[1].setCharacterSize(100);
}
