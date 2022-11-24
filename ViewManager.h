#pragma once

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>

class ViewManager
{
public:
	ViewManager(sf::RenderWindow *window);
	void initView(float width, float height);
private:
	sf::RenderWindow* window;

};

