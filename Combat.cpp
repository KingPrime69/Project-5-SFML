#include "Combat.h"
#include <cstdlib>
#include <math.h>

Combat::Combat(sf::RenderWindow* window, Pokemon playerPokemon, Pokemon opponentPokemon, const char* weather) : ViewCreator(window)
{
	Combat::playerPokemon = playerPokemon;
	Combat::opponentPokemon = opponentPokemon;
	Combat::weather = weather;

	this->window = window;
	initView(playerPokemon, 34, 1, 27, 29, 0, 0, opponentPokemon, 195, 401, 42, 31, 0, 0);
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

	// ===== Stats Clash (Mods not included : concerns items, certain moves/talents or specific conditions like weather =====

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
			Combat::StatusMoveCalc(playerMove.getName(), opponentPokemon, playerPokemon);
		}

		if (Combat::opponentPokemon.getCurrentHP() <= 0) {
			//temp function : exp calculation is incomplete
			cout << "Ennemy " << opponentPokemon.getName() << " has fainted, " << opponentPokemon.getExpYield() << " exp obtained ! \n";
			playerPokemon.setExp(opponentPokemon.getExpYield());
			return;
		}

		if (Combat::CheckFlinchMoves(playerMove) == true) {
			return;
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
			Combat::StatusMoveCalc(opponentMove.getName(), playerPokemon, opponentPokemon);
		}

		if (Combat::playerPokemon.getCurrentHP() <= 0) {
			cout << playerPokemon.getName() << " fainted ! \n";
			//add party check to determine if fight is lost
			return;
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
			Combat::StatusMoveCalc(opponentMove.getName(), playerPokemon, opponentPokemon);
		}

		if (Combat::playerPokemon.getCurrentHP() <= 0) {
			cout << playerPokemon.getName() << " fainted ! \n";
			//add party check to determine if fight is lost
			return;
		}

		if (Combat::CheckFlinchMoves(opponentMove) == true) {
			return;
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
			Combat::StatusMoveCalc(playerMove.getName(), opponentPokemon, playerPokemon);
		}

		if (Combat::opponentPokemon.getCurrentHP() <= 0) {

			cout << "Ennemy " << opponentPokemon.getName() << " has fainted, " <<  Combat::ExpDropCalc(Combat::opponentPokemon.getExpYield()) << " exp obtained ! \n";
			playerPokemon.setExp(Combat::ExpDropCalc(Combat::opponentPokemon.getExpYield()));
			return;
		}
	}
	return;
}

bool Combat::CheckPriority(Move playerMove, Move opponentMove)
{
	// ===== Turn Play Order =====

	bool playerPlaysFirst;

	//priority moves
	if (playerMove.getName() == "Quick Attack") {
		if (playerMove.getName() == opponentMove.getName()) {
			if ((rand() % 2) == 0) {
				return playerPlaysFirst = true;
			}
			else {
				return playerPlaysFirst = false;
			}
		}
		return playerPlaysFirst = true;
	}

	//Speed comparison
	if (playerPokemon.getCurrentSpeed() > opponentPokemon.getCurrentSpeed()) {
		return playerPlaysFirst = true;
	}
	//Manage comparison when both speed are equal (random 50/50)
	else if (playerPokemon.getCurrentSpeed() == opponentPokemon.getCurrentSpeed()) {

		if ((rand() % 2) == 0) {
			return playerPlaysFirst = true;
		}
		else {
			return playerPlaysFirst = false;
		}
	}
	else {
		return playerPlaysFirst = false;
	}

	return playerPlaysFirst;
}

