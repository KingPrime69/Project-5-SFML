#pragma once

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "InterfaceTemplate.h"

#define MAX_NUMBER_OF_TEXT 6
#define MAX_NUMBER_OF_SPRITE 2
class Menu : public InterfaceTemplate
{
public:
	Menu(sf::RenderWindow* window);
	~Menu();


	void initComponent();

private:
	sf::Sprite componentButton[MAX_NUMBER_OF_SPRITE];
	std::array <sf::Text, MAX_NUMBER_OF_TEXT> componentText;
};

