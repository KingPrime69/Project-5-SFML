#pragma once

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "InGame.h"

class ViewManager
{
public:

	ViewManager(sf::RenderWindow *window);
	~ViewManager();

	void updateKeytime();
	bool getKeytime();

	void swapView();
	void drawCurrentView();



private:
	//Menu* menu;
	std::stack<ViewTemplate*> view;
	sf::RenderWindow *window;
	sf::Keyboard keyboard;
	std::string currentView;
	bool showMenuInGame;

	float MaxKeytime;
	float Keytime;

	bool avaible;
};

