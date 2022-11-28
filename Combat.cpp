#include "Combat.h"
#include <cstdlib>
#include <math.h>

Combat::Combat(Pokemon playerPokemon, Pokemon opponentPokemon, const char* weather)
{
	Combat::playerPokemon = playerPokemon;
	Combat::opponentPokemon = opponentPokemon;
	Combat::weather = weather;
}

Pokemon Combat::getPlayerPokemon()
{
	return Combat::playerPokemon;
}

Pokemon Combat::getOpponentPokemon()
{
	return Combat::opponentPokemon;
}

string Combat::getWeather()
{
	return Combat::weather;
}

int Combat::getWeatherTurn()
{
	return Combat::weatherTurn;
}

void Combat::setPlayerPokemon(Pokemon selectPokemon)
{
	Combat::playerPokemon = selectPokemon;
}

void Combat::setOpponentPokemon(Pokemon selectPokemon)
{
	Combat::opponentPokemon = selectPokemon;
}

void Combat::setWeather(string nextWeather)
{
	Combat::weather = nextWeather;
}

void Combat::setWeatherTurn(int nextWeatherTurn)
{
	Combat::weatherTurn = nextWeatherTurn;
}

void Combat::Attack(Move playerMove, Move opponentMove)
{
	// ===== Combat Turn =====

	bool playerPlaysFirst;
	bool isCritical = false;
	float CriticalMultiplier;
	int R = 0;
	float STAB = 1;
	float TypeMatchup = 1;

	playerPlaysFirst = Combat::CheckPriority(playerMove, opponentMove);

	// ===== Stats Clash (Crits not included | Mods not included : concerns items, certain moves/talents or specific conditions like weather =====

	if (playerPlaysFirst) {
		
		// ----- Player Turn -----

		CriticalMultiplier = 1;

		isCritical = CheckCritical(playerMove);
		if (isCritical) {
			CriticalMultiplier = 1.5;
		}

		//rand = random value comprised between 217 and 255 included | R = (rand x 100) / 255
		R = ((rand() % ((255 - 217) + 1) + 217) * 100) / 255;

		//check STAB and Type weaknesses
		STAB = Combat::CheckStab(playerPokemon, playerMove);
		TypeMatchup = Combat::CheckTypeMatchup(playerMove, opponentPokemon);

		if (playerMove.getCategory() == "Physical") {
			cout << "Damage done : " << (((((((playerPokemon.getLevel() * 2 / 5) + 2) * playerMove.getPower() * playerPokemon.getCurrentAtk() / 50) / opponentPokemon.getCurrentDef()) /* x Mod 1 */) + 2) /* Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier << "\n\n";
			Combat::opponentPokemon.setCurrentHP(Combat::opponentPokemon.getCurrentHP() - (((((((playerPokemon.getLevel() * 2 / 5) + 2) * playerMove.getPower() * playerPokemon.getCurrentAtk() / 50) / opponentPokemon.getCurrentDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier);
		}
		else if (playerMove.getCategory() == "Special") {
			cout << "Damage done : " << (((((((playerPokemon.getLevel() * 2 / 5) + 2) * playerMove.getPower() * playerPokemon.getCurrentSpeAtk() / 50) / opponentPokemon.getCurrentSpeDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier << "\n\n";
			Combat::opponentPokemon.setCurrentHP(Combat::opponentPokemon.getCurrentHP() - (((((((playerPokemon.getLevel() * 2 / 5) + 2) * playerMove.getPower() * playerPokemon.getCurrentSpeAtk() / 50) / opponentPokemon.getCurrentSpeDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier);
		}

		//Manage Stat reduction moves

		else if (playerMove.getCategory() == "Status") {
		// not done yet !!!!!!!!!!
		}


		// ----- Ai Turn -----

		CriticalMultiplier = 1;

		isCritical = CheckCritical(playerMove);
		if (isCritical) {
			CriticalMultiplier = 1.5;
		}

		//rand = random value comprised between 217 and 255 included | R = (rand x 100) / 255
		R = ((rand() % ((255 - 217) + 1) + 217) * 100) / 255;

		//check STAB and Type weaknesses
		STAB = Combat::CheckStab(opponentPokemon, opponentMove);
		TypeMatchup = Combat::CheckTypeMatchup(opponentMove, playerPokemon);

		if (opponentMove.getCategory() == "Physical") {
			cout << "Damage done : " << (((((((opponentPokemon.getLevel() * 2 / 5) + 2) * opponentMove.getPower() * opponentPokemon.getCurrentAtk() / 50) / playerPokemon.getCurrentDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier << "\n\n";
			Combat::playerPokemon.setCurrentHP(Combat::playerPokemon.getCurrentHP() - (((((((opponentPokemon.getLevel() * 2 / 5) + 2) * opponentMove.getPower() * opponentPokemon.getCurrentAtk() / 50) / playerPokemon.getCurrentDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier);
		}
		else if (opponentMove.getCategory() == "Special") {
			cout << "Damage done : " << (((((((opponentPokemon.getLevel() * 2 / 5) + 2) * opponentMove.getPower() * opponentPokemon.getCurrentSpeAtk() / 50) / playerPokemon.getCurrentSpeDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier << "\n\n";
			Combat::playerPokemon.setCurrentHP(Combat::playerPokemon.getCurrentHP() - (((((((opponentPokemon.getLevel() * 2 / 5) + 2) * opponentMove.getPower() * opponentPokemon.getCurrentSpeAtk() / 50) / playerPokemon.getCurrentSpeDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier);
		}

		//Manage Stat reduction moves

		else if (opponentMove.getCategory() == "Status") {
			// not done yet !!!!!!!!!!
		}
	}
	else if (!playerPlaysFirst) {

		// ----- Ai Turn -----

		CriticalMultiplier = 1;

		isCritical = CheckCritical(playerMove);
		if (isCritical) {
			CriticalMultiplier = 1.5;
		}

		//rand = random value comprised between 217 and 255 included | R = (rand x 100) / 255
		R = ((rand() % ((255 - 217) + 1) + 217) * 100) / 255;

		//check STAB and Type weaknesses
		STAB = Combat::CheckStab(opponentPokemon, opponentMove);
		TypeMatchup = Combat::CheckTypeMatchup(opponentMove, playerPokemon);

		if (opponentMove.getCategory() == "Physical") {
			cout << "Damage done : " << (((((((opponentPokemon.getLevel() * 2 / 5) + 2) * opponentMove.getPower() * opponentPokemon.getCurrentAtk() / 50) / playerPokemon.getCurrentDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier << "\n\n";
			Combat::playerPokemon.setCurrentHP(Combat::playerPokemon.getCurrentHP() - (((((((opponentPokemon.getLevel() * 2 / 5) + 2) * opponentMove.getPower() * opponentPokemon.getCurrentAtk() / 50) / playerPokemon.getCurrentDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier);
		}
		else if (opponentMove.getCategory() == "Special") {
			cout << "Damage done : " << (((((((opponentPokemon.getLevel() * 2 / 5) + 2) * opponentMove.getPower() * opponentPokemon.getCurrentSpeAtk() / 50) / playerPokemon.getCurrentSpeDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier << "\n\n";
			Combat::playerPokemon.setCurrentHP(Combat::playerPokemon.getCurrentHP() - (((((((opponentPokemon.getLevel() * 2 / 5) + 2) * opponentMove.getPower() * opponentPokemon.getCurrentSpeAtk() / 50) / playerPokemon.getCurrentSpeDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier);
		}

		//Manage Stat reduction moves

		else if (opponentMove.getCategory() == "Status") {
			// not done yet !!!!!!!!!!
		}


		// ----- Player Turn -----

		CriticalMultiplier = 1;

		isCritical = CheckCritical(playerMove);
		if (isCritical) {
			CriticalMultiplier = 1.5;
		}

		//rand = random value comprised between 217 and 255 included | R = (rand x 100) / 255
		R = ((rand() % ((255 - 217) + 1) + 217) * 100) / 255;

		//check STAB and Type weaknesses
		STAB = Combat::CheckStab(playerPokemon, playerMove);
		TypeMatchup = Combat::CheckTypeMatchup(playerMove, opponentPokemon);

		if (playerMove.getCategory() == "Physical") {
			cout << "Damage done : " << (((((((playerPokemon.getLevel() * 2 / 5) + 2) * playerMove.getPower() * playerPokemon.getCurrentAtk() / 50) / opponentPokemon.getCurrentDef()) /* x Mod 1 */) + 2) /* Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier << "\n\n";
			Combat::opponentPokemon.setCurrentHP(Combat::opponentPokemon.getCurrentHP() - (((((((playerPokemon.getLevel() * 2 / 5) + 2) * playerMove.getPower() * playerPokemon.getCurrentAtk() / 50) / opponentPokemon.getCurrentDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier);
		}
		else if (playerMove.getCategory() == "Special") {
			cout << "Damage done : " << (((((((playerPokemon.getLevel() * 2 / 5) + 2) * playerMove.getPower() * playerPokemon.getCurrentSpeAtk() / 50) / opponentPokemon.getCurrentSpeDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier << "\n\n";
			Combat::opponentPokemon.setCurrentHP(Combat::opponentPokemon.getCurrentHP() - (((((((playerPokemon.getLevel() * 2 / 5) + 2) * playerMove.getPower() * playerPokemon.getCurrentSpeAtk() / 50) / opponentPokemon.getCurrentSpeDef()) /* x Mod 1 */) + 2) /* x Mod2 */ * R / 100) * STAB * TypeMatchup /* x Mod3 */ * CriticalMultiplier);
		}

		//Manage Stat reduction moves

		else if (playerMove.getCategory() == "Status") {
			// not done yet !!!!!!!!!!
		}
	}
}

