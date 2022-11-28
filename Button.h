#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

#define WINDOW_BAR 31

class Button
{
public:
	Button(sf::RenderWindow* window);
	~Button();

	int initTexture();

	void setBox(sf::Text* text, sf::Sprite buttonSPrite, 
		int bgTexture, float x, float y, int size,
		int rectLeft, int rectTop, int rectWidth, int rectHeight,
		const char* action, bool alignCenter);

	void draw();

	const char* getAction();
	bool isPressed();
	bool isHover();
	void update();
protected:
	sf::RenderWindow* window;
	std::map<std::string, Button*> componentButtonList;
	const char* action;
private:
	sf::Text* text;
	sf::RectangleShape rectButton;
	sf::Mouse mouse;
	sf::Sprite Sprite;
	sf::Texture bgButtonList[1];

};

