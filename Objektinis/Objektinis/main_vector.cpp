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

		int n;
		do {
			std::cout << "Kiek pazymiu ivesite? ";

			std::cin >> n;

			if (std::cin.fail())
			{
				std::cout << "Ivestis turi buti skaicius, bandykite dar karta\n";
				std::cin.clear(); // isvalo klaidos busena
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoruoja netinkama ivesti iki naujos eilutes
				n = -1; // i neigiamas kad loop eitu vel

			}
			else if (n <= 0)
			{
				std::cout << "Pazymiu skaicius turi buti teigiamas, bandykite dar karta\n";
			}
		} while (n <= 0);


		for (int i = 0; i < n; i++)
		{
			int temp;

			do {
				std::cout << "Iveskite pazymi (0 - 10)\n";
				std::cin >> temp;

				if (std::cin.fail())
				{
					std::cout << "Ivestis turi buti skaicius, bandykite dar karta\n";
					std::cin.clear(); // isvalo klaidos busena
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoruoja netinkama ivesti iki naujos eilutes
					temp = -1; // i neigiamas kad loop eitu velj
				}
				else if (temp < 0 || temp > 10)
				{
					std::cout << "Pazymys turi buti tarp 0 ir 10, bandykite dar karta\n";
				}
			} while (temp < 0 || temp > 10);

			studentas.pazymiai.push_back(temp);
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
	std::string rez = "";

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

	for (int i = 0; i < studentai.size(); ++i)
	{

		if (choice == 1)
		{
			double average = calculateAverage(studentai[i].pazymiai);
			studentai[i].rezultatas = calculateFinal(average, studentai[i].egzaminas);
			rez = "Galutinis (Vid.)";

		}
		else
		{
			double median = calculateMedian(studentai[i].pazymiai);
			studentai[i].rezultatas = calculateFinal(median, studentai[i].egzaminas);
			rez = "Galutinis (Med.)";
		}

	}
	std::cout << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< rez << "\n";


	for (int i = 0; i < studentai.size(); ++i)
	{
		std::cout << std::setw(15) << studentai[i].pavarde
			<< std::setw(15) << studentai[i].vardas
			<< std::fixed << std::setprecision(2) << studentai[i].rezultatas << "\n";

	}
}

