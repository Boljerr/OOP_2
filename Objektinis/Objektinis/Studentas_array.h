#pragma once
#include <string>


struct StudentasA {
	std::string vardas;
	std::string pavarde;
	
	int* pazymiai;
	int pazKiekis;
	
	int egzaminas;
	double rezultatas;

};

// Funkcijos

void pridetiPazymi(StudentasA& s, int paz);

double calculateAverageA(int* paz, int kiekis);
double calculateMedianaA(int* paz, int kiekis);

void pridetiStudenta(StudentasA*& arr, int& kiekis, const StudentasA& naujas);

void atlaisvinti(StudentasA* arr, int kiekis);

int ivestiIntSuValidacija(const std::string& zinute, int min, int max);
std::string ivestiVardaArPavarde(const std::string& zinute);
