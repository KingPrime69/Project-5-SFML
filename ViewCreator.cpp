#include "ViewCreator.h"

ViewCreator::ViewCreator(sf::RenderWindow* window) : SpriteCreator(window)
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

ViewCreator::~ViewCreator()
{
}

int ViewCreator::InitFont()
{
	if (!pokemonSolid.loadFromFile("pokemonSolid.ttf"))return EXIT_FAILURE;
	fontList[0] = pokemonSolid;
	if (!pokemonHollow.loadFromFile("pokemonHollow.ttf"))return EXIT_FAILURE;
	fontList[1] = pokemonHollow;
	if (!fontList[2].loadFromFile("ortemmn.ttf"))return EXIT_FAILURE;
	if (!fontList[3].loadFromFile("pokemonPixel.ttf"))return EXIT_FAILURE;
	return 0;
}

void ViewCreator::createButton(sf::Text content, sf::Color color, sf::Color colorHovere, int font, std::string text,
	float x, float y, float xIncrement, float yIncrement, int sizeText, sf::Sprite buttonSPrite, std::string buttonName,
	int bgTexture, sf::Vector2f sizeBox, int rectLeft, int rectTop, int rectWidth, int rectHeight, bool alignCenter)
{
	componentSpriteList[buttonName] = new SpriteCreator(this->window);
	addButtonText(content, color, font, text, x+xIncrement, y+yIncrement, sizeText, alignCenter, buttonName);
	componentSpriteList[buttonName]->addSprite(buttonSPrite, bgTexture, x, y, sizeBox,
	rectLeft, rectTop, rectWidth, rectHeight, alignCenter);
	this->colorHover = colorHovere;
}

void ViewCreator::addText(sf::Text content, sf::Color color, int font, std::string text,
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

void ViewCreator::addButtonText(sf::Text content, sf::Color color, int font, std::string text,
	float x, float y, int size, bool alignCenter, std::string action)
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

void ViewCreator::addSprite(sf::Sprite buttonSPrite, int bgTexture,
	float x, float y, sf::Vector2f size, int rectLeft, int rectTop,
	int rectWidth, int rectHeight, bool alignCenter, string name, bool hover)
{
	if (hover == true) {
		componentSpriteHover[name] = new SpriteCreator(this->window);
		componentSpriteHover[name]->addSprite(buttonSPrite, bgTexture, x, y, size,
			rectLeft, rectTop, rectWidth, rectHeight, alignCenter);
	}
	else {
		componentSpriteList[name] = new SpriteCreator(this->window);
		componentSpriteList[name]->addSprite(buttonSPrite, bgTexture, x, y, size,
		rectLeft, rectTop, rectWidth, rectHeight, alignCenter);
	}
}

void ViewCreator::addRect(sf::RectangleShape rect, sf::Color color,float x, float y, 
	sf::Vector2f size, std::string name)
{
	std::cout << "Size X : " << size.x << std::endl;
	componentRectList[name].setPosition(x, y);
	componentRectList[name].setFillColor(color);
	componentRectList[name].setSize(size);
}

int ViewCreator::InitBackground()
{
	if (!bgTextureList[0].loadFromFile("sprite/StartBg.jpg"))return EXIT_FAILURE;
	if (!bgTextureList[1].loadFromFile("sprite/combat.jpg"))return EXIT_FAILURE;
	return 0;
}

void ViewCreator::createBackground(int backgroungTexture)
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

void ViewCreator::updateKeytime()
{
	if (this->Keytime < this->MaxKeytime)
		this->Keytime += 0.08f;
}

bool ViewCreator::getKeytime()
{
	if (this->Keytime >= this->MaxKeytime)
	{
		this->Keytime = 0.f;
		return true;
	}
	return false;
}

void ViewCreator::initSelect()
{
	this->length = componentButtonTextList.size();
	this->posMin = 0;
	this->pos = 0;
	componentButtonTextList[pos].setOutlineColor(this->colorHover);
	componentButtonTextList[pos].setOutlineThickness(5);
	this->one = true;
}

void ViewCreator::selectedButton()
{
	if (this->one == false && !componentSpriteList.empty() && !componentButtonTextList.empty()) this->initSelect();

	if(this->keyboard.isKeyPressed(this->keyboard.S) && !componentSpriteList.empty() && !componentButtonTextList.empty())
	{
		this->avaible = this->getKeytime();
		if (this->pos == length - 1 && avaible)
		{
			this->pos = 0;
			int posN = this->pos + length - 1;
			componentButtonTextList[this->pos].setOutlineColor(this->colorHover);
			componentButtonTextList[this->pos].setOutlineThickness(3);
			componentButtonTextList[posN].setOutlineThickness(0);
		}
		else if (this->pos < length-1 && avaible)
		{
			++this->pos;
			int posN = this->pos - 1;
			componentButtonTextList[this->pos].setOutlineColor(this->colorHover);
			componentButtonTextList[this->pos].setOutlineThickness(3);
			componentButtonTextList[posN].setOutlineThickness(0);
		}
	}

	if (this->keyboard.isKeyPressed(this->keyboard.Z) && !componentSpriteList.empty() && !componentButtonTextList.empty())
	{
		this->avaible = this->getKeytime();
		if (this->pos == 0 && avaible)
		{
			this->pos = length - 1;
			int posP = 0;
			componentButtonTextList[this->pos].setOutlineColor(this->colorHover);
			componentButtonTextList[this->pos].setOutlineThickness(3);
			componentButtonTextList[posP].setOutlineThickness(0);
		}
		else if (this->pos > posMin && avaible)
		{
			--this->pos;
			int posP = this->pos + 1;
			componentButtonTextList[this->pos].setOutlineColor(this->colorHover);
			componentButtonTextList[this->pos].setOutlineThickness(3);
			componentButtonTextList[posP].setOutlineThickness(0);
		}
	}
}

std::string ViewCreator::getActionButton()
{
	if (!componentButtonTextList.empty())
	{
		if (this->keyboard.isKeyPressed(this->keyboard.Enter)) {
			return buttonActionList[this->pos];
		}

	}
	return "";
}

void ViewCreator::updateHp()
{
	if (!componentRectList.empty()) {
			componentRectList.clear();
	}
}




void ViewCreator::draw()
{
	updateKeytime();
	selectedButton();
	if (this->background.getTexture()) {
		this->window->draw(this->background);
	}
	if (!componentSpriteList.empty())
	{
		for (auto& i : componentSpriteList)
		{
			i.second->draw();
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
	if (!componentRectList.empty()) {
		for (auto i : componentRectList)
		{
			//std::cout << i.first << std::endl;
			this->window->draw(componentRectList[i.first]);

		}
	}
	if (!componentSpriteHover.empty())
	{
		for (auto& i : componentSpriteHover)
		{
			i.second->draw();
		}
	}
}

