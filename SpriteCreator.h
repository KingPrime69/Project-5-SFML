#pragma once

#include <iostream>
#include <map>
#include <array>
#include <SFML/Graphics.hpp>

#define WINDOW_BAR 31
#define MAX_SPRITE 5
class SpriteCreator
{
public:
	SpriteCreator(sf::RenderWindow* window);
	~SpriteCreator();

	int initTexture();

	void addSprite(sf::Sprite buttonSPrite, int bgTexture,
		float x, float y, sf::Vector2f size, int rectLeft, int rectTop, int rectWidth,
		int rectHeight, bool alignCenter);

	void draw();
protected:
	sf::RenderWindow* window;
	std::map<std::string, SpriteCreator*> componentSpriteList;
	std::map<std::string, SpriteCreator*> componentSpriteHover;
private:
	sf::Sprite Sprite;
	std::array <sf::Texture, MAX_SPRITE> textureList;

};

