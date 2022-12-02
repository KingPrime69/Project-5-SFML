#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ViewManager.h"
#include "Entity.h"


class Game
{
public:
	Game();
	~Game();

	void setWindow(int width, int height, const char* windowName);


	sf::Vector2u getSize();


	void handleEvents(void); 

	int run();


	//void drawEntity(const Entity&);

private:
	sf::RenderWindow window;
	ViewManager* viewManager;
};

