#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>

#include "SpriteCreator.h"

class ViewCreator : public SpriteCreator
{
public:
	ViewCreator(sf::RenderWindow* window);
	~ViewCreator();

	int InitFont();
	void createButton(sf::Text content, sf::Color color, 
		sf::Color colorHovere, int font, std::string text, float x,
		float y, float xIncrement, float yIncrement, int sizeText, 
		sf::Sprite buttonSPrite, std::string buttonName, int bgTexture,
		sf::Vector2f sizeBox,int rectLeft, int rectTop, int rectWidth,
		int rectHeight, bool alignCenter);

	void addText(sf::Text content, sf::Color color, int font, 
		std::string text, float x, float y, int size, bool alignCenter);

	void addButtonText(sf::Text content, sf::Color color, int font,
		std::string text, float x, float y, int size, bool alignCenter,
		std::string action);

	void addSprite(sf::Sprite buttonSPrite, int bgTexture, float x,
		float y, sf::Vector2f size, int rectLeft, int rectTop, int rectWidth, 
		int rectHeight, bool alignCenter, const char* name, bool hover);

	void addRect(sf::RectangleShape rect, sf::Color color,float x, float y, 
		sf::Vector2f size);


	int InitBackground();
	void createBackground(int backgroungTexture);

	void updateKeytime();
	bool getKeytime();

	void initSelect();
	void selectedButton();
	std::string getActionButton();

	void draw();


protected:
	sf::RenderWindow* window;
	std::vector<sf::Text> componentTextList;
	std::vector<sf::Text> componentButtonTextList;
	std::vector<sf::RectangleShape> componentRectList;
private:
	sf::Texture bgTextureList[2];
	sf::Sprite background;
	std::array <sf::Font, 4> fontList;
	sf::Font pokemonSolid;
	sf::Font pokemonHollow;

	sf::Keyboard keyboard;
	int pos;
	int length;
	int posMin;
	bool one;

	float MaxKeytime;
	float Keytime;

	bool avaible;

	std::vector<std::string> buttonActionList;
	sf::Color colorHover;
};

