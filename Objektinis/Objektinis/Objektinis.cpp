//ReSharper disable CommentTypo
//ReSharper disable IdentifierTypo
//ReSharper disable All
// Objektinis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>

struct Studentas {
	std::string vardas;
	std::string pavarde;
	std::vector<int> pazymiai;
	int egzaminas;
	double Rezultatas;
};

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



int main()
{
	Studentas studentas;

	std::cout << "Iveskite varda ir pavarde: ";
	std::cin >> studentas.vardas >> studentas.pavarde;

	int n;

	do {
		std::cout << "Kiek pazymiu ivesite? ";

		std::cin >> n;
		if (n < 0)
		{
			std::cout << "Pazymiu skaicius turi buti teigiamas, bandykite dar karta\n";
		}
	} while (n < 0);


	for (int i = 0; i < n ; i++)
	{
		int temp;
		std::cout << "Iveskite pazymi\n";
		std::cin >> temp;
		studentas.pazymiai.push_back(temp);
	}
	
	double average = calculateAverage(studentas.pazymiai);
	double median = calculateMedian(studentas.pazymiai);


	std::cout << "Iveskite egzamino rezultata: ";
	std::cin >> studentas.egzaminas;


	int choice;
	std::string rez = "";

	do
	{
		std::cout << "Ar rezultata skaiciuojama su mediana ar su vidurkiu\n";
		std::cout << "1 - vidurkis\n";
		std::cout << "2 - mediana\n";
		std::cout << "Pasirinkite: ";

		std::cin >> choice;

		if (choice != 1 && choice !=2)
		{
			std::cout << "Neteisingas pasirinkimas, bandykite dar karta\n";
		}
		
	} while (choice != 1 && choice != 2);


	if (choice == 1)
	{
		studentas.Rezultatas = calculateFinal(average, studentas.egzaminas);
		rez = "Galutinis (Vid.)";
		
	}
	else
	{
		studentas.Rezultatas = calculateFinal(median, studentas.egzaminas);
		rez = "Galutinis (Med.)";
	}


	std::cout <<std::left <<std::setw(15)<< "Pavarde " 
		<< std::setw(15)<< "Vardas " 
		<< rez	<< "\n";
	std::cout <<std::setw(15)<< studentas.pavarde
	<< std::setw(15) << studentas.vardas
	<< std::fixed << std::setprecision(2) << studentas.Rezultatas << "\n";
	
}

