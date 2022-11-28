#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Button.h"

class InterfaceTemplate : public Button
{
public:
	InterfaceTemplate(sf::RenderWindow* window);
	~InterfaceTemplate();

	int InitFont();
	void createButton(sf::Text content, sf::Color color, int font,
		const char* text, float x, float y, int sizeText,
		sf::Sprite buttonSPrite, const char* buttonName, int bgTexture, int sizeBox,
		int rectLeft, int rectTop, int rectWidth, int rectHeight, bool alignCenter);

	const char* getActionButton();


	void addText(sf::Text content, sf::Color color, int font, 
		const char* text, float x, float y, int size, bool alignCenter);


	int InitBackground();
	void createBackground(int backgroungTexture);


	void draw();


protected:
	sf::RenderWindow* window;
	std::vector<sf::Text> componentTextList;
private:
	sf::Texture bgTextureList[1];
	sf::Sprite background;
	sf::Font fontList[2];
	sf::Font pokemonSolid;
	sf::Font pokemonHollow;
};

