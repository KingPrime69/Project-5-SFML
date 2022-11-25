#pragma once

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "WindowManager.h"

#define MAX_NUMBER_OF_ITEMS 4
class ViewManager
{
public:

	ViewManager(WindowManager *window);
	~ViewManager();

	void initView();
	void drawCurrentView();


	std::array<sf::Text, MAX_NUMBER_OF_ITEMS> componentTextList;

private:
	WindowManager *window;
	std::string viewName;
};

