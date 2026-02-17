//ReSharper disable all
#include <cstdlib>
#include <ctime>
#include <limits>
#include<iostream>
#include<string>
#include<iomanip>
#include "Studentas_array.h"

void paleistiArrayVersija()
{
	std::srand(std::time(nullptr));
	int pasirinkimas;
	do {
		std::cout << "\n=============MENIU=============\n";
		std::cout << "1 - Rankinis ivedimas\n";
		std::cout << "2 - Generuoti tik pazymius \n";
		std::cout << "3 - Generuoti studentus ir pazymius\n";
		std::cout << "4 - Baigti\n";
		std::cin >> pasirinkimas;
		if (std::cin.fail())
		{
			std::cout << "Ivestis turi buti skaicius.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		switch (pasirinkimas)
		{
			case 1:
			{
				StudentasA* studentai = nullptr;
				int studentuKiekis = 0;
				//char testi;
				//	do
				//	{
						
				//	} while (testi == 't' || testi == 'T');
				break;
			}
			case 2:
			{
				std::cout << "Generuoti tik pazymius dar neivesta\n";
				break;
			}
			case 3:
			{
				std::cout << "Generuoti studentus ir pazymius dar neivesta\n";
				break;
			}
			case 4:
			{
				std::cout << "Programa baigiama.\n";
				break;
			}


		}
	} while (pasirinkimas != 4);
}