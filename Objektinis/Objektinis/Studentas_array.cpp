#include "Studentas_array.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cctype>

void pridetiPazymi(StudentasA& s, int paz)
{
	int* naujas = new int[s.pazKiekis + 1];
	for (int i = 0; i < s.pazKiekis; ++i)
	{
		naujas[i] = s.pazymiai[i];
	}

	naujas[s.pazKiekis] = paz;
	delete[] s.pazymiai;
	s.pazymiai = naujas;
	s.pazKiekis++;
}
double calculateAverageA(int* paz, int kiekis)
{
	if (kiekis == 0)
		return 0.0;
		
	int suma = 0;
	for (int i = 0; i < kiekis; i++)
	{
		suma += paz[i];
	}
	return (double)suma / kiekis;
}
double calculateMedianaA(int* paz, int kiekis)
{
	if (kiekis == 0) 
		return 0.0;

	int* kopija = new int[kiekis];
	
	for (int i = 0; i < kiekis; ++i)
	{
		kopija[i] = paz[i];
	}

	std::sort(kopija, kopija + kiekis);

	double med;

	if (kiekis % 2 == 1)
	{
		med = kopija[kiekis / 2];
	}
	else
	{
		med = (kopija[kiekis / 2 - 1] + kopija[kiekis / 2]) / 2.0;
	}

	delete[] kopija;

	return med;
}

double calculateFinalA(double ndReiksme, int egzaminas)
{
	return 0.4 * ndReiksme + 0.6 * egzaminas;
}

int pasirinktiSkaiciavimoTipaA()
{
	std::cout << "Ar rezultata skaiciuojama su mediana ar su vidurkiu\n";
	std::cout << "1 - vidurkis\n";
	std::cout << "2 - mediana\n";
		return ivestiIntSuValidacijaA("Pasirinkite: ", 1, 2);
}
void skaicuotiRezultatusA(StudentasA* studentai, int kiekis, int skaiciavimoTipas)
{
	for (int i = 0; i < kiekis; ++i)
	{
		double nd;
		if (skaiciavimoTipas == 1)
		{
			nd = calculateAverageA(studentai[i].pazymiai, studentai[i].pazKiekis);
		}
		else
		{
			nd = calculateMedianaA(studentai[i].pazymiai, studentai[i].pazKiekis);
		}
		studentai[i].rezultatas = calculateFinalA(nd, studentai[i].egzaminas);
	}
}

void isvestiRezultatusA(StudentasA* studentai, int studentuKiekis, int skaiciavimoTipas)
{
	std::string rez = (skaiciavimoTipas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";

	std::cout << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< std::setw(20) << rez << "\n";
	for (int i = 0; i < studentuKiekis; ++i)
	{
		std::cout << std::setw(15) << studentai[i].pavarde
			<< std::setw(15) << studentai[i].vardas
			<< std::fixed << std::setprecision(2) << studentai[i].rezultatas << "\n";
	}
}

void pridetiStudentaA(StudentasA*& arr, int& kiekis, const StudentasA& naujas)
{
	StudentasA* temp = new StudentasA[kiekis + 1];

	for (int i = 0; i < kiekis; ++i)
	{
		temp[i] = arr[i];
	}

	temp[kiekis] = naujas;

	delete[] arr;
	arr = temp;
	kiekis++;
}

void atlaisvinti(StudentasA* arr, int kiekis)
{
	for (int i = 0; i < kiekis; ++i)
	{
		delete[] arr[i].pazymiai;
	}
	delete[] arr;
}
int ivestiIntSuValidacijaA(const std::string& zinute, int min, int max)
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

std::string ivestiVardaArPavardeA(const std::string& zinute)
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
