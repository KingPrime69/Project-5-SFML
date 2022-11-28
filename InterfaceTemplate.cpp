#include "InterfaceTemplate.h"

InterfaceTemplate::InterfaceTemplate(sf::RenderWindow* window) : Button(window)
{
	this->window = window;
	InitFont();
}

InterfaceTemplate::~InterfaceTemplate()
{
}

int InterfaceTemplate::InitFont()
{
	if (!pokemonSolid.loadFromFile("pokemonSolid.ttf"))return EXIT_FAILURE;
	fontList[0] = pokemonSolid;
	if (!pokemonHollow.loadFromFile("pokemonHollow.ttf"))return EXIT_FAILURE;
	fontList[1] = pokemonHollow;
	return 0;
}

void InterfaceTemplate::createButton(sf::Text content, sf::Color color, int font, const char* text,
	float x, float y, int sizeText, 
	sf::Sprite buttonSPrite, const char* buttonName, int bgTexture, int sizeBox)
{
	componentButtonList[buttonName] = new Button(this->window);
	componentButtonList[buttonName]->setBox(buttonSPrite, bgTexture, x, y, sizeBox);
	addText(content, color, font, text, x+20, y+10, sizeText);
}

void InterfaceTemplate::addText(sf::Text content, sf::Color color, int font, const char* text,
	float x, float y, int size)
{
	componentTextList.push_back(content);
	componentTextList.back().setFont(fontList[font]);
	componentTextList.back().setFillColor(color);
	componentTextList.back().setString(text);
	componentTextList.back().setPosition(x,y);
	componentTextList.back().setCharacterSize(size);
}

void InterfaceTemplate::draw()
{
	if (!componentButtonList.empty())
	{
		for (auto& i : componentButtonList)
		{
			i.second->draw();
		}
	}
	if (!componentTextList.empty()) {
		for (unsigned int i = 0; i < componentTextList.size(); i++)
			this->window->draw(componentTextList[i]);
	}
}