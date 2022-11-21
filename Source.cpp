# include "Caesar.h "
# include <string>
# include <iostream>



static void encryptString(Caesar& encryptionMethod, std::string const& toEncrypt)
{
	size_t len = toEncrypt.size();
	encryptionMethod.reset();
	for (size_t i = 0; i < len; i++)
	{
		encryptionMethod.encryptChar(toEncrypt[i]);
	}
	std::cout << std::endl;
}
static void decryptString(Caesar& encryptionMethod,
	std::string const& toDecrypt)
{
	size_t len = toDecrypt.size();
	encryptionMethod.reset();
	for (size_t i = 0; i < len; i++)
	{
		//encryptionMethod.decryptChar(toDecrypt[i]);
	}
	std::cout << std::endl;
}

int main()
{
	Caesar c;
	encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
	decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !"
	);
	encryptString(c, "KIKOO ");
	encryptString(c, "LULZ XD");
	decryptString(c, "Ziqivun ea Ndcsg. Wji !");
	return 0;
}