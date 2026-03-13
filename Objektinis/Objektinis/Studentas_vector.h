#pragma once
#include <vector>
#include <string>

struct Studentas {
	std::string vardas;
	std::string pavarde;
	std::vector<int> pazymiai;
	int egzaminas;
	double rezultatas;
};
// function declarations

double calculateAverage(const std::vector<int>& grade);
double calculateMedian(std::vector<int> grade);
double calculateFinal(double ndReiksme, int egzaminas);
int pasirinktiSkaiciavimoTipa();
void skaicuotiRezultatus(std::vector<Studentas>& studentai, int skaiciavimoTipas);
void isvestiRezultatus(const std::vector<Studentas>& studentai, int skaiciavimoTipas);
int ivestiIntSuValidacija(const std::string& zinute, int min, int max);
std::string ivestiVardaArPavarde(const std::string& zinute);
//v0.2

void skaitytiIsFailo(const std::string& failoPavadinimas, std::vector<Studentas>& studentai);

bool compareByVardas(const Studentas& a, const Studentas& b);
bool compareByPavarde(const Studentas& a, const Studentas& b);
bool compareByRezultatas(const Studentas& a, const Studentas& b);

void rusiuotiStudentus(std::vector<Studentas>& studentai, int pasirinkimas);
int pasirinktiRusiavimoTipa();
void isvestiRezultatusIFaila(const std::vector<Studentas>& studentai, int skaiciavimoTipas, const std::string& failoPavadinimas);

//v0.4

void generuotiStudentuFaila(const std::string& failoPavadinimas, int studentuKiekis, int ndKiekis);

void padalintiStudentus(
	const std::vector<Studentas>& studentai,
	std::vector<Studentas>& nuskriaustieji,
	std::vector<Studentas>& kietiakiai
);

void atliktiFailoKurimoTyrima(const std::string& failoPavadinimas, int studentuKiekis, int ndKiekis);

void atliktiDuomenuApdorojimoTyrima(
	const std::string& failoPavadinimas,
	int skaiciavimoTipas,
	int rusiavimoTipas
);

void atliktiDuomenuApdorojimoTyrimoVidurki(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas, int kartu);

std::string gautiFailoVardaBePletinio(const std::string& failoPavadinimas);