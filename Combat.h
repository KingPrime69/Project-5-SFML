#pragma once

#include "Pokemon.h"

class Combat
{
public :

	//constructor
	Combat(Pokemon playerPokemon, Pokemon opponentPokemon, const char* weather);

	//combat back methods
	//void Attack(Move playerMove, Move opponentMove);

private : 

	Pokemon playerPokemon;
	Pokemon opponentPokemon;
	string weather;

};

