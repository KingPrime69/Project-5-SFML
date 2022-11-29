#include "ViewManager.h"

ViewManager::ViewManager(sf::RenderWindow *window)
{
	this->window = window;
	this->view.push(new Menu(this->window));
	this->showMenuInGame = false;
	this->MaxKeytime = 1.f;
	this->Keytime = 0.f;
	this->avaible = false;
	//this->menu = new Menu(this->window);
}

ViewManager::~ViewManager()
{
	while (!this->view.empty())
	{
		delete this->view.top();
		this->view.pop();
	}
}

void ViewManager::updateKeytime()
{
	if (this->Keytime < this->MaxKeytime)
		this->Keytime += 0.05f;
	std::cout << Keytime << std::endl;
}

bool ViewManager::getKeytime()
{
	if (this->Keytime >= this->MaxKeytime)
	{
		this->Keytime = 0.f;
		return true;
	}
	return false;
}

void ViewManager::swapView()
{
	if (this->view.top()->getActionButton() != nullptr) 
	{
		const char* action = this->view.top()->getActionButton();

		this->currentView = action;

		//### put view with here name action here ###//
		if (action == "Start")this->view.push(new InGame(this->window, this->showMenuInGame));
	}
	if (this->currentView == "Start" && this->keyboard.isKeyPressed(this->keyboard.Escape) && this->showMenuInGame == false)
	{
		this->avaible = getKeytime();
		if (this->avaible)
		{
			this->showMenuInGame = true;
			this->view.push(new InGame(this->window, this->showMenuInGame));
		}
	}
	if (this->currentView == "Start" && this->keyboard.isKeyPressed(this->keyboard.Escape) && this->showMenuInGame == true)
	{
		this->avaible = getKeytime();
		if (this->avaible)
		{
			delete this->view.top();
			this->view.pop();
			this->showMenuInGame = false;
			this->view.push(new InGame(this->window, this->showMenuInGame));
		}
	}
	//this->view.push(new Test(this->window));
	//this->view.top().
	//this->menu->initComponent();
}

void ViewManager::drawCurrentView()
{
	updateKeytime();
	this->view.top()->draw();
	
	//this->menu->draw();
}
