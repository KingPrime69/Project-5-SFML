#include "ViewManager.h"

ViewManager::ViewManager(sf::RenderWindow *window)
{
	this->window = window;
	this->view.push(new CombatTemplate(this->window));
	this->showMenuInGame = false;
	this->MaxKeytime = 1.f;
	this->Keytime = 0.f;
	this->avaible = false;
	//this->menu = new Menu(this->window);
	this->currentView = "Start";
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

void ViewManager::SwapViewKeyboard()
{
	//############################//
	//#### ECHAP MENU IN GAME ####//
	//############################//
	if (this->currentView == "Start" && this->keyboard.isKeyPressed(this->keyboard.Escape) && this->showMenuInGame == false)
	{
		this->avaible = getKeytime();
		if (this->avaible)
		{
			this->showMenuInGame = true;
			this->view.push(new InGame(this->window, this->showMenuInGame));
		}
	}
	else if (this->currentView == "Start" && this->keyboard.isKeyPressed(this->keyboard.Escape) && this->showMenuInGame == true)
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
	//#############################//
	//#### ~ECHAP MENU IN GAME ####//
	//#############################//

	//#############################//
	//######## COMBAT VIEW ########//
	//#############################//
	if (this->currentView == "Start" && this->keyboard.isKeyPressed(this->keyboard.C))
	{
		this->avaible = getKeytime();
		if (this->avaible)
		{
			this->view.push(new CombatTemplate(this->window));
		}
	}
}

void ViewManager::swapViewButton()
{
	if (this->view.top()->getActionButton() != "") 
	{
		std::string action = this->view.top()->getActionButton();

		this->currentView = action;

		//### put view with here name action here ###//
		if (action == "Start")this->view.push(new InGame(this->window, this->showMenuInGame));
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
