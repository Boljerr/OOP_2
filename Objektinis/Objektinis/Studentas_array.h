#pragma once
#include <string>


struct StudentasA {
	std::string vardas;
	std::string pavarde;
	
	int* pazymiai;
	int pazKiekis;
	
	int egzaminas;
	double rezultatas;
	
	StudentasA()
	{
		pazymiai = nullptr;
		pazKiekis = 0;
		egzaminas = 0;
		rezultatas = 0.0;
	}

};

// Funkcijos

void pridetiPazymi(StudentasA& s, int paz);

double calculateAverageA(int* paz, int kiekis);
double calculateMedianaA(int* paz, int kiekis);
double calculateFinalA(double ndReiksme, int egzaminas);

int pasirinktiSkaiciavimoTipaA();
void skaicuotiRezultatusA(StudentasA* studentai, int kiekis, int skaiciavimoTipas);

void isvestiRezultatusA(StudentasA* studentai, int studentuKiekis, int skaiciavimoTipas);



void pridetiStudentaA(StudentasA*& arr, int& kiekis, const StudentasA& naujas);

void atlaisvinti(StudentasA* arr, int kiekis);

int ivestiIntSuValidacijaA(const std::string& zinute, int min, int max);
std::string ivestiVardaArPavardeA(const std::string& zinute);
