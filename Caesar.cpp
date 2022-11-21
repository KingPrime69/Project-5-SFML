#include "Caesar.h"

Caesar::Caesar()
{
	this->increment = 2;
}

void Caesar::reset()
{
	this->increment = 2;
}

void Caesar::encryptChar(int letter)
{
	char temp = letter;
	this->increment++;
	if (this->increment > 26)this->increment = 1;
	char newLetter = letter;

	if (letter > 96 && letter < 123) {
		if (letter+this->increment > 122) {
			int rectify = 123 - letter;
			newLetter = 97 + this->increment - rectify;
		}
		else newLetter = letter+this->increment;
	}
	if (letter > 64 && letter < 91) {
		if (letter + this->increment > 90) {
			int rectify = 91 - letter;
			newLetter = 65 + this->increment - rectify;
		}
		else newLetter = letter + this->increment;
	}
	//int itemp = newLetter;
	//std::cout << "increment : " << this->increment << std::endl;
	//std::cout << "letter : " << temp << std::endl;
	//std::cout << "ACSII l: " << letter << std::endl;
	//std::cout << "newL : " << newLetter << std::endl;
	//std::cout << "ACSII nl : " << itemp << std::endl << std::endl;

	//std::cout << "letter : " << temp << std::endl;
	//std::cout << letter << std::endl << std::endl;
	//std::cout << letter+this->increment << std::endl;
	std::cout << newLetter;
}

void Caesar::decryptChar(int letter)
{
	char temp = letter;
	this->increment++;
	if (this->increment > 26)this->increment = 1;
	char newLetter = letter;

	if (letter > 96 && letter < 123) {
		if (letter - this->increment < 97) {
			int rectify = letter - 96;
			newLetter = 122 - this->increment + rectify;
		}
		else newLetter = letter - this->increment;
	}

	if (letter > 64 && letter < 91) {
		if (letter - this->increment < 65) {
			int rectify = letter - 64;
			newLetter = 90 - this->increment + rectify;
		}
		else newLetter = letter - this->increment;
	}

	//int itemp = newLetter;
	//std::cout << "increment : " << this->increment << std::endl;
	//std::cout << "letter : " << temp << std::endl;
	//std::cout << "ACSII l: " << letter << std::endl;
	//std::cout << "newL : " << newLetter << std::endl;
	//std::cout << "ACSII nl : " << itemp << std::endl << std::endl;

	//std::cout << "letter : " << temp << std::endl;
	//std::cout << letter << std::endl << std::endl;
	//std::cout << letter+this->increment << std::endl;
	std::cout << newLetter;
}
