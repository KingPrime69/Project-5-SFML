#pragma once

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include "Game.h"

class ViewManager
{
public:
	Game game;
	std::stack<ViewManager*> viewManager;
	void initView(float width, float height);
private:
	


};

