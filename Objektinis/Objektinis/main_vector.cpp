//ReSharper disable CommentTypo
//ReSharper disable IdentifierTypo
//ReSharper disable All
// Objektinis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstdlib>
#include <ctime>
#include <limits>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include "Studentas_vector.h"

int main()
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
			std::vector<Studentas> studentai;
			char testi;

			do {
				Studentas studentas;
				studentas.vardas = ivestiVardaArPavarde("Iveskite varda: ");
				studentas.pavarde = ivestiVardaArPavarde("Iveskite pavarde: ");

				std::cout << "Iveskite pazymi (0 - 10). Baigti -1\n";

				while (true)
				{
					int temp = ivestiIntSuValidacija("Pazymys: ", -1, 10);
					
					if (temp == -1)
					{
						break; // baigia ivesti pazymius
					}

					studentas.pazymiai.push_back(temp);
				}
				if (studentas.pazymiai.empty())
				{
					std::cout << "Nerasta pazymiu, galutinis bus skaiciuojamas tik is egzamino\n";
				}

				studentas.egzaminas = ivestiIntSuValidacija("Iveskite egzamino rezultata (0-10): ", 0, 10);

				studentai.push_back(studentas);

				std::cout << "Ar norite ivesti kito studento duomenis? (t/n) ";
				std::cin >> testi;

			} while (testi == 't' || testi == 'T');

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();

			skaicuotiRezultatus(studentai, skaiciavimoTipas);
			isvestiRezultatus(studentai, skaiciavimoTipas);
			
			break;
		}
		case 2:
			{
			std::vector<Studentas> studentai;
			char testi;

				do
				{
					Studentas studentas;
					std::cout << "Iveskite varda ir pavarde: ";
					std::cin >> studentas.vardas >> studentas.pavarde;

					int kiekis = 0;
					std::cout << "Kiek generuoti namu darbu pazymiu?";
					std::cin >> kiekis;

					for (int i = 0; i < kiekis; ++i)
					{
						int paz = std::rand() % 10 + 1;
						studentas.pazymiai.push_back(paz);
					}
					studentas.egzaminas = std::rand() % 10 + 1;
					
					studentai.push_back(studentas);
					
					std::cout << "Ar generuoti dar viena studenta? (t/n): ";
					std::cin >> testi;
				
				} while (testi == 't' || testi == 'T');

				int skaiciavimoTipas;

				break;
			}
		case 3:
			{
				std::cout << "studentu+ paz";
				break;
			}
		case 4:
			{
				std::cout << "Programa baigiama. \n";
				break;
			}
		default:
			{
				std::cout << "Neteisingas pasirinkimas";
			}
		}

	} while (pasirinkimas != 4);
}


