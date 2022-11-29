#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

#define WINDOW_BAR 31

class DropDown
{
public:
	DropDown(sf::RenderWindow* window);
	~DropDown();

	int initTexture();

	void setDropdown(int background, );

	void draw();

	const char* getAction();
	float getXsize();
	float getYsize();


	bool isPressed();
	bool isHover();
	void update();
protected:
	sf::RenderWindow* window;
	std::map<sf::Text, DropDown*> componentTextList;
	const char* action;
private:
	sf::Keyboard keyboard;
	sf::Text* text;
	sf::Texture bgDropDownList[1];

};


