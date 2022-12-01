#pragma once

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "ViewCreator.h"

#define MAX_NUMBER_OF_TEXT 5
#define MAX_NUMBER_OF_SPRITE 5
#define MAX_NUMBER_OF_RECT 2
#define MAX_NUMBER_OF_RECT 4
class CombatTemplate : public ViewCreator
{
public:
	CombatTemplate(sf::RenderWindow* window);
	~CombatTemplate();

	void initView(const char* namePokePlayer, int spritePlayerX, int spritePlayerY, 
		int spritePlayerW, int spritePlayerH, int increPokePlayerX, int increPokePlayerY, 
		int lvlPokePlayer, const char* Skill1, const char* Skill2, const char* Skill3, 
		const char* Skill4, const char* namePokeNP, int spriteNPX, int spriteNPY, int spriteNPW,
		int spriteNPH, int increNPX, int increNPY, int lvlPokeNP);



protected:



private:
	std::array <sf::Sprite, MAX_NUMBER_OF_SPRITE> componentSprite;
	std::array <sf::Text, MAX_NUMBER_OF_TEXT> componentText;
	std::array <sf::RectangleShape, MAX_NUMBER_OF_RECT> componentRect;
	std::array <sf::Sprite, MAX_NUMBER_OF_RECT> componentButton;
	bool showMenu;

};

