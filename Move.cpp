#include "Move.h"


Move::Move()
{
	Move::name = "NULL";
	Move::type = "NULL";
	Move::category = "NULL";
	Move::power = 0;
	Move::accuracy = 0;
	Move::PP = 0;
	Move::contact = NULL;
	Move::weather = "NULL";
}

Move::Move(json name, json type, json category, json power, json accuracy, json PP, json contact, json weather)
{
	Move::name = name;
	Move::type = type;
	Move::category = category;
	Move::power = power;
	Move::accuracy = accuracy;
	Move::PP = PP;
	Move::contact = contact;
	Move::weather = weather;
}

Move::~Move()
{
	//cout << "Move object deleted &.\n";
}

string Move::getName()
{
	return Move::name;
}

string Move::getType()
{
	return Move::type;
}

string Move::getCategory()
{
	return Move::category;
}

int Move::getPower()
{
	return Move::power;
}

int Move::getAccuracy()
{
	return Move::accuracy;
}

int Move::getPP()
{
	return Move::PP;
}

bool Move::getContact()
{
	return Move::contact;
}

string Move::getWeather()
{
	return Move::weather;
}

void Move::setName(json name)
{
	Move::name = name;
}

void Move::setType(json type)
{
	Move::type = type;
}

void Move::setCategory(json category)
{
	Move::category = category;
}

void Move::setPower(json power)
{
	Move::power = power;
}

void Move::setAccuracy(json accuracy)
{
	Move::accuracy = accuracy;
}

void Move::setPP(json PP)
{
	Move::PP = PP;
}

void Move::setContact(json contact)
{
	Move::contact = contact;
}

void Move::setWeather(json weather)
{
	Move::weather = weather;
}
