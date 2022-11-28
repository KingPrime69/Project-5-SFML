#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "InterfaceTemplate.h"

#define MAX_NUMBER_OF_ITEMS 2
class Menu : public InterfaceTemplate
{
public:
	Menu(sf::RenderWindow* window);
	~Menu();


	void initComponent();

private:

	sf::Text componentText[MAX_NUMBER_OF_ITEMS];

};

