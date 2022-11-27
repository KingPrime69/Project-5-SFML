#pragma once

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>

#include "Menu.h"

class ViewManager
{
public:

	ViewManager(sf::RenderWindow *window);
	~ViewManager();

	void initView();
	void drawCurrentView();



private:
	//Menu* menu;
	std::stack<InterfaceTemplate*> view;
	sf::RenderWindow *window;
};

