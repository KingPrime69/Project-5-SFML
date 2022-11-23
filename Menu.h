#pragma once

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>


#define MAX_NUMBER_OF_ITEMS 4
class Menu
{

public:
	std::array<sf::Text, MAX_NUMBER_OF_ITEMS> componentTextList;
	int initComponent(float width, float height);

private:
	sf::Font title;
	sf::Font title2;
	sf::Text componentText[MAX_NUMBER_OF_ITEMS];
};

