#pragma once

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include <math.h>

#include "Pokemon.h"
#include "ViewCreator.h"

#define MAX_NUMBER_OF_TEXT 5
#define MAX_NUMBER_OF_SPRITE 5
#define MAX_NUMBER_OF_RECT 2
#define MAX_NUMBER_OF_RECT 4

class Combat : public ViewCreator
{
public :

	//constructor
	Combat(sf::RenderWindow* window, Pokemon playerPokemon, Pokemon opponentPokemon, const char* weather);

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

	//back end methods
	void Attack(Move playerMove, Move opponentMove);
	bool CheckPriority(Move playerMove, Move opponentMove);
	bool CheckCritical(Move selectMove);
	float CheckStab(Pokemon attackingPokemon, Move attackingMove);
	float CheckTypeMatchup(Move attackingMove, Pokemon defendingPokemon);
	bool CheckFlinchMoves(Move selectMove);
	void StatusMoveCalc(string attackName, Pokemon& targetPokemon, Pokemon& attackingPokemon);
	float ExpDropCalc(int baseExpYield);
	Move WildAIAttackDecision(Pokemon WildPokemon);

	//front end methods
	void initView(Pokemon playerPokemon, int spritePlayerX, int spritePlayerY,
		int spritePlayerW, int spritePlayerH, int increPokePlayerX, int increPokePlayerY, Pokemon opponentPokemon, int spriteNPX, int spriteNPY, int spriteNPW,
		int spriteNPH, int increNPX, int increNPY);
	void drawHP(Pokemon pokemonPlayer, Pokemon pokemonEnemy);

private : 

	Pokemon playerPokemon;
	Pokemon opponentPokemon;
	string weather;
	int weatherTurn;


	std::array <sf::Sprite, MAX_NUMBER_OF_SPRITE> componentSprite;
	std::array <sf::Text, MAX_NUMBER_OF_TEXT> componentText;
	std::array <sf::RectangleShape, MAX_NUMBER_OF_RECT> componentRect;
	std::array <sf::Sprite, MAX_NUMBER_OF_RECT> componentButton;
	bool showMenu;
};