bool Combat::CheckPriority(Move playerMove, Move opponentMove)
{
	// ===== Turn Play Order =====

	bool playerPlaysFirst;

	//Speed comparison
	if (playerPokemon.getCurrentSpeed() > opponentPokemon.getCurrentSpeed()) {
		playerPlaysFirst = true;
	}
	//Manage comparison when both speed are equal (random 50/50)
	else if (playerPokemon.getCurrentSpeed() == opponentPokemon.getCurrentSpeed()) {

		if ((rand() % 2) == 0) {
			playerPlaysFirst = true;
		}
		else {
			playerPlaysFirst = false;
		}
	}
	else {
		playerPlaysFirst = false;
	}
	return playerPlaysFirst;
}

bool Combat::CheckCritical(Move selectMove)
{
	// ===== Critical ===== not implemented

	bool isCritical;

	//check Critical Chance stage
	//if (selectMove.getHighCritMove) { //do stage 1 crit chance (1/8) }
	/*else*/ if ((rand() % 2) == 0) {
		isCritical = true;
		cout << "\nCritical !\n\n";
	}
	else {
		isCritical = false;
	}
	return isCritical;
}

float Combat::CheckStab(Pokemon attackingPokemon, Move attackingMove)
{
	float STAB = 1;

	if (attackingPokemon.getFirstType() == attackingMove.getType()) {
		STAB += 0.5;
	}

	// + additional 0.5 if talent is adaptability -- not implemented

	cout << "First Type : " << attackingPokemon.getFirstType() << "\n";
	cout << "Second Type : " << attackingPokemon.getSecondType() << "\n";
	cout << "Attack Type : " << attackingMove.getType() << "\n";
	cout << "STAB : " << STAB << "\n";

	return STAB;
}

