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
				char testi;
					do
					{
						StudentasA studentas;

						studentas.vardas = ivestiVardaArPavardeA("Iveskite varda: ");
						studentas.pavarde = ivestiVardaArPavardeA("Iveskite pavarde: ");
						
						std::cout << "Iveskite pazymi (0 - 10). Baigti -1\n";
						while (true)
						{
							int paz = ivestiIntSuValidacijaA("Pazymys: ", -1, 10);
							
							if (paz == -1)
							{
								break;
							}

							pridetiPazymi(studentas, paz);
						}
						
						studentas.egzaminas = ivestiIntSuValidacijaA("Iveskite egzamino rezultata (0-10): ", 0, 10);
						
						pridetiStudentaA(studentai, studentuKiekis, studentas);

						std::cout << "Ar norite ivesti kito studento duomenis? (t/n) ";
						std::cin >> testi;
					} while (testi == 't' || testi == 'T');

					if (studentuKiekis > 0);
					{
					int tipas = pasirinktiSkaiciavimoTipaA();
					
					skaicuotiRezultatusA(studentai, studentuKiekis, tipas);

					isvestiRezultatusA(studentai, studentuKiekis, tipas);
					}
					
					atlaisvinti(studentai, studentuKiekis);
				break;
			}
			case 2:
			{
				StudentasA* studentai = nullptr;
				int studentuKiekis = 0;
				char testi;
					
				do {

					StudentasA studentas;


					studentas.vardas = ivestiVardaArPavardeA("Iveskite varda: ");

					studentas.pavarde = ivestiVardaArPavardeA("Iveskite pavarde: ");

					int kiekis = ivestiIntSuValidacijaA("Kiek generuoti namu darbu pazymiu? ", 1, INT_MAX - 1);

					for (int i = 0; i < kiekis; ++i)

					{
						int paz = std::rand() % 10 + 1;
						pridetiPazymi(studentas, paz);
					}

					studentas.egzaminas = std::rand() % 10 + 1;

					pridetiStudentaA(studentai, studentuKiekis, studentas);

					std::cout << "Ar norite ivesti kito studento duomenis? (t/n) ";
					std::cin >> testi;
				} while (testi == 't' || testi == 'T');
					
					if (studentuKiekis > 0)
					{
						int tipas = pasirinktiSkaiciavimoTipaA();

						skaicuotiRezultatusA(studentai, studentuKiekis, tipas);

						isvestiRezultatusA(studentai, studentuKiekis, tipas);
					}
					
					atlaisvinti(studentai, studentuKiekis);
				
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
