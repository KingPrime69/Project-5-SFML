#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

#define WINDOW_BAR 31

class SpriteCreator
{
public:
	SpriteCreator(sf::RenderWindow* window);
	~SpriteCreator();

	int initTexture();

	void addSprite(sf::Sprite buttonSPrite, sf::Color colorHover, int bgTexture,
		float x, float y, sf::Vector2f size, int rectLeft, int rectTop, int rectWidth,
		int rectHeight, bool alignCenter);

	void draw();
protected:
	sf::RenderWindow* window;
	std::map<std::string, SpriteCreator*> componentButtonList;
private:
	sf::Sprite Sprite;
	sf::Texture textureList[2];

};

