#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "WindowManager.h"
#include "ViewManager.h"

class Menu : public ViewManager
{
public:
	Menu(WindowManager* window);
	~Menu();


	int initComponent();
	void draw();

private:
	sf::Font title;
	sf::Font title2;
	sf::Text componentText[MAX_NUMBER_OF_ITEMS];

	WindowManager* window;
};