float Combat::CheckTypeMatchup(Move attackingMove, Pokemon defendingPokemon)
{
	float TypeMultiplier = 1;

	//list type matchup interaction to calculate TypeMultiplier for every possible Type combination (except for double identical type such as Normal/Normal. Which doesn't exists)

	// =============== NORMAL ===============

	if (defendingPokemon.getFirstType() == "Normal" || defendingPokemon.getSecondType() == "Normal") {

		if (attackingMove.getType() == "Fighting") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Ghost") {
			TypeMultiplier = 0;
			return TypeMultiplier;
		}
	}

	//=============== FIRE ===============

	if (defendingPokemon.getFirstType() == "Fire" || defendingPokemon.getSecondType() == "Fire") {

		if (attackingMove.getType() == "Fire") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Water") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Grass") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ice") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ground") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Rock") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Steel") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fairy") {
			TypeMultiplier /= 2;
		}
	}

	//=============== WATER ===============

	if (defendingPokemon.getFirstType() == "Water" || defendingPokemon.getSecondType() == "Water") {
	
		if (attackingMove.getType() == "Fire") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Water") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Electric") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Grass") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Ice") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Steel") {
			TypeMultiplier /= 2;
		}
	}

	//=============== ELECTRIC ===============

	if (defendingPokemon.getFirstType() == "Electric" || defendingPokemon.getSecondType() == "Electric") {

		if (attackingMove.getType() == "Electric") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ground") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Flying") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Steel") {
			TypeMultiplier /= 2;
		}
	}

	//=============== GRASS ===============

	if (defendingPokemon.getFirstType() == "Grass" || defendingPokemon.getSecondType() == "Grass") {

		if (attackingMove.getType() == "Fire") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Water") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Electric") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Grass") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ice") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Poison") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Ground") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Flying") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier *= 2;
		}
	}

	//=============== ICE ===============

	if (defendingPokemon.getFirstType() == "Ice" || defendingPokemon.getSecondType() == "Ice") {

		if (attackingMove.getType() == "Fire") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Ice") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fighting") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Rock") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Steel") {
			TypeMultiplier *= 2;
		}
	}

	//=============== FIGHTING ===============

	if (defendingPokemon.getFirstType() == "Fighting" || defendingPokemon.getSecondType() == "Fighting") {

		if (attackingMove.getType() == "Flying") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Psychic") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Rock") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Dark") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fairy") {
			TypeMultiplier *= 2;
		}
	}

	//=============== POISON ===============

	if (defendingPokemon.getFirstType() == "Poison" || defendingPokemon.getSecondType() == "Poison") {

		if (attackingMove.getType() == "Grass") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fighting") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Poison") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ground") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Psychic") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fairy") {
			TypeMultiplier /= 2;
		}
	}

	//=============== GROUND ===============

	if (defendingPokemon.getFirstType() == "Ground" || defendingPokemon.getSecondType() == "Ground") {

		if (attackingMove.getType() == "Water") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Electric") {
			TypeMultiplier = 0;
			return TypeMultiplier;
		}
		else if (attackingMove.getType() == "Grass") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Ice") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Poison") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Rock") {
			TypeMultiplier /= 2;
		}
	}

	//=============== FLYING ===============

	if (defendingPokemon.getFirstType() == "Flying" || defendingPokemon.getSecondType() == "Flying") {

		if (attackingMove.getType() == "Electric") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Grass") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ice") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Fighting") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ground") {
			TypeMultiplier = 0;
			return TypeMultiplier;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Rock") {
			TypeMultiplier *= 2;
		}
	}

	//=============== PSYCHIC ===============

	if (defendingPokemon.getFirstType() == "Psychic" || defendingPokemon.getSecondType() == "Psychic") {

		if (attackingMove.getType() == "Fighting") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Psychic") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Ghost") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Dark") {
			TypeMultiplier /= 2;
		}
	}

	//=============== BUG ===============

	if (defendingPokemon.getFirstType() == "Bug" || defendingPokemon.getSecondType() == "Bug") {

		if (attackingMove.getType() == "Fire") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Grass") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fighting") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ground") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Flying") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Rock") {
			TypeMultiplier *= 2;
		}
	}

	//=============== ROCK ===============

	if (defendingPokemon.getFirstType() == "Rock" || defendingPokemon.getSecondType() == "Rock") {

		if (attackingMove.getType() == "Normal") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fire") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Water") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Grass") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Fighting") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Poison") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ground") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Flying") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Steel") {
			TypeMultiplier *= 2;
		}
	}

	//=============== GHOST ===============

	if (defendingPokemon.getFirstType() == "Ghost" || defendingPokemon.getSecondType() == "Ghost") {

		if (attackingMove.getType() == "Normal") {
			TypeMultiplier = 0;
			return TypeMultiplier;
		}
		else if (attackingMove.getType() == "Fighting") {
			TypeMultiplier = 0;
			return TypeMultiplier;
		}
		else if (attackingMove.getType() == "Poison") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ghost") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Dark") {
			TypeMultiplier *= 2;
		}
	}

	//=============== DRAGON ===============

	if (defendingPokemon.getFirstType() == "Dragon" || defendingPokemon.getSecondType() == "Dragon") {

		if (attackingMove.getType() == "Fire") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Water") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Electric") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Grass") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ice") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Dragon") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Fairy") {
			TypeMultiplier *= 2;
		}
	}

	//=============== DARK ===============

	if (defendingPokemon.getFirstType() == "Dark" || defendingPokemon.getSecondType() == "Dark") {

		if (attackingMove.getType() == "Fighting") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Psychic") {
			TypeMultiplier = 0;
			return TypeMultiplier;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Ghost") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Dark") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Fairy") {
			TypeMultiplier *= 2;
		}
	}

	//=============== STEEL ===============

	if (defendingPokemon.getFirstType() == "Steel" || defendingPokemon.getSecondType() == "Steel") {

		if (attackingMove.getType() == "Normal") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fire") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Grass") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Ice") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fighting") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Poison") {
			TypeMultiplier = 0;
			return TypeMultiplier;
		}
		else if (attackingMove.getType() == "Ground") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Flying") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Psychic") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Rock") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Dragon") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Steel") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Fairy") {
			TypeMultiplier /= 2;
		}
	}

	//=============== FAIRY ===============

	if (defendingPokemon.getFirstType() == "Dark" || defendingPokemon.getSecondType() == "Dark") {

		if (attackingMove.getType() == "Fighting") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Poison") {
			TypeMultiplier *= 2;
		}
		else if (attackingMove.getType() == "Bug") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Dragon") {
			TypeMultiplier = 0;
			return TypeMultiplier;
		}
		else if (attackingMove.getType() == "Dark") {
			TypeMultiplier /= 2;
		}
		else if (attackingMove.getType() == "Steel") {
			TypeMultiplier *= 2;
		}
	}

	cout << "Type Mult : " << TypeMultiplier << "\n";

	return TypeMultiplier;
}

