#include "SpriteCreator.h"

SpriteCreator::SpriteCreator(sf::RenderWindow* window)
{
	this->window = window;
	this->initTexture();
}

SpriteCreator::~SpriteCreator()
{
	for (auto& i : this->componentSpriteList)
	{
		delete i.second;
	}
}

int SpriteCreator::initTexture()
{
	if (!textureList[0].loadFromFile("sprite/Red-Button.png"))return EXIT_FAILURE;
	if (!textureList[1].loadFromFile("sprite/Fleches.png"))return EXIT_FAILURE;
	if (!textureList[2].loadFromFile("sprite/Sprite-SheetPokemon.png"))return EXIT_FAILURE;
	if (!textureList[3].loadFromFile("sprite/ContainerCombat.png"))return EXIT_FAILURE;
	return 0;
}

void SpriteCreator::addSprite(sf::Sprite buttonSPrite, int bgTexture, float x, 
	float y, sf::Vector2f size, int rectLeft, int rectTop, int rectWidth, int rectHeight, bool alignCenter)
{
	this->Sprite = buttonSPrite;
	this->Sprite.setScale(size);
	this->Sprite.setTexture(textureList[bgTexture]);
	this->Sprite.setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
	this->Sprite.setPosition(x, y);

	if (alignCenter)
	{
		int calcCenter = (this->window->getSize().x - this->Sprite.getGlobalBounds().width) / 2;
		this->Sprite.setPosition(calcCenter, y);
	}
	else
	{
		this->Sprite.setPosition(x, y);
	}
}



void SpriteCreator::draw()
{
	this->window->draw(this->Sprite);
}