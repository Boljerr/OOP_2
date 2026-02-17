//ReSharper disable all
#include <iostream>

void paleistiVectorVersija();
void paleistiArrayVersija();

int main()
{
	int pasirinkimas;

	do {
		std::cout << "\n=============PASRRINIKITE VERSIJA=============\n";
		std::cout << "1 - Vector versija\n";
		std::cout << "2 - Array versija \n";
		std::cout << "3 - Baigti\n";
		std::cin >> pasirinkimas;
		if (std::cin.fail())
		{
			std::cout << "Ivestis turi buti skaicius.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch (pasirinkimas)
		{
		case 1:
			paleistiVectorVersija();
			break;
		case 2:
			paleistiArrayVersija();
			break;
		case 3:
			std::cout << "Programa baigiama.\n";
			break;
		default:
			std::cout << "Neteisingas pasirinkimas, bandykite dar karta.\n";
		}

	} while (pasirinkimas != 3);
	return 0;
}