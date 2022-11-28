#pragma once

#include "Pokemon.h"

class Combat
{
public :

	//constructor
	Combat(Pokemon playerPokemon, Pokemon opponentPokemon, const char* weather);

	//getters
	Pokemon getPlayerPokemon();
	Pokemon getOpponentPokemon();
	string getWeather();
	int getWeatherTurn();

	//setters
	void setPlayerPokemon(Pokemon selectPokemon);
	void setOpponentPokemon(Pokemon selectPokemon);
	void setWeather(string nextWeather);
	void setWeatherTurn(int nextWeatherTurn);

	//methods
	void Attack(Move playerMove, Move opponentMove);
	bool CheckPriority(Move playerMove, Move opponentMove);
	bool CheckCritical(Move selectMove);
	float CheckStab(Pokemon attackingPokemon, Move attackingMove);
	float CheckTypeMatchup(Move attackingMove, Pokemon defendingPokemon);
	Move WildAIAttackDecision(Pokemon WildPokemon);

private : 

	Pokemon playerPokemon;
	Pokemon opponentPokemon;
	string weather;
	int weatherTurn;
};

