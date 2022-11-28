#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "InterfaceTemplate.h"

#define MAX_NUMBER_OF_ITEMS 2
class Test : public InterfaceTemplate
{
public:
	Test(sf::RenderWindow* window);
	~Test();


	void initComponent();

private:

	sf::Text componentText[MAX_NUMBER_OF_ITEMS];

};