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

	int WindowYPokemon = this->window->getSize().y / 2-100;
	int pokeLeftX = this->window->getSize().x / 7;
	int pokeRightX = this->window->getSize().x - 275;

	//### Pokemon ###//
	this->addSprite(componentSprite[0], 2, pokeLeftX, WindowYPokemon+100, sf::Vector2f(3, 3), 34, 1, 27, 29, false, "GneuGneu", false);
	this->addSprite(componentSprite[1], 2, pokeRightX - 200, WindowYPokemon - 100, sf::Vector2f(3, 3), 4, 1057, 154, 119, false, "Gneneu", false);
	//### ~Pokemon ###//
	
	//groudon (componentSprite[1], 2, pokeRightX-200, WindowY-100, sf::Vector2f(3, 3), 4, 1057, 154, 119, false, "Gneneu");
	//gitan (componentSprite[0], 2, pokeRightX, WindowY+100, sf::Vector2f(3, 3), 195, 401, 42, 31, false, "Gneneu", false);

	//### Box Info ###//
	this->addSprite(componentSprite[2], 3, pokeLeftX-100, WindowYPokemon-200, sf::Vector2f(1.5, 1.5), 46, 32, 270, 54, false, "InfoPokemonPlayer", false);
	this->addSprite(componentSprite[2], 3, pokeRightX - 200, WindowYPokemon - 200, sf::Vector2f(1.5, 1.5), 46, 32, 270, 54, false, "InfoPokemonNP", false);
	//### ~Box Info ###//

	//### Name Pokemon ###//
	this->addText(componentText[0], sf::Color::Black, 3, "GneGne", pokeLeftX - 80, WindowYPokemon - 200, 40, false);
	this->addText(componentText[1], sf::Color::Black, 3, "Les gitans", pokeRightX - 180, WindowYPokemon - 200, 40, false);
	//### ~Name Pokemon ###//

	//### Lvl Pokemon ###//
	int lvl = 16;
	std::string lvlSting = "Lv" + std::to_string(lvl);
	std::cout << lvlSting << std::endl;
	this->addText(componentText[2], sf::Color::Black, 3, lvlSting, pokeLeftX + 240, WindowYPokemon - 200, 35, false);

	lvl = 5;
	lvlSting = "Lv" + std::to_string(lvl);
	std::cout << lvlSting << std::endl;
	this->addText(componentText[3], sf::Color::Black, 3, lvlSting, pokeRightX + 140, WindowYPokemon - 200, 35, false);
	//### ~Lvl Pokemon ###//
	
	//### HP ###//
	this->addSprite(componentSprite[3], 4, pokeLeftX + 40, WindowYPokemon - 145, sf::Vector2f(0.5, 0.5), 2, 243, 509, 19, false, "hpPlayer", true);
	this->addSprite(componentSprite[3], 4, pokeRightX - 60, WindowYPokemon - 145, sf::Vector2f(0.5, 0.5), 2, 243, 509, 19, false, "hpNP", true);
	//### ~HP ###//

	//### HP barre ###//
	this->addRect(componentRect[0], sf::Color::Green, pokeLeftX + 98, WindowYPokemon - 145, sf::Vector2f(194, 10));
	this->addRect(componentRect[0], sf::Color::Green, pokeRightX - 2, WindowYPokemon - 145, sf::Vector2f(194, 10));
	//### ~HP barre ###//

	this->createButton(componentText[1], sf::Color::Black, sf::Color::Yellow, 3, "Skill 1",
		1/(this->window->getSize().x - 100), this->window->getSize().y - 100, 100, 25,
		25, componentButton[0], "Attack", 3, sf::Vector2f(0.25, 0.25),
		15, 13, 435, 434, false);
}
