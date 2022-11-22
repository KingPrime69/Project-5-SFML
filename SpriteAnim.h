#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class SpriteAnim
{
public:
	SpriteAnim();
	~SpriteAnim();

	int createSprite(int x, int y, int width, int height, int pX, int pY);
	void playAnim(int increment);



private:

};

