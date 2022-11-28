#include "Pokemon.h"

Pokemon::Pokemon() {
	//Value attribution
	Pokemon::name = "";
	Pokemon::firstType = "";
	Pokemon::secondType = "";
	Pokemon::level = 0;
	Pokemon::exp = 0;

	Pokemon::nature = "";
	Pokemon::talent = "";

	Pokemon::HP = 0;
	Pokemon::Atk = 0;
	Pokemon::Def = 0;
	Pokemon::SpeAtk = 0;
	Pokemon::SpeDef = 0;
	Pokemon::Speed = 0;

	Pokemon::currentHP = 0;
	Pokemon::currentAtk = 0;
	Pokemon::currentDef = 0;
	Pokemon::currentSpeAtk = 0;
	Pokemon::currentSpeDef = 0;
	Pokemon::currentSpeed = 0;
}

Pokemon::Pokemon(string PokemonName, int PokemonLevel)
{
	//get pokemon data
	std::ifstream f("../Project-5-SFML/.json_data/pokemon.json");

	//parse and serialize JSON
	json data = json::parse(f);

	//Value attribution
	Pokemon::name = data[PokemonName]["Name"];
	Pokemon::firstType = data[PokemonName]["FirstType"];
	Pokemon::secondType = data[PokemonName]["SecondType"];
	Pokemon::level = PokemonLevel;
	Pokemon::exp = 0; //[calcul courbe exp de level-1] 

	Pokemon::nature = ""; //not defined yet
	Pokemon::talent = ""; //not defined yet

	Pokemon::HP = data[PokemonName]["HP"];
	Pokemon::Atk = data[PokemonName]["Atk"];
	Pokemon::Def = data[PokemonName]["Def"];
	Pokemon::SpeAtk = data[PokemonName]["SpeAtk"];
	Pokemon::SpeDef = data[PokemonName]["SpeDef"];
	Pokemon::Speed = data[PokemonName]["Speed"];

	Pokemon::currentHP = data[PokemonName]["HP"];
	Pokemon::currentAtk = data[PokemonName]["Atk"];
	Pokemon::currentDef = data[PokemonName]["Def"];
	Pokemon::currentSpeAtk = data[PokemonName]["SpeAtk"];
	Pokemon::currentSpeDef = data[PokemonName]["SpeDef"];
	Pokemon::currentSpeed = data[PokemonName]["Speed"];
}

string Pokemon::getName()
{
	return Pokemon::name;
}

string Pokemon::getFirstType()
{
	return Pokemon::firstType;
}

string Pokemon::getSecondType()
{
	return Pokemon::secondType;
}

int Pokemon::getLevel()
{
	return Pokemon::level;
}

int Pokemon::getExp()
{
	return Pokemon::exp;
}

int Pokemon::getCurrentHP()
{
	return Pokemon::currentHP;
}

int Pokemon::getCurrentAtk()
{
	return Pokemon::currentAtk;
}

int Pokemon::getCurrentDef()
{
	return Pokemon::currentDef;
}

int Pokemon::getCurrentSpeAtk()
{
	return Pokemon::currentSpeAtk;
}

int Pokemon::getCurrentSpeDef()
{
	return Pokemon::currentSpeDef;
}

int Pokemon::getCurrentSpeed()
{
	return Pokemon::currentSpeed;
}

Move Pokemon::getMove(int MoveNumber)
{
	switch (MoveNumber) {
	case 1:
		return Pokemon::move1;
	case 2:
		return Pokemon::move2;
	case 3:
		return Pokemon::move3;
	case 4:
		return Pokemon::move4;
	default:
		cout << "Get Move Object Error : invalid move number [" << MoveNumber << "]\n";
		break;
	}
}

void Pokemon::setLevel(int level)
{
	Pokemon::level = level;
}

void Pokemon::setExp(int exp)
{
	Pokemon::exp += exp;
	//manage leveling system ...
}

void Pokemon::setCurrentHP(int HP)
{
	Pokemon::currentHP = HP;
}

void Pokemon::setCurrentAtk(int Atk)
{
	Pokemon::currentAtk = Atk;
}

void Pokemon::setCurrentDef(int Def)
{
	Pokemon::currentDef = Def;
}

void Pokemon::setCurrentSpeAtk(int SpeAtk)
{
	Pokemon::currentSpeAtk = SpeAtk;
}

void Pokemon::setCurrentSpeDef(int SpeDef)
{
	Pokemon::currentSpeDef = SpeDef;
}

void Pokemon::setCurrentSpeed(int Speed)
{
	Pokemon::currentSpeed = Speed;
}

void Pokemon::setMove(int MoveNumber, string MoveName)
{
	//get moves data
	std::ifstream f("../Project-5-SFML/.json_data/moves.json");

	//parse and serialize JSON
	json data = json::parse(f);
	Move MoveObject(data[MoveName]["Name"], data[MoveName]["Type"], data[MoveName]["Category"], data[MoveName]["Power"], data[MoveName]["Accuracy"], data[MoveName]["PP"], data[MoveName]["Contact"], data[MoveName]["Weather"]);

	switch (MoveNumber) {
		case 1:
			Pokemon::move1 = MoveObject;
			break;
		case 2:
			Pokemon::move2 = MoveObject;
			break;
		case 3:
			Pokemon::move3 = MoveObject;
			break;
		case 4:
			Pokemon::move4 = MoveObject;
			break;
		default:
			cout << "Move Object Creation Error : invalid move number [" << MoveNumber << "]\n";
			break;
	}
	MoveObject.~Move();
}

/*void Pokemon::SyncLevelStat(string stat, int PokemonLevel)
{
	switch (stat)
	{
	case "HP":

		break;
	case "Atk":

		break;
	case "Def":

		break;
	case "SpeAtk":

		break;
	case "SpeDef":

		break;
	case "Speed":

		break;
	default:
		break;
	}
}*/


