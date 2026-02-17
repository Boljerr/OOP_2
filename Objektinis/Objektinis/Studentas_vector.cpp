#include "Studentas_vector.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <limits>

double calculateAverage(const std::vector<int>& grade) // Cia reference tiesiog nes tipo nereikia nieko keisti
{
	if (grade.empty()) return 0.0;
	int suma = 0;
	for (int i = 0; i < grade.size(); i++)
	{
		suma += grade[i];
	}
	return (double)suma / grade.size();
}

double calculateMedian(std::vector<int> grade) // cia kopija nes tipo sortini
{
	if (grade.empty()) return 0.0;

	std::sort(grade.begin(), grade.end());

	int n = grade.size();

	if (n % 2 == 1)
	{
		return grade[n / 2];
	}
	else
	{
		return (grade[n / 2 - 1] + grade[n / 2]) / 2.0;
	}
}

double calculateFinal(double ndReiksme, int egzaminas)
{
	return 0.4 * ndReiksme + 0.6 * egzaminas;
}

int pasirinktiSkaiciavimoTipa()
{
		std::cout << "Ar rezultata skaiciuojama su mediana ar su vidurkiu\n";
		std::cout << "1 - vidurkis\n";
		std::cout << "2 - mediana\n";
	return ivestiIntSuValidacija("Pasirinkite: ",1,2);
}

void skaicuotiRezultatus(std::vector<Studentas>& studentai, int skaiciavimoTipas)
{
	for (int i = 0; i < studentai.size(); ++i)
	{
		double nd;
		if (skaiciavimoTipas == 1)
		{
			nd = calculateAverage(studentai[i].pazymiai);
		}
		else
		{
			nd = calculateMedian(studentai[i].pazymiai);
		}
		studentai[i].rezultatas = calculateFinal(nd, studentai[i].egzaminas);
	}
}

void isvestiRezultatus(const std::vector<Studentas>& studentai, int skaiciavimoTipas)
{
	std::string rez = (skaiciavimoTipas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";
	std::cout << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< std::setw(20) << rez << "\n";
	for (int i = 0; i < studentai.size(); ++i)
	{
		std::cout << std::setw(15) << studentai[i].pavarde
			<< std::setw(15) << studentai[i].vardas
			<< std::fixed << std::setprecision(2) << studentai[i].rezultatas << "\n";
	}
}

int ivestiIntSuValidacija(const std::string& zinute, int min, int max)
{
	int value;
	while (true)
	{
		std::cout << zinute;
		std::cin >> value;
		if (std::cin.fail())
		{
			std::cout << "Ivestis turi buti skaicius, bandykite dar karta\n";
			std::cin.clear(); // isvalo klaidos busena
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoruoja netinkama ivesti iki naujos eilutes
			continue;
		}
		else if (value < min || value > max)
		{
			std::cout << "Ivestis turi buti tarp " << min << " ir " << max << ", bandykite dar karta\n";
			continue;
		}
		else
		{
			return value;
		}
	}
}

std::string ivestiVardaArPavarde(const std::string& zinute)
{
	std::string tekstas;
	while (true)
	{
		std::cout << zinute;
		std::cin >> tekstas;
		if (tekstas.empty())
		{
			std::cout << "Ivestis negali buti tuscia, bandykite dar karta\n";
			continue;
		}
		bool teisingas = true;
			
		for (char c : tekstas)
		{
				if (!std::isalpha(c))
				{
					teisingas = false;
					break;
				}
		}
		if (!teisingas)
		{
			std::cout << "Ivestis turi buti sudaryta tik is raidziu, bandykite dar karta\n";
			continue;
		}
		return tekstas;
		
	}
}
