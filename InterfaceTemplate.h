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
	void createButton(sf::Text content, sf::Color color, 
		sf::Color colorHovere, int font, const char* text, float x, 
		float y, float xIncrement, float yIncrement, int sizeText, 
		sf::Sprite buttonSPrite, const char* buttonName, int bgTexture,
		sf::Vector2f sizeBox,int rectLeft, int rectTop, int rectWidth,
		int rectHeight, bool alignCenter);

	const char* getActionButton();


	void addText(sf::Text content, sf::Color color, int font, 
		const char* text, float x, float y, int size, bool alignCenter);
	void addButtonText(sf::Text content, sf::Color color, int font,
		const char* text, float x, float y, int size, bool alignCenter,
		const char* action);


	int InitBackground();
	void createBackground(int backgroungTexture);

	void updateKeytime();
	bool getKeytime();

	void initSelect();
	void selectedButton();

	void draw();


protected:
	sf::RenderWindow* window;
	std::vector<sf::Text> componentTextList;
	std::vector<sf::Text> componentButtonTextList;
private:
	sf::Texture bgTextureList[1];
	sf::Sprite background;
	sf::Font fontList[3];
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

	std::vector<const char*> buttonActionList;
	sf::Color colorHover;
};

