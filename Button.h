#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(sf::RenderWindow* window);
	~Button();

	int initTexture();

	void setBox(sf::Sprite buttonSPrite, int bgTexture, float x, float y, int size);

	void draw();

	bool isPressed();
	bool isHover();
	void update();
protected:
	sf::RenderWindow* window;
	std::map<std::string, Button*> componentButtonList;
private:
	sf::Sprite Sprite;
	sf::Texture bgButtonList[1];
};

