#include "Game.h"

Game::Game(void) : window(sf::VideoMode(1200, 800), "Pokiiiiimon")
{
	this->window.setFramerateLimit(60);
}

void Game::setWindow(int width, int height, const char* windowName)
{
	this->window.setSize(sf::Vector2u(width, height));
}


bool Game::isOpen(void) const
{
    return this->window.isOpen();
}

void Game::handleEvents(void)
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window.close();
    }
}

void Game::drawSprite(sf::Sprite sprite)
{
    this->window.draw(sprite);
}

void Game::drawText(sf::Text text)
{
    this->window.draw(text);
}

void Game::clear(void)
{
    this->window.clear();
}

void Game::display(void)
{
    this->window.display();
}

sf::Vector2u Game::getSize()
{
    return this->window.getSize();
}



