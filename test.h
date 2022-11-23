#pragma once

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3
class test
{
public:
	std::array<sf::Sprite, MAX_NUMBER_OF_ITEMS> compSpriteList;
	int initComponent();

private:
	sf::Texture texture;
	sf::Sprite componentSprite[MAX_NUMBER_OF_ITEMS];
};

