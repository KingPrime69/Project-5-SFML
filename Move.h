#pragma once
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using namespace std;
using json = nlohmann::json;

class Move
{
public:

	//constructor
	Move();
	Move(json name, json type, json category, json power, json accuracy, json PP, json contact, json weather);

	//destructor
	~Move();

	//getters
	string getName();
	string getType();
	string getCategory();
	int getPower();
	int getAccuracy();
	int getPP();
	bool getContact();
	string getWeather();

	//setters
	void setName(json name);
	void setType(json type);
	void setCategory(json category);
	void setPower(json power);
	void setAccuracy(json accuracy);
	void setPP(json PP);
	void setContact(json contact);
	void setWeather(json weather);

private:

	string name;
	string type;
	string category;
	int power;
	int accuracy;
	int PP;
	bool contact;
	string weather;

};

