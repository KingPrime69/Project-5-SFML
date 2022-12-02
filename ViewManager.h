#pragma once

#include <iostream>
#include <stack>
#include <array>
#include <SFML/Graphics.hpp>

#include "Menu.h"
#include "InGame.h"
#include "Combat.h"

class ViewManager
{
public:

	ViewManager(sf::RenderWindow *window);
	~ViewManager();

	void updateKeytime();
	bool getKeytime();

	void SwapViewKeyboard();
	void swapViewButton();


	void drawCurrentView();



private:
	//Menu* menu;
	std::stack<ViewCreator*> view;
	sf::RenderWindow *window;
	sf::Keyboard keyboard;
	std::string currentView;
	bool showMenuInGame;

	float MaxKeytime;
	float Keytime;

	Pokemon pokemonPlayer;
	Pokemon pokemonEnemy;
	std::array <std::string, 4> nameMoveList;
	Combat* combatLogic;

	bool avaible;
};

