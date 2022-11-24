#pragma once

#include <iostream>
#include <stack>
#include "Window.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();

	Window window;
	std::stack<ViewManager*> viewManager;
	int run();
	void showView();
private:

};

