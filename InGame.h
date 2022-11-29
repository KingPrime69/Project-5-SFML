#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "InterfaceTemplate.h"

#define MAX_NUMBER_OF_ITEMS 2
class InGame : public InterfaceTemplate
{
public:
	InGame(sf::RenderWindow* window, bool menu);
	~InGame();


	void initComponent();

private:

	sf::Text componentText[MAX_NUMBER_OF_ITEMS];
	bool showMenu;
};