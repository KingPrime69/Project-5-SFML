#include "Menu.h"



Menu::Menu(sf::RenderWindow* window) : InterfaceTemplate(window)
{
	this->window = window;
	initComponent();
}

Menu::~Menu()
{

}

void Menu::initComponent()
{	
	//### Title ###//
	this->addText(componentText[0], sf::Color::Yellow, 0, "Poke Moon", (this->window->getSize().x / 3), (1/this->window->getSize().y), 100, true);
	this->addText(componentText[1], sf::Color::Blue, 1, "Poke Moon", (this->window->getSize().x / 3), (1/this->window->getSize().y), 100, true);
	//### ~Title ###//

	//### TM ###//
	this->addText(componentText[2], sf::Color::Black, 0, "TM", (this->window->getSize().x / 3)+450, (1/this->window->getSize().y / 5+100), 18, false);
	this->addText(componentText[3], sf::Color::White, 1, "TM", (this->window->getSize().x / 3)+450, (1/this->window->getSize().y / 5+100), 18, false);
	//### ~TM ###//
	
	//### Game Button ###//
	this->createButton(componentText[4], sf::Color::Black, sf::Color::White, 2, "PLAYEUX",
		(this->window->getSize().x / 3) + 150, (this->window->getSize().y / 6 + 250), 0, 25,
		50, componentButton[0], "Start", 0, sf::Vector2f(0.25,0.25),
		47, 66, 1273, 462, true);
	//### ~Game Button ###//

	this->createButton(componentText[5], sf::Color::Black, sf::Color::White, 2, "Setting",
		(this->window->getSize().x / 3) + 150, (this->window->getSize().y / 6 + 450), 0, 25,
		50, componentButton[1], "param", 0, sf::Vector2f(0.25, 0.25),
		47, 66, 1273, 462, true);

	this->createBackground(0);
}