bool Combat::CheckCritical(Move selectMove)
{
	// ===== Critical ===== not implemented

	bool isCritical;

	//check Critical Chance stage
	//if (selectMove.getHighCritMove) { //do stage 1 crit chance (1/8) }
	/*else*/ if ((rand() % 24) == 0) {
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

bool Combat::CheckFlinchMoves(Move selectMove)
{
	if (selectMove.getName() == "Bite") {
		cout << "Ennemy Flinched ?\n";
		if (rand() % 10 + 1 == 1 || rand() % 10 + 1 == 2 || rand() % 10 + 1 == 3) {
			cout << "Ennemy Flinched !\n\n";
			return true;
		}

	}
}

void Combat::StatusMoveCalc(string attackName, Pokemon& targetPokemon, Pokemon& attackingPokemon)
{
	//Defense reduction moves
	if (attackName == "Tail Whip") {
		if (targetPokemon.getDefStage() >= -6) {
			targetPokemon.setDefStage(targetPokemon.getDefStage() - 1);
		}
		else {
			cout << "Ennemy Defense can't go any lower !";
		}
	}

	//Atk boost moves
	else if (attackName == "Hone Claws") {
		if (targetPokemon.getAtkStage() <= 6) {
			attackingPokemon.setAtkStage(targetPokemon.getAtkStage() + 1);
		}
		else {
			cout << "Ennemy Defense can't go any lower !";
		}
	}

	targetPokemon.SyncLevelStat("All", targetPokemon.getLevel());
	attackingPokemon.SyncLevelStat("All", attackingPokemon.getLevel());
}

float Combat::ExpDropCalc(int baseExpYield)
{
	float expYield = 0;

	expYield = round(((((baseExpYield * Combat::opponentPokemon.getLevel()) / 5)) * pow(((static_cast<float>(2) * Combat::opponentPokemon.getLevel() + 10) / (Combat::opponentPokemon.getLevel() + Combat::playerPokemon.getLevel() + 10)), 2.5) + 1));

	return expYield;
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

void Combat::initView(Pokemon playerPokemon, int spritePlayerX, int spritePlayerY, int spritePlayerW, int spritePlayerH, int increPokePlayerX, int increPokePlayerY, Pokemon opponentPokemon, int spriteNPX, int spriteNPY, int spriteNPW, int spriteNPH, int increNPX, int increNPY)
{

	cout << "Pokemon Move Name Getted : " << playerPokemon.getMove(1).getName() << "\n";

	this->createBackground(1);

	int WindowYPokemon = this->window->getSize().y / 2 - 100;
	int pokeLeftX = this->window->getSize().x / 7;
	int pokeRightX = this->window->getSize().x - 275;

	//### Pokemon ###//
	//34, 1, 27, 29,
	this->addSprite(componentSprite[0], 2, pokeLeftX + increPokePlayerX, WindowYPokemon + 100 + increPokePlayerY,
		sf::Vector2f(3, 3), spritePlayerX, spritePlayerY, spritePlayerW, spritePlayerH, false, playerPokemon.getName(), false);
	this->addSprite(componentSprite[1], 2, pokeRightX + increNPX, WindowYPokemon + 100 + increNPY, sf::Vector2f(3, 3), spriteNPX,
		spriteNPY, spriteNPW, spriteNPH,
		false, opponentPokemon.getName(), false);
	//### ~Pokemon ###//

	//groudon (componentSprite[1], 2, pokeRightX-200, WindowYPokemon-100, sf::Vector2f(3, 3), 4, 1057, 154, 119, false, "Gneneu");
	//gitan (componentSprite[0], 2, pokeRightX, WindowYPokemon+100, sf::Vector2f(3, 3), 195, 401, 42, 31, false, "Gneneu", false);

	//### Box Info ###//
	this->addSprite(componentSprite[2], 3, pokeLeftX - 100, WindowYPokemon - 200, sf::Vector2f(1.5, 1.5), 46, 32, 270, 54, false, "InfoPokemonPlayer", false);
	this->addSprite(componentSprite[2], 3, pokeRightX - 200, WindowYPokemon - 200, sf::Vector2f(1.5, 1.5), 46, 32, 270, 54, false, "InfoPokemonNP", false);
	//### ~Box Info ###//

	//### Name Pokemon ###//
	this->addText(componentText[0], sf::Color::Black, 3, playerPokemon.getName(), pokeLeftX - 80, WindowYPokemon - 200, 40, false);
	this->addText(componentText[1], sf::Color::Black, 3, opponentPokemon.getName(), pokeRightX - 180, WindowYPokemon - 200, 40, false);
	//### ~Name Pokemon ###//

	//### Lvl Pokemon ###//
	std::string lvlSting = "Lv" + std::to_string(playerPokemon.getLevel());
	std::cout << lvlSting << std::endl;
	this->addText(componentText[2], sf::Color::Black, 3, lvlSting, pokeLeftX + 240, WindowYPokemon - 200, 35, false);


	lvlSting = "Lv" + std::to_string(opponentPokemon.getLevel());
	std::cout << lvlSting << std::endl;
	this->addText(componentText[3], sf::Color::Black, 3, lvlSting, pokeRightX + 140, WindowYPokemon - 200, 35, false);
	//### ~Lvl Pokemon ###//

	//### HP ###//
	this->addSprite(componentSprite[3], 4, pokeLeftX + 40, WindowYPokemon - 145, sf::Vector2f(0.5, 0.5), 2, 243, 509, 19, false, "hpPlayer", true);
	this->addSprite(componentSprite[3], 4, pokeRightX - 60, WindowYPokemon - 145, sf::Vector2f(0.5, 0.5), 2, 243, 509, 19, false, "hpNP", true);
	//### ~HP ###//

	//### HP barre ###//
	this->addRect(componentRect[0], sf::Color::Green, pokeLeftX + 98, WindowYPokemon - 145, sf::Vector2f(194, 10), "hpPlayer");
	this->addRect(componentRect[0], sf::Color::Green, pokeRightX - 2, WindowYPokemon - 145, sf::Vector2f(194, 10), "hpEnemy");
	//### ~HP barre ###//

	int skillX = 1 / this->window->getSize().x + 50;
	int skillY = this->window->getSize().y - 200;

	int sizeBoxY = 1.75;
	this->addText(componentText[2], sf::Color::Black, 3, "Attaque :", skillX + 25, skillY - 75, 50, false);
	this->createButton(componentText[1], sf::Color::Black, sf::Color::Red, 3, playerPokemon.getMove(1).getName(),
		skillX, skillY, 40, 25, 30, componentButton[0], playerPokemon.getMove(1).getName(), 3, sf::Vector2f(0.75, 1.75),
		46, 32, 270, 54, false);
	this->createButton(componentText[2], sf::Color::Black, sf::Color::Red, 3, playerPokemon.getMove(2).getName(),
		skillX, skillY + 90, 40, 25, 30, componentButton[1], playerPokemon.getMove(2).getName(), 3, sf::Vector2f(0.75, 1.75),
		46, 32, 270, 54, false);
	this->createButton(componentText[3], sf::Color::Black, sf::Color::Red, 3, playerPokemon.getMove(3).getName(),
		skillX + 250, skillY, 40, 25, 30, componentButton[2], playerPokemon.getMove(3).getName(), 3, sf::Vector2f(0.75, 1.75),
		46, 32, 270, 54, false);
	this->createButton(componentText[4], sf::Color::Black, sf::Color::Red, 3, playerPokemon.getMove(4).getName(),
		skillX + 250, skillY + 90, 40, 25, 30, componentButton[3], playerPokemon.getMove(4).getName(), 3, sf::Vector2f(0.75, 1.75),
		46, 32, 270, 54, false);
}

void Combat::drawHP(Pokemon pokemonPlayer, Pokemon pokemonEnemy)
{
	int hpPlayer = pokemonPlayer.getCurrentHP();
	int hpPokemon = pokemonEnemy.getCurrentHP();

}
