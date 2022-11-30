#include "ViewTemplate.h"

ViewTemplate::ViewTemplate(sf::RenderWindow* window) : Button(window)
{
	this->window = window;
	this->pos = 0;
	this->length = 0;
	this->posMin = 0;
	this->one = false;
	this->MaxKeytime = 1.f;
	InitFont();
	InitBackground();
}

ViewTemplate::~ViewTemplate()
{
}

int ViewTemplate::InitFont()
{
	if (!pokemonSolid.loadFromFile("pokemonSolid.ttf"))return EXIT_FAILURE;
	fontList[0] = pokemonSolid;
	if (!pokemonHollow.loadFromFile("pokemonHollow.ttf"))return EXIT_FAILURE;
	fontList[1] = pokemonHollow;
	if (!fontList[2].loadFromFile("ortemmn.ttf"))return EXIT_FAILURE;
	return 0;
}

void ViewTemplate::createButton(sf::Text content, sf::Color color, sf::Color colorHovere, int font, const char* text,
	float x, float y, float xIncrement, float yIncrement, int sizeText, sf::Sprite buttonSPrite, const char* buttonName, 
	int bgTexture, sf::Vector2f sizeBox, int rectLeft, int rectTop, int rectWidth, int rectHeight, bool alignCenter)
{
	componentButtonList[buttonName] = new Button(this->window);
	addButtonText(content, color, font, text, x+xIncrement, y+yIncrement, sizeText, alignCenter, buttonName);
	componentButtonList[buttonName]->setBox(&componentTextList.back(), buttonSPrite, colorHovere, bgTexture, x, y, sizeBox,
	rectLeft, rectTop, rectWidth, rectHeight, buttonName, alignCenter);
	this->colorHover = colorHovere;
}

const char* ViewTemplate::getActionButton()
{
	if (!componentButtonTextList.empty())
	{
		if(this->keyboard.isKeyPressed(this->keyboard.Enter))
		return buttonActionList[this->pos];
	}
	return nullptr;
}


void ViewTemplate::addText(sf::Text content, sf::Color color, int font, const char* text,
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

void ViewTemplate::addButtonText(sf::Text content, sf::Color color, int font, const char* text,
	float x, float y, int size, bool alignCenter, const char* action)
{
	componentButtonTextList.push_back(content);
	componentButtonTextList.back().setFont(fontList[font]);
	componentButtonTextList.back().setFillColor(color);
	componentButtonTextList.back().setString(text);
	componentButtonTextList.back().setCharacterSize(size);
	buttonActionList.push_back(action);
	if (alignCenter)
	{
		int calcCenter = (this->window->getSize().x - componentButtonTextList.back().getGlobalBounds().width) / 2;
		componentButtonTextList.back().setPosition(calcCenter, y);
	}
	else componentButtonTextList.back().setPosition(x, y);
}

int ViewTemplate::InitBackground()
{
	if (!bgTextureList[0].loadFromFile("sprite/StartBg.jpg"))return EXIT_FAILURE;
	return 0;
}

void ViewTemplate::createBackground(int backgroungTexture)
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

void ViewTemplate::updateKeytime()
{
	if (this->Keytime < this->MaxKeytime)
		this->Keytime += 0.08f;
}

bool ViewTemplate::getKeytime()
{
	if (this->Keytime >= this->MaxKeytime)
	{
		this->Keytime = 0.f;
		return true;
	}
	return false;
}

void ViewTemplate::initSelect()
{
	this->length = componentButtonTextList.size();
	this->posMin = 0;
	this->pos = 0;
	componentButtonTextList[pos].setOutlineColor(this->colorHover);
	componentButtonTextList[pos].setOutlineThickness(5);
	std::cout << "lenght : " << length << std::endl;
	std::cout << "posMin : " << posMin << std::endl;
	std::cout << "pos : " << this->pos << std::endl;
	this->one = true;
}

void ViewTemplate::selectedButton()
{
	if (this->one == false && !componentButtonList.empty()) this->initSelect();

	if(this->keyboard.isKeyPressed(this->keyboard.S) && !componentButtonList.empty()) 
	{
		this->avaible = this->getKeytime();
		if (this->pos < length-1 && avaible)
		{
			++this->pos;
			int posN = this->pos - 1;
			componentButtonTextList[this->pos].setOutlineColor(this->colorHover);
			componentButtonTextList[this->pos].setOutlineThickness(5);
			componentButtonTextList[posN].setOutlineThickness(0);
		}
	}

	if (this->keyboard.isKeyPressed(this->keyboard.Z) && !componentButtonList.empty())
	{
		this->avaible = this->getKeytime();
		if (this->pos > posMin && avaible)
		{
			--this->pos;
			componentButtonTextList[this->pos].setOutlineThickness(5);
			componentButtonTextList[this->pos + 1].setOutlineThickness(0);
		}
	}
}


void ViewTemplate::draw()
{
	updateKeytime();
	selectedButton();
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
	if (!componentButtonTextList.empty()) {
		for (unsigned int i = 0; i < componentButtonTextList.size(); i++)
			this->window->draw(componentButtonTextList[i]);
	}
}

