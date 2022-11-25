#pragma once

#include <iostream>


#include <SFML/Graphics.hpp>




class WindowManager
{
public:
    WindowManager(void);
	void setWindow(int width, int height, const char* windowName);
    bool isOpen(void) const;
    void handleEvents(void);
    void drawSprite(sf::Sprite sprite);
    void drawText(sf::Text text);
    void clear(void);
    void render();
    void display(void);

    sf::Vector2u getSize();



private:
	sf::RenderWindow window;
};
