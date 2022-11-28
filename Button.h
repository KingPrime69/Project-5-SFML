#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(sf::RenderWindow* window);
	~Button();

	void setBox();

	bool isPressed();
	bool isHover();
	void update();
protected:
	sf::RenderWindow* window;
	std::map<std::string, Button*> componentButtonList;
private:
};

