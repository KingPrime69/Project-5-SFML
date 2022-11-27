#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


class InterfaceTemplate
{
public:
	InterfaceTemplate(sf::RenderWindow* window);
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

