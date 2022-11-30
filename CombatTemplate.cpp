#include "CombatTemplate.h"

CombatTemplate::CombatTemplate(sf::RenderWindow* window) : ViewCreator(window)
{
	this->window = window;
	initComponent();
}

CombatTemplate::~CombatTemplate()
{
}

void CombatTemplate::initComponent()
{
	this->createBackground(1);

	//### Pokemon ###//
	int WindowY = this->window->getSize().y / 2-100;
	int pokeLeftX = this->window->getSize().x / 7;
	int pokeRightX = this->window->getSize().x - 275;

	this->addSprite(componentSprite[0], 2, pokeLeftX, WindowY+100, sf::Vector2f(3, 3), 34, 1, 27, 29, false, "GneuGneu");
	this->addSprite(componentSprite[1], 2, pokeRightX, WindowY+100, sf::Vector2f(3, 3), 195, 401, 42, 31, false, "Gneneu");
	//### ~Pokemon ###//
	
	//groudon(componentSprite[1], 2, pokeRightX-200, WindowY-100, sf::Vector2f(3, 3), 4, 1057, 154, 119, false, "Gneneu");

	this->addSprite(componentSprite[2], 3, pokeLeftX-100, WindowY-200, sf::Vector2f(1.5, 1.5), 46, 32, 270, 54, false, "InfoPokemonPlayer");
	this->addSprite(componentSprite[3], 3, pokeRightX - 200, WindowY - 200, sf::Vector2f(1.5, 1.5), 46, 32, 270, 54, false, "InfoPokemonNP");


	this->addText(componentText[0], sf::Color::Black, 3, "starter", pokeLeftX - 80, WindowY - 200, 40, false);
	int lvl = 16;
	std::string lvlSting = "Lv" + std::to_string(lvl);
	std::cout << lvlSting << std::endl;
	this->addText(componentText[1], sf::Color::Black, 3, lvlSting, pokeLeftX + 240, WindowY - 200, 35, false);
	//this->addText(componentText[0], sf::Color::Yellow, 0, "Test", (this->window->getSize().x / 3), (this->window->getSize().y / (3 * 2)), 100, false);
	//### Game Button ###//
	this->addText(componentText[2], sf::Color::Black, 3, "Ennemy", pokeRightX - 180, WindowY - 200, 40, false);
	lvl = 5;
	lvlSting = "Lv" + std::to_string(lvl);
	std::cout << lvlSting << std::endl;
	this->addText(componentText[3], sf::Color::Black, 3, lvlSting, pokeRightX + 140, WindowY - 200, 35, false);

	//### ~Game Button ###//


}
