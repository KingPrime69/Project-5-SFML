#include "CombatTemplate.h"

CombatTemplate::CombatTemplate(sf::RenderWindow* window) : ViewCreator(window)
{
	this->window = window;
	initView("Gnegne", 34, 1, 27, 29, 0, 0, 150,
		"Taper", "Magical Leaf", "Magical Leaf tes", "Trisomie",
		"Les gitans", 195, 401, 42, 31, 0, 0,5);
}

CombatTemplate::~CombatTemplate()
{
}

void CombatTemplate::initView(const char* namePokePlayer, int spritePlayerX, int spritePlayerY, int spritePlayerW, int spritePlayerH,
	int increPokePlayerX, int increPokePlayerY, int lvlPokePlayer,
	const char* Skill1, const char* Skill2, const char* Skill3, const char* Skill4,
	const char* namePokeNP, int spriteNPX, int spriteNPY, int spriteNPW, int spriteNPH, int increNPX, int increNPY, int lvlPokeNP)
{
	this->createBackground(1);

	int WindowYPokemon = this->window->getSize().y / 2-100;
	int pokeLeftX = this->window->getSize().x / 7;
	int pokeRightX = this->window->getSize().x - 275;

	//### Pokemon ###//
	//34, 1, 27, 29,
	this->addSprite(componentSprite[0], 2, pokeLeftX + increPokePlayerX, WindowYPokemon + 100 + increPokePlayerY, 
		sf::Vector2f(3, 3), spritePlayerX, spritePlayerY, spritePlayerW, spritePlayerH, false, namePokePlayer, false);
	this->addSprite(componentSprite[1], 2, pokeRightX + increNPX, WindowYPokemon + 100 + increNPY, sf::Vector2f(3, 3), spriteNPX,
		spriteNPY, spriteNPW, spriteNPH, 
		false, namePokeNP, false);
	//### ~Pokemon ###//
	
	//groudon (componentSprite[1], 2, pokeRightX-200, WindowYPokemon-100, sf::Vector2f(3, 3), 4, 1057, 154, 119, false, "Gneneu");
	//gitan (componentSprite[0], 2, pokeRightX, WindowYPokemon+100, sf::Vector2f(3, 3), 195, 401, 42, 31, false, "Gneneu", false);

	//### Box Info ###//
	this->addSprite(componentSprite[2], 3, pokeLeftX-100, WindowYPokemon-200, sf::Vector2f(1.5, 1.5), 46, 32, 270, 54, false, "InfoPokemonPlayer", false);
	this->addSprite(componentSprite[2], 3, pokeRightX - 200, WindowYPokemon - 200, sf::Vector2f(1.5, 1.5), 46, 32, 270, 54, false, "InfoPokemonNP", false);
	//### ~Box Info ###//

	//### Name Pokemon ###//
	this->addText(componentText[0], sf::Color::Black, 3, namePokePlayer, pokeLeftX - 80, WindowYPokemon - 200, 40, false);
	this->addText(componentText[1], sf::Color::Black, 3, namePokeNP, pokeRightX - 180, WindowYPokemon - 200, 40, false);
	//### ~Name Pokemon ###//

	//### Lvl Pokemon ###//
	std::string lvlSting = "Lv" + std::to_string(lvlPokePlayer);
	std::cout << lvlSting << std::endl;
	this->addText(componentText[2], sf::Color::Black, 3, lvlSting, pokeLeftX + 240, WindowYPokemon - 200, 35, false);


	lvlSting = "Lv" + std::to_string(lvlPokeNP);
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

	int skillX = 1 / this->window->getSize().x + 50;
	int skillY = this->window->getSize().y - 200;

	int sizeBoxY = 1.75;
	this->addText(componentText[2], sf::Color::Black, 3, "Attaque :", skillX + 25, skillY - 75, 50, false);
	this->createButton(componentText[1], sf::Color::Black, sf::Color::Red, 3, Skill1,
		skillX, skillY, 40, 25, 30, componentButton[0], Skill1, 3, sf::Vector2f(0.75, 1.75),
		46, 32, 270, 54, false);
	this->createButton(componentText[2], sf::Color::Black, sf::Color::Red, 3, Skill2,
		skillX, skillY + 90, 40, 25, 30, componentButton[1], Skill2, 3, sf::Vector2f(0.75, 1.75),
		46, 32, 270, 54, false);
	this->createButton(componentText[3], sf::Color::Black, sf::Color::Red, 3, Skill3,
		skillX + 250, skillY, 40, 25, 30, componentButton[2], Skill3, 3, sf::Vector2f(0.75, 1.75),
		46, 32, 270, 54, false);
	this->createButton(componentText[4], sf::Color::Black, sf::Color::Red, 3, Skill4,
		skillX + 250, skillY + 90, 40, 25, 30, componentButton[3], Skill4, 3, sf::Vector2f(0.75, 1.75),
		46, 32, 270, 54, false);
}
