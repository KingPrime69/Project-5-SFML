#pragma once

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "ViewCreator.h"

#define MAX_NUMBER_OF_TEXT 4
#define MAX_NUMBER_OF_SPRITE 4
class CombatTemplate : public ViewCreator
{
public:
	CombatTemplate(sf::RenderWindow* window);
	~CombatTemplate();

	void setBackgroud(int backgroundTexture);

	void setSpritePokemonPlayer();
	void setInfoPokemonPlayer();

	void setSpritePokemonNP();
	void setInfoPokemonNP();

	void initComponent();

protected:



private:
	std::array <sf::Sprite, MAX_NUMBER_OF_SPRITE> componentSprite;
	std::array <sf::Text, MAX_NUMBER_OF_TEXT> componentText;
	bool showMenu;

};

