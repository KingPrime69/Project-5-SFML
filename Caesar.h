#pragma once

#include <iostream>
#include <string>

class Caesar
{
public :
	Caesar();
	//~Caesar();

	void reset();
	void encryptChar(int letter);



private :
	int increment;


};

