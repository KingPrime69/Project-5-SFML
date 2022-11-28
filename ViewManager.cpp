#include "ViewManager.h"

ViewManager::ViewManager(sf::RenderWindow *window)
{
	this->window = window;
	this->view.push(new Menu(this->window));
	//this->menu = new Menu(this->window);
}

ViewManager::~ViewManager()
{

}

void ViewManager::initView()
{
	this->view.push(new Test(this->window));
	//this->view.top().
	//this->menu->initComponent();
}

void ViewManager::drawCurrentView()
{
	this->view.top()->draw();
	//this->menu->draw();
}
