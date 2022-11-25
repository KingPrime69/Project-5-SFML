#pragma once

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>

#include "WindowManager.h"
#include "ViewManager.h"

#include "Menu.h"

class Game
{
public:
	WindowManager window;
	Game();
	~Game();
	void showView();
	int run();
private:
	std::stack<ViewManager*> viewManagers;

};