Move Combat::WildAIAttackDecision(Pokemon WildPokemon)
{
	bool hasChosen = false;

	while (!hasChosen)
	{
		if ((rand() % 4) == 0) {
			if (WildPokemon.getMove(1).getPP() != 0) {
				cout << "move 1 chosen\n\n";
				hasChosen = true;
				return WildPokemon.getMove(1);
			}
			else {
				cout << "move 1 couldn't be chosen \n";
			}
		}
		else if ((rand() % 4) == 1) {
			if (WildPokemon.getMove(2).getPP() != 0) {
				cout << "move 2 chosen\n\n";
				hasChosen = true;
				return WildPokemon.getMove(2);
			}
			else {
				cout << "move 2 couldn't be chosen \n";
			}
		}
		else if ((rand() % 4) == 2) {
			if (WildPokemon.getMove(3).getPP() != 0) {
				cout << "move 3 chosen\n\n";
				hasChosen = true;
				return WildPokemon.getMove(3);
			}
			else {
				cout << "move 3 couldn't be chosen \n";
			}
		}
		else if ((rand() % 4) == 3) {
			if (WildPokemon.getMove(4).getPP() != 0) {
				cout << "move 4 chosen\n\n";
				hasChosen = true;
				return WildPokemon.getMove(4);
			}
			else {
				cout << "move 4 couldn't be chosen \n";
			}
		}
	}
}
