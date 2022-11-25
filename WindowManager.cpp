#include "WindowManager.h"

WindowManager::WindowManager(void) : window(sf::VideoMode(1200, 800), "Pokiiiiimon")
{
	this->window.setFramerateLimit(60);
}

void WindowManager::setWindow(int width, int height, const char* windowName)
{
	this->window.setSize(sf::Vector2u(width, height));
}


bool WindowManager::isOpen(void) const
{
    return this->window.isOpen();
}

void WindowManager::handleEvents(void)
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window.close();
    }
}

void WindowManager::drawSprite(sf::Sprite sprite)
{
    this->window.draw(sprite);
}

void WindowManager::drawText(sf::Text text)
{
    this->window.draw(text);
}

void WindowManager::clear(void)
{
    this->window.clear();
}

void WindowManager::render()
{

}

void WindowManager::display(void)
{
    this->window.display();
}

sf::Vector2u WindowManager::getSize()
{
    return this->window.getSize();
}



