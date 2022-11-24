#include "Window.h"

Window::Window(void) : window(sf::VideoMode(1200, 800), "Pokiiiiimon")
{
	this->window.setFramerateLimit(60);
}

void Window::setWindow(int width, int height, const char* windowName)
{
	this->window.setSize(sf::Vector2u(width, height));
}


bool Window::isOpen(void) const
{
    return this->window.isOpen();
}

void Window::handleEvents(void)
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window.close();
    }
}

void Window::drawSprite(sf::Sprite sprite)
{
    this->window.draw(sprite);
}

void Window::drawText(sf::Text text)
{
    this->window.draw(text);
}

void Window::clear(void)
{
    this->window.clear();
}

void Window::display(void)
{
    this->window.display();
}

sf::Vector2u Window::getSize()
{
    return this->window.getSize();
}



