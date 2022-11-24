#pragma once

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>

#include "Window.h"
#include "ViewManager.h"

class Game : public Window
{
public:
	Game();
	void showView();
	int run();
private:
	std::stack<ViewManager*> viewManagers;

};

