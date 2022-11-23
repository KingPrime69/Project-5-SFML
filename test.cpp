#include "test.h"

int test::initComponent()
{
	if (!texture.loadFromFile("sprite/Sprite-Starter.png"))return EXIT_FAILURE;

	componentSprite[0].setTexture(texture);
	componentSprite[0].setTextureRect(sf::IntRect(1, 0, 13, 16));
	componentSprite[0].scale(5, 5);
	componentSprite[0].setPosition(500, 100);

	componentSprite[1].setTexture(texture);
	componentSprite[1].setTextureRect(sf::IntRect(66, 1, 13, 16));
	componentSprite[1].scale(5, 5);
	componentSprite[1].setPosition(600, 100);


	componentSprite[2].setTexture(texture);
	componentSprite[2].setTextureRect(sf::IntRect(130, 0, 13, 16));
	componentSprite[2].scale(5, 5);
	componentSprite[2].setPosition(700, 100);

	for (unsigned int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		compSpriteList[i] = componentSprite[i];
	}
}
