#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>


class Game
{
public:
	Game(void);
	void setWindow(int width, int height, const char* windowName);
    bool isOpen(void) const;
    void handleEvents(void);
    void drawSprite(sf::Sprite sprite);
    void drawText(sf::Text text);
    void clear(void);
    void display(void);
    void render(void);



private:
	sf::RenderWindow window;
};

