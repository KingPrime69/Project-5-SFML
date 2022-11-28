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

void ViewManager::swapView()
{
	if (this->view.top()->getActionButton() != nullptr) 
	{
		const char* action = this->view.top()->getActionButton();
		std::cout << action << std::endl;

		//### put view with here name action here ###//
		if (action == "Start") this->view.push(new Test(this->window));
	}
	//this->view.push(new Test(this->window));
	//this->view.top().
	//this->menu->initComponent();
}

void ViewManager::drawCurrentView()
{
	this->view.top()->draw();
	//this->menu->draw();
}
