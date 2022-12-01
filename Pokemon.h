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
	int getNextLevelExp();
	int getExpYield();
	string getExpCurve();

	string getNatureID();
	string getNatureName();

	int getCurrentHP();
	int getHP();
	int getCurrentAtk();
	int getAtk();
	int getAtkStage();
	int getCurrentDef();
	int getDef();
	int getDefStage();
	int getCurrentSpeAtk();
	int getSpeAtk();
	int getSpeAtkStage();
	int getCurrentSpeDef();
	int getSpeDef();
	int getSpeDefStage();
	int getCurrentSpeed();
	int getSpeed();
	int getSpeedStage();
	Move getMove(int MoveNumber);

	//Setters

	void setLevel(int level);
	void setExp(int exp);
	void setNextLevelExp(int exp);
	void setExpYield(int exp);
	void setExpCurve(string selectCurve);

	void setNatureID(string natureID);
	void setNatureName(string natureName);

	void setCurrentHP(int HP);
	void setCurrentAtk(int Atk);
	void setAtkStage(int StageMod);
	void setCurrentDef(int Def);
	void setDefStage(int StageMod);
	void setCurrentSpeAtk(int SpeAtk);
	void setSpeAtkStage(int StageMod);
	void setCurrentSpeDef(int SpeDef);
	void setSpeDefStage(int StageMod);
	void setCurrentSpeed(int Speed);
	void setSpeedStage(int StageMod);
	void setMove(int MoveNumber, string MoveName);

	//Methods

	void SyncLevelStat(string stat, int PokemonLevel);
	void SyncExp(string selectValue);
	float ProcessMultiplier(int StageMod, string StageType);
	string RandomNature();
	void CheckLevelOpportunity();

private:

	//Entity information
	string name;
	string firstType;
	string secondType;
	int level;
	int exp;
	int nextLevelExp;
	int expYield;
	string expCurve;

	string natureID;
	string natureName;
	string talent; // not implemented yet


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

	//Stats stages (buffs/debufs)
	float AtkStage;
	float DefStage;
	float SpeAtkStage;
	float SpeDefStage;
	float SpeedStage;

};