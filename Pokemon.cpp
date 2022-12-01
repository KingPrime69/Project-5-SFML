#include "Pokemon.h"

Pokemon::Pokemon() {
	//Value attribution
	Pokemon::name = "";
	Pokemon::firstType = "";
	Pokemon::secondType = "";
	Pokemon::level = 0;
	Pokemon::exp = 0;
	Pokemon::nextLevelExp = 0;
	Pokemon::expCurve = "";

	Pokemon::natureID = "";
	Pokemon::natureName = "";
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
	std::ifstream g("../Project-5-SFML/.json_data/nature.json");

	//parse and serialize JSON
	json PokemonData = json::parse(f);
	json NatureData = json::parse(g);

	//Value attribution
	Pokemon::name = PokemonData[PokemonName]["Name"];
	Pokemon::firstType = PokemonData[PokemonName]["FirstType"];
	Pokemon::secondType = PokemonData[PokemonName]["SecondType"];
	Pokemon::level = PokemonLevel;
	Pokemon::expCurve = PokemonData[PokemonName]["ExpCurve"];
	Pokemon::SyncExp("exp");
	Pokemon::SyncExp("nextLevelExp");
	Pokemon::expYield = PokemonData[PokemonName]["ExpYield"];

	Pokemon::natureID = Pokemon::RandomNature();
	Pokemon::natureName = NatureData[Pokemon::natureID]["Name"].get<std::string>();
	Pokemon::talent = ""; //not defined yet

	Pokemon::AtkStage = 0;
	Pokemon::DefStage = 0;
	Pokemon::SpeAtkStage = 0;
	Pokemon::SpeDefStage = 0;
	Pokemon::SpeedStage = 0;

	//fill stats according to base stats and level
	Pokemon::SyncLevelStat("HP", PokemonLevel);
	Pokemon::SyncLevelStat("Atk", PokemonLevel);
	Pokemon::SyncLevelStat("Def", PokemonLevel);
	Pokemon::SyncLevelStat("SpeAtk", PokemonLevel);
	Pokemon::SyncLevelStat("SpeDef", PokemonLevel);
	Pokemon::SyncLevelStat("Speed", PokemonLevel);

	Pokemon::currentHP = Pokemon::HP;
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

int Pokemon::getNextLevelExp()
{
	return Pokemon::nextLevelExp;
}

int Pokemon::getExpYield()
{
	return Pokemon::expYield;
}

string Pokemon::getExpCurve()
{
	return Pokemon::expCurve;
}

string Pokemon::getNatureID()
{
	return Pokemon::natureID;
}

string Pokemon::getNatureName()
{
	return Pokemon::natureName;
}

int Pokemon::getCurrentHP()
{
	return Pokemon::currentHP;
}

int Pokemon::getHP()
{
	return Pokemon::HP;
}

int Pokemon::getCurrentAtk()
{
	return Pokemon::currentAtk;
}

int Pokemon::getAtk()
{
	return Pokemon::Atk;
}

int Pokemon::getAtkStage()
{
	return Pokemon::AtkStage;
}

int Pokemon::getCurrentDef()
{
	return Pokemon::currentDef;
}

int Pokemon::getDef()
{
	return Pokemon::Def;
}

int Pokemon::getDefStage()
{
	cout << Pokemon::name << " Get DefStage : " << Pokemon::DefStage << "\n";
	return Pokemon::DefStage;
}

int Pokemon::getCurrentSpeAtk()
{
	return Pokemon::currentSpeAtk;
}

int Pokemon::getSpeAtk()
{
	return Pokemon::SpeAtk;
}

int Pokemon::getSpeAtkStage()
{
	return Pokemon::SpeAtkStage;
}

int Pokemon::getCurrentSpeDef()
{
	return Pokemon::currentSpeDef;
}

int Pokemon::getSpeDef()
{
	return Pokemon::SpeDef;
}

int Pokemon::getSpeDefStage()
{
	return Pokemon::SpeDefStage;
}

int Pokemon::getCurrentSpeed()
{
	return Pokemon::currentSpeed;
}

int Pokemon::getSpeed()
{
	return Pokemon::Speed;
}

int Pokemon::getSpeedStage()
{
	return Pokemon::SpeedStage;
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

	//manage leveling system
	if (Pokemon::exp >= Pokemon::nextLevelExp) {
		Pokemon::setLevel(Pokemon::level + 1);
		Pokemon::SyncExp("nextLevelExp");
		cout << Pokemon::name << " leveled up !\n" << Pokemon::name << " is level : " << Pokemon::level << "\n";
		Pokemon::SyncLevelStat("All", Pokemon::level);
	}
}

void Pokemon::setNextLevelExp(int exp)
{
	Pokemon::nextLevelExp = exp;
}

void Pokemon::setExpYield(int exp)
{
	Pokemon::expYield = exp;
}

void Pokemon::setExpCurve(string selectCurve)
{
	Pokemon::expCurve = selectCurve;
}

void Pokemon::setNatureID(string natureID)
{
	Pokemon::natureID = natureID;
}

void Pokemon::setNatureName(string natureName)
{
	Pokemon::natureName = natureName;
}

void Pokemon::setCurrentHP(int HP)
{
	Pokemon::currentHP = HP;
}

void Pokemon::setCurrentAtk(int Atk)
{
	Pokemon::currentAtk = Atk;
}

void Pokemon::setAtkStage(int ProcessedStageMod)
{
	Pokemon::AtkStage = ProcessedStageMod;
}

void Pokemon::setCurrentDef(int Def)
{
	Pokemon::currentDef = Def;
}

void Pokemon::setDefStage(int StageMod)
{
	Pokemon::DefStage = StageMod;
	cout << Pokemon::name << " New DefStage : " << Pokemon::DefStage << "\n";
}

void Pokemon::setCurrentSpeAtk(int SpeAtk)
{
	Pokemon::currentSpeAtk = SpeAtk;
}

void Pokemon::setSpeAtkStage(int StageMod)
{
	Pokemon::SpeAtkStage = StageMod;
}

void Pokemon::setCurrentSpeDef(int SpeDef)
{
	Pokemon::currentSpeDef = SpeDef;
}

void Pokemon::setSpeDefStage(int StageMod)
{
	Pokemon::SpeDefStage = StageMod;
}

void Pokemon::setCurrentSpeed(int Speed)
{
	Pokemon::currentSpeed = Speed;
}

void Pokemon::setSpeedStage(int StageMod)
{
	Pokemon::SpeedStage = StageMod;
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

void Pokemon::SyncLevelStat(string stat, int PokemonLevel)
{
	//get pokemon data
	std::ifstream f("../Project-5-SFML/.json_data/pokemon.json");
	std::ifstream g("../Project-5-SFML/.json_data/nature.json");

	//parse and serialize JSON
	json PokemonData = json::parse(f);
	json NatureData = json::parse(g);

	if (stat == "All") {

		Pokemon::HP = (PokemonData[Pokemon::name]["HP"] * 2 * PokemonLevel) / 100 + 10 + PokemonLevel;
		if (Pokemon::currentHP == Pokemon::HP) {

			Pokemon::currentHP = Pokemon::HP;
		}

		Pokemon::Atk = ((PokemonData[Pokemon::name]["Atk"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["AtkMod"]);
		Pokemon::currentAtk = Pokemon::Atk * Pokemon::ProcessMultiplier(Pokemon::AtkStage, "Base");

		Pokemon::Def = ((PokemonData[Pokemon::name]["Def"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["DefMod"]);
		Pokemon::currentDef = Pokemon::Def * Pokemon::ProcessMultiplier(Pokemon::DefStage, "Base");

		Pokemon::SpeAtk = ((PokemonData[Pokemon::name]["SpeAtk"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["SpeAtkMod"]);
		Pokemon::currentSpeAtk = Pokemon::SpeAtk * Pokemon::ProcessMultiplier(Pokemon::SpeAtkStage, "Base");

		Pokemon::SpeDef = ((PokemonData[Pokemon::name]["SpeDef"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["SpeDefMod"]);
		Pokemon::currentSpeDef = Pokemon::SpeDef * Pokemon::ProcessMultiplier(Pokemon::SpeDefStage, "Base");

		Pokemon::Speed = ((PokemonData[Pokemon::name]["Speed"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["SpeedMod"]);
		Pokemon::currentSpeed = Pokemon::Speed * Pokemon::ProcessMultiplier(Pokemon::SpeedStage, "Base");
	}
	else if (stat == "HP") {

		Pokemon::HP = (PokemonData[Pokemon::name]["HP"] * 2 * PokemonLevel) / 100 + 10 + PokemonLevel;
		if (Pokemon::currentHP == Pokemon::HP) {

			Pokemon::currentHP = Pokemon::HP;
		}
	}
	else if (stat == "Atk") {

		Pokemon::Atk = ((PokemonData[Pokemon::name]["Atk"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["AtkMod"]);
		Pokemon::currentAtk = Pokemon::Atk * Pokemon::ProcessMultiplier(Pokemon::AtkStage, "Base");
	}
	else if (stat == "Def") {

		Pokemon::Def = ((PokemonData[Pokemon::name]["Def"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["DefMod"]);
		Pokemon::currentDef = Pokemon::Def * Pokemon::ProcessMultiplier(Pokemon::DefStage, "Base");
	}
	else if (stat == "SpeAtk"){

		Pokemon::SpeAtk = ((PokemonData[Pokemon::name]["SpeAtk"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["SpeAtkMod"]);
		Pokemon::currentSpeAtk = Pokemon::SpeAtk * Pokemon::ProcessMultiplier(Pokemon::SpeAtkStage, "Base");
	}
	else if (stat == "SpeDef"){

		Pokemon::SpeDef = ((PokemonData[Pokemon::name]["SpeDef"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["SpeDefMod"]);
		Pokemon::currentSpeDef = Pokemon::SpeDef * Pokemon::ProcessMultiplier(Pokemon::SpeDefStage, "Base");
	}
	else if (stat == "Speed") {

		Pokemon::Speed = ((PokemonData[Pokemon::name]["Speed"] * 2 * PokemonLevel) / 100 + 5) * static_cast<float>(NatureData[Pokemon::natureID]["SpeedMod"]);
		Pokemon::currentSpeed = Pokemon::Speed * Pokemon::ProcessMultiplier(Pokemon::SpeedStage, "Base");
	}
	else {
		cout << "Stat Sync Error : invalid value : [" << stat << "]\n";
	}
}

void Pokemon::SyncExp(string selectValue)
{
	double expResult{};

	if (selectValue == "exp") {
		if (Pokemon::expCurve == "Medium Slow") {

			//list exp curve cases
			expResult = (((static_cast<double>(6) / 5) * (Pokemon::level * Pokemon::level * Pokemon::level)) - 15 * (Pokemon::level * Pokemon::level)) + 100 * Pokemon::level - 140;

			Pokemon::exp = expResult;
			cout << "Sync Exp Result : " << expResult << "\n";
		}
	}
	else if (selectValue == "nextLevelExp") {

		//list exp curve cases
		if (Pokemon::expCurve == "Medium Slow") {
			expResult = (((static_cast<double>(6) / 5) * ((Pokemon::level + 1) * (Pokemon::level + 1) * (Pokemon::level + 1))) - 15 * ((Pokemon::level + 1) * (Pokemon::level + 1))) + 100 * (Pokemon::level + 1) - 140;;
		}
		Pokemon::nextLevelExp = expResult;
		cout << "Sync nextLevelExp Result : " << expResult << "\n\n";
	}
}

float Pokemon::ProcessMultiplier(int StageMod, string StageType)
{
	float processedStageMod;

	if (StageType == "Base") {

		if (StageMod == -6) {
			processedStageMod = static_cast<float>(2) / 8;
		}

		else if (StageMod == -5) {
			processedStageMod = static_cast<float>(2) / 7;
		}

		else if (StageMod == -4) {
			processedStageMod = static_cast<float>(2) / 6;
		}

		else if (StageMod == -3) {
			processedStageMod = static_cast<float>(2) / 5;
		}

		else if (StageMod == -2) {
			processedStageMod = static_cast<float>(2) / 4;
		}

		else if (StageMod == -1) {
			processedStageMod = static_cast<float>(2) / 3;
		}

		else if (StageMod == 0) {
			processedStageMod = 1;
		}

		else if (StageMod == 1) {
			processedStageMod = static_cast<float>(3) / 2;
		}

		else if (StageMod == 2) {
			processedStageMod = static_cast<float>(4) / 2;
		}

		else if (StageMod == 3) {
			processedStageMod = static_cast<float>(5) / 2;
		}

		else if (StageMod == 4) {
			processedStageMod = static_cast<float>(6) / 2;
		}

		else if (StageMod == 5) {
			processedStageMod = static_cast<float>(7) / 2;
		}

		else if (StageMod == 6) {
			processedStageMod = static_cast<float>(8) / 2;
		}

		else {
			cout << "Stage Multiplier Processing failed : invalid value " << StageMod << "\n";
			return 1;
		}
	}

	else if (StageType == "Combat") {

		if (StageMod == -6) {
			processedStageMod = static_cast<float>(3) / 9;
		}

		else if (StageMod == -5) {
			processedStageMod = static_cast<float>(3) / 8;
		}

		else if (StageMod == -4) {
			processedStageMod = static_cast<float>(3) / 7;
		}

		else if (StageMod == -3) {
			processedStageMod = static_cast<float>(3) / 6;
		}

		else if (StageMod == -2) {
			processedStageMod = static_cast<float>(3) / 5;
		}

		else if (StageMod == -1) {
			processedStageMod = static_cast<float>(3) / 4;
		}

		else if (StageMod == 0) {
			processedStageMod = 1;
		}

		else if (StageMod == 1) {
			processedStageMod = static_cast<float>(4) / 3;
		}

		else if (StageMod == 2) {
			processedStageMod = static_cast<float>(5) / 3;
		}

		else if (StageMod == 3) {
			processedStageMod = static_cast<float>(6) / 3;
		}

		else if (StageMod == 4) {
			processedStageMod = static_cast<float>(7) / 3;
		}

		else if (StageMod == 5) {
			processedStageMod = static_cast<float>(8) / 3;
		}

		else if (StageMod == 6) {
			processedStageMod = static_cast<float>(9) / 3;
		}

		else {
			cout << "Stage Multiplier Processing failed : invalid value " << StageMod << "\n";
			return 1;
		}
	}

	return processedStageMod;
}

string Pokemon::RandomNature()
{
	int natureID;

	//get nature data
	std::ifstream f("../Project-5-SFML/.json_data/nature.json");

	//parse and serialize JSON
	json data = json::parse(f);

	natureID = (rand() % 25) + 1;

	string NatureStrID = std::to_string(natureID);

	return NatureStrID;
}

void Pokemon::CheckLevelOpportunity() 
{
	/*//get pokemon data
	std::ifstream f("../Project-5-SFML/.json_data/pokemon.json");

	//parse and serialize JSON
	json data = json::parse(f);

	string iStr;

	for (size_t i = Pokemon::getLevel();  i < 101;  i++)
	{
		int test = i;
		iStr = "\"" + to_string(test) + "\"";
		cout << data[Pokemon::getName()]["LevelingPath"][iStr] << "\n\n";
		if (data[Pokemon::getName()]["LevelingPath"]["7"].find("AvailableAttack") != data[Pokemon::getName()]["LevelingPath"]["7"].end())
		{
			cout << data[Pokemon::getName()]["LevelingPath"]["7"]["AvailableAttack"] << "\n";
		}
	}*/
}
