//ReSharper disable CommentTypo
//ReSharper disable IdentifierTypo
//ReSharper disable All
// Objektinis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <limits>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include "Studentas_vector.h"

int main()
{
	std::vector<Studentas> studentai;
	char testi;

	do {
		Studentas studentas;
		std::cout << "Iveskite varda ir pavarde: ";
		std::cin >> studentas.vardas >> studentas.pavarde;

		int temp;
		std::cout << "Iveskite pazymi (0 - 10). Baigti -1\n";
		
		while (true) 
		{
			std::cout << "Pazymys: ";
			std::cin >> temp;

			if (std::cin.fail())
			{
				std::cout << "Ivestis turi buti skaicius, bandykite dar karta\n";
				std::cin.clear(); // isvalo klaidos busena
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoruoja netinkama ivesti iki naujos eilutes
				continue;
			}
			if (temp == -1)
			{
				break; // baigia ivesti pazymius
			}

			else if (temp < 0 || temp > 10)
			{
				std::cout << "Pazymys turi buti tarp 0 ir 10, bandykite dar karta\n";
				continue;
			}
			studentas.pazymiai.push_back(temp);
		}
		if (studentas.pazymiai.empty())
		{
			std::cout << "Nerasta pazymiu, galutinis bus skaiciuojamas tik is egzamino\n";
		}

		do
		{

			std::cout << "Iveskite egzamino rezultata: ";
			std::cin >> studentas.egzaminas;

			if (std::cin.fail())
			{
				std::cout << "Ivestis turi buti skaicius, bandykite dar karta\n";
				std::cin.clear(); // isvalo klaidos busena
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoruoja netinkama ivesti iki naujos eilutes
				studentas.egzaminas = -1; // i neigiamas kad loop eitu vel
			}
			else if (studentas.egzaminas < 0 || studentas.egzaminas > 10)
			{
				std::cout << "Egzamino rezultatas turi buti tarp 0 ir 10, bandykite dar karta\n";
			}

		} while (studentas.egzaminas < 0 || studentas.egzaminas > 10);
		studentai.push_back(studentas);

		std::cout << "Ar norite ivesti kito studento duomenis? (t/n) ";
		std::cin >> testi;
	} while (testi == 't' || testi == 'T');

	int choice;
	
	do
	{
		std::cout << "Ar rezultata skaiciuojama su mediana ar su vidurkiu\n";
		std::cout << "1 - vidurkis\n";
		std::cout << "2 - mediana\n";
		std::cout << "Pasirinkite: ";

		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cout << "Ivestis turi buti skaicius, bandykite dar karta\n";
			std::cin.clear(); // isvalo klaidos busena
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoruoja netinkama ivesti iki naujos eilutes
			choice = -1; // i neigiamas kad loop eitu vel
		}
		else if (choice != 1 && choice != 2)
		{
			std::cout << "Neteisingas pasirinkimas, bandykite dar karta\n";
		}

	} while (choice != 1 && choice != 2);

	std::string rez = (choice == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";


	for (int i = 0; i < studentai.size(); ++i)
	{
		double nd;
		if (choice == 1)
		{
			nd = calculateAverage(studentai[i].pazymiai);
		}
		else
		{
			nd = calculateMedian(studentai[i].pazymiai);
		}
		studentai[i].rezultatas = calculateFinal(nd, studentai[i].egzaminas);

	}
	std::cout << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<<std::setw(20)<< rez << "\n";


	for (int i = 0; i < studentai.size(); ++i)
	{
		std::cout << std::setw(15) << studentai[i].pavarde
			<< std::setw(15) << studentai[i].vardas
			<< std::fixed << std::setprecision(2) << studentai[i].rezultatas << "\n";

	}
}

