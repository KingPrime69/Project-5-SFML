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
		this->addText(componentText[1], sf::Color::Blue, 1, "Test", (this->window->getSize().x / 3), (this->window->getSize().y / (3 * 2)), 100, false);
	}
}
