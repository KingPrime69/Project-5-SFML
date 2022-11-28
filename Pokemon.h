#pragma once
#include "Move.h"

class Pokemon
{
public:

	//constructor
	Pokemon();
	Pokemon(string PokemonName, int PokemonLevel);

	//Getters

	string getName();
	string getFirstType();
	string getSecondType();
	int getLevel();
	int getExp();

	int getCurrentHP();
	int getCurrentAtk();
	int getCurrentDef();
	int getCurrentSpeAtk();
	int getCurrentSpeDef();
	int getCurrentSpeed();
	Move getMove(int MoveNumber);

	//Setters

	void setLevel(int level);
	void setExp(int exp);

	void setCurrentHP(int HP);
	void setCurrentAtk(int Atk);
	void setCurrentDef(int Def);
	void setCurrentSpeAtk(int SpeAtk);
	void setCurrentSpeDef(int SpeDef);
	void setCurrentSpeed(int Speed);
	void setMove(int MoveNumber, string MoveName);

	//Methods

	void SyncLevelStat(string stat, int PokemonLevel);

private:

	//Entity information
	string name;
	string firstType;
	string secondType;
	int level;
	int exp;

	string nature; //to be implemented
	string talent; // " "      " " 


	//Moves (class move containing "name", "type", "category", "power", "accuracy", ...)
	Move move1;
	Move move2;
	Move move3;
	Move move4;
	
	//Stats
	int HP;
	int Atk;
	int Def;
	int SpeAtk;
	int SpeDef;
	int Speed;

	//Current Stats
	int currentHP;
	int currentAtk;
	int currentDef;
	int currentSpeAtk;
	int currentSpeDef;
	int currentSpeed;

};