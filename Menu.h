#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "InterfaceTemplate.h"

#define MAX_NUMBER_OF_TEXT 5
#define MAX_NUMBER_OF_SPRITE 2
class Menu : public InterfaceTemplate
{
public:
	Menu(sf::RenderWindow* window);
	~Menu();


	void initComponent();

private:
	sf::Sprite componentSprite[MAX_NUMBER_OF_SPRITE];
	sf::Text componentText[MAX_NUMBER_OF_TEXT];
};

