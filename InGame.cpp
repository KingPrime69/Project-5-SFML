#include "InGame.h"



InGame::InGame(sf::RenderWindow* window, bool menu) : InterfaceTemplate(window)
{
	this->window = window;
	this->showMenu = menu;
	initComponent();
}

InGame::~InGame()
{

}

void InGame::initComponent()
{
	
	//### Title ###//
	this->addText(componentText[0], sf::Color::Yellow, 0, "Test", (this->window->getSize().x / 3), (this->window->getSize().y / (3 * 2)), 100, false);

	//### ~Title ###//

	//### Game Button ###//

	//### ~Game Button ###//

	if (this->showMenu == true)
	{
		//### Game Button ###//
		this->createButton(componentText[1], sf::Color::White, sf::Color::Yellow, 2, "PLAYEUX",
			(this->window->getSize().x-300), (this->window->getSize().y / 6 + 250), 0, 25,
			50, componentButton[0], "Start", 0, sf::Vector2f(0.25, 0.25),
			47, 66, 1273, 462, false);
		//### ~Game Button ###//

		this->createButton(componentText[2], sf::Color::White, sf::Color::Yellow, 2, "Setting",
			(this->window->getSize().x / 3) + 150, (this->window->getSize().y / 6 + 450), 0, 25,
			50, componentButton[1], "param", 0, sf::Vector2f(0.25, 0.25),
			47, 66, 1273, 462, false);
	}
}
