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
