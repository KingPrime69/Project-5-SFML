#pragma once

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "ViewTemplate.h"


#define MAX_NUMBER_OF_TEXT 4
#define MAX_NUMBER_OF_SPRITE 4
class InGame : public ViewTemplate
{
public:
	InGame(sf::RenderWindow* window, bool menu);
	~InGame();


	void initComponent();

private:
	sf::Sprite componentButton[MAX_NUMBER_OF_SPRITE];
	std::array <sf::Text, MAX_NUMBER_OF_TEXT> componentText;
	bool showMenu;
};