#include "InterfaceTemplate.h"

InterfaceTemplate::InterfaceTemplate(sf::RenderWindow* window) : Button(window)
{
	this->window = window;
	InitFont();
	InitBackground();
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
	if (!fontList[2].loadFromFile("ortemmn.ttf"))return EXIT_FAILURE;
	return 0;
}

void InterfaceTemplate::createButton(sf::Text content, sf::Color color, sf::Color colorHovere, int font, const char* text,
	float x, float y, float xIncrement, float yIncrement, int sizeText, sf::Sprite buttonSPrite, const char* buttonName, 
	int bgTexture, sf::Vector2f sizeBox, int rectLeft, int rectTop, int rectWidth, int rectHeight, bool alignCenter)
{
	componentButtonList[buttonName] = new Button(this->window);
	addText(content, color, font, text, x+xIncrement, y+yIncrement, sizeText, alignCenter);
	componentButtonList[buttonName]->setBox(&componentTextList.back(), buttonSPrite, colorHovere, bgTexture, x, y, sizeBox,
	rectLeft, rectTop, rectWidth, rectHeight, buttonName, alignCenter);
}

const char* InterfaceTemplate::getActionButton()
{
	if (!componentButtonList.empty())
	{
		for (auto& i : componentButtonList)
		{
			if (i.second->isPressed())
				return i.second->getAction();
		}
	}
	return nullptr;
}


void InterfaceTemplate::addText(sf::Text content, sf::Color color, int font, const char* text,
	float x, float y, int size, bool alignCenter)
{
	componentTextList.push_back(content);
	componentTextList.back().setFont(fontList[font]);
	componentTextList.back().setFillColor(color);
	componentTextList.back().setString(text);
	componentTextList.back().setCharacterSize(size);

	if (alignCenter) 
	{
		int calcCenter = (this->window->getSize().x - componentTextList.back().getGlobalBounds().width)/2;
		componentTextList.back().setPosition(calcCenter, y);
	}
	else componentTextList.back().setPosition(x,y);
}


int InterfaceTemplate::InitBackground()
{
	if (!bgTextureList[0].loadFromFile("sprite/StartBg.jpg"))return EXIT_FAILURE;
	return 0;
}

void InterfaceTemplate::createBackground(int backgroungTexture)
{
	this->background.setTexture(bgTextureList[backgroungTexture]);
	float xBG = this->background.getTexture()->getSize().x;
	float xWIN = this->window->getSize().x;
	float xScale = xWIN / xBG;
	float yBG = this->background.getTexture()->getSize().y;
	float yWIN = this->window->getSize().y;
	float yScale = yWIN / yBG;
	this->background.setScale(xScale, yScale);
}

void InterfaceTemplate::getCurrentView()
{
}


void InterfaceTemplate::draw()
{
	if (this->background.getTexture()) {
		this->window->draw(this->background);
	}
	if (!componentButtonList.empty())
	{
		for (auto& i : componentButtonList)
		{
			i.second->update();
		}
	}
	if (!componentTextList.empty()) {
		for (unsigned int i = 0; i < componentTextList.size(); i++)
			this->window->draw(componentTextList[i]);
	}
}

