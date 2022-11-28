#include "Combat.h"
#include <cstdlib>
#include <math.h>

Combat::Combat(Pokemon playerPokemon, Pokemon opponentPokemon, const char* weather)
{
	Combat::playerPokemon = playerPokemon;
	Combat::opponentPokemon = opponentPokemon;
	Combat::weather = weather;
}

/*void Combat::Attack(Move playerMove, Move opponentMove)
{
	// ===== Turn Play Order =====

	bool playerPlaysFirst;

	//Speed comparison
	if (playerPokemon.getCurrentSpeed() > opponentPokemon.getCurrentSpeed()) {
		playerPlaysFirst = true;
	}
	//Manage comparison when both speed are equal (random 50/50)
	else if (playerPokemon.getCurrentSpeed() == opponentPokemon.getCurrentSpeed()) {

		if((rand() % 2) == 0){
			playerPlaysFirst = true;
		}
		else {
			playerPlaysFirst = false;
		}
	}
	else {
		playerPlaysFirst = false;
	}

	// ===== Stats Clash =====



}*/
