// Objektinis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
struct Studentas {
	std::string vardas;
	std::string pavarde;
	//int* pazymiai;
	std::vector<int> pazymiai;
	int egzaminas;
	double rezultatas;
};

#include <iostream>

int main()
{
	Studentas A;
	std::cout << "Iveskite varda ir pavarde: ";
	std::cin >> A.vardas >> A.pavarde;
	std::cout << "Kiek pazymiu ivesite? ";
	int n, temp;
	double average = 0;
	int total = 0;
	double median = 0;
	std:: cin >> n;
	for (int i = 0; i < n ; i++)
	{
		std::cout << "Iveskite pazymi\n";
		std::cin >> temp;
		A.pazymiai.push_back(temp);
		total += temp;
		
	}
	sort(A.pazymiai.begin(), A.pazymiai.end());

	if(n%2 == 1)
	{
		median = A.pazymiai[n / 2];
		std::cout << "Mediana: " << median << "\n";
	}
	else
	{
		median = (A.pazymiai[n / 2 - 1] + A.pazymiai[n / 2]) / 2.0;
		std::cout << "Mediana: " << median << "\n";
	}
	std::cout << "Iveskite egzamino rezultata: ";
	std::cin >> A.egzaminas;

	average = total / n;
	std::cout << "Vardas: " << A.vardas << "\nPavarde: " << A.pavarde << "\n";
	std::cout << "Atsakymai:\n";

	for (auto b : A.pazymiai)
		std::cout << b << " ";
	std::cout << "\nVidurkis: " << average << "\n";

	A.rezultatas = 0.4 * average + 0.6 * A.egzaminas;
	std::cout << "Galutinis rezultatas: " << A.rezultatas << "\n";
	A.rezultatas = 0.4 * median + 0.6 * A.egzaminas;
	std::cout << "Galutinis rezultatas (mediana): " << A.rezultatas << "\n";
	
}

