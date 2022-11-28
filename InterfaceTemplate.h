#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Button.h"

class InterfaceTemplate : public Button
{
public:
	InterfaceTemplate(sf::RenderWindow* window);
	InterfaceTemplate();
	~InterfaceTemplate();

	int InitFont();
	void createButton(sf::Text content, sf::Color color, int font,
		const char* text, float x, float y, int size);
	void addText(sf::Text content, sf::Color color, int font, const char* text,
		float x, float y, int size);

	void draw();


protected:
	sf::RenderWindow* window;
	std::vector<sf::Text> componentTextList;
private:
	sf::Font fontList[2];
	sf::Font pokemonSolid;
	sf::Font pokemonHollow;
};

