#include "ViewManager.h"

ViewManager::ViewManager(sf::RenderWindow *window)
{
	this->window = window;
	//create pokemon beforehand, should get player pokemon from team (get team in args) and ennemy through random encounter function (not done yet)
	this->pokemonPlayer = Pokemon("Sprigatito", 5);
	this->pokemonPlayer.setMove(1, "Leafage");
	this->pokemonPlayer.setMove(2, "Scratch");
	this->pokemonPlayer.setMove(3, "Tail Whip");
	this->pokemonEnemy = Pokemon("Riolu", 5);
	this->pokemonEnemy.setMove(1, "Leafage");
	this->pokemonEnemy.setMove(2, "Scratch");
	this->pokemonEnemy.setMove(3, "Tail Whip");
	this->view.push(new Combat(this->window, this->pokemonPlayer, this->pokemonEnemy, "none", true));
	//this->view.push(new Menu(this->window));
	this->combatLogic = new Combat(this->window, this->pokemonPlayer, this->pokemonEnemy, "none", true);
	this->showMenuInGame = false;
	this->MaxKeytime = 1.f;
	this->Keytime = 0.f;
	this->avaible = false;
	//this->menu = new Menu(this->window);
	this->currentView = "Combat";
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
			this->currentView = "Combat";
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
		if (action == "Combat")
		{
			this->view.push(new Combat(this->window, this->pokemonPlayer, this->pokemonEnemy, "none", true));
		}
		std::string attack = this->view.top()->getActionButton();
		for (unsigned int i = 1; i < 5; i++)
		{
			if (attack == this->pokemonPlayer.getMove(i).getName())
			{
				this->avaible = getKeytime();
				if (avaible)
				{
					this->combatLogic->Attack(this->pokemonPlayer.getMove(i), this->combatLogic->WildAIAttackDecision(this->pokemonEnemy));
					this->pokemonPlayer = this->combatLogic->getPlayerPokemon();
					this->pokemonEnemy = this->combatLogic->getOpponentPokemon();
					this->view.pop();
					this->view.push(new Combat(this->window, this->pokemonPlayer, this->pokemonEnemy, "none", false));
				}
			}
		}
	}
}

void ViewManager::drawCurrentView()
{
	updateKeytime();
	this->view.top()->draw();
	
	//this->menu->draw();
}
