#include "VectorFunkcijos.h"
#include "Bendra.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdexcept>
#include <cstdlib>

void skaitytiIsFailoVector(const std::string& failoPavadinimas, std::vector<Studentas>& studentai)
{
	studentai.clear();
	std::ifstream in(failoPavadinimas);

	if (!in.is_open())
	{
		throw std::runtime_error("Nepavyko atidaryti failo: " + failoPavadinimas);
	}

	std::string eilute;

	std::getline(in, eilute); // praleidzia pirma eilute su antraste

	while (std::getline(in, eilute))
	{
		std::stringstream ss(eilute);
		Studentas studentas;

		if (!(ss >> studentas.vardas >> studentas.pavarde))
		{
			throw std::runtime_error("Netinkamas duomenu formatas");
		}

		int paz;
		std::vector<int> visiPaz;

		while (ss >> paz)
		{
			if (paz < 0 || paz > 10)
			{
				throw std::runtime_error("Faile rastas netinkamas pazymys");
			}
			visiPaz.push_back(paz);
		}

		if (visiPaz.empty())
		{
			throw std::runtime_error("Studentui nerastas nei vienas pazymys ar egzamino rezultatas");
		}
		studentas.egzaminas = visiPaz.back();
		visiPaz.pop_back();
		studentas.pazymiai = visiPaz;

		studentai.push_back(studentas);
	}
	in.close();
}

void skaiciuotiRezultatusVector(std::vector<Studentas>& studentai, int skaiciavimoTipas)
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

void rusiuotiStudentusVector(std::vector<Studentas>& studentai, int pasirinkimas)
{
	switch (pasirinkimas)
	{
	case 1:
		std::sort(studentai.begin(), studentai.end(), compareByVardas);
		break;
	case 2:
		std::sort(studentai.begin(), studentai.end(), compareByPavarde);
		break;
	case 3:
		std::sort(studentai.begin(), studentai.end(), compareByRezultatas);
		break;
	default:
		break;
	}

}

void isvestiRezultatusVector(const std::vector<Studentas>& studentai, int skaiciavimoTipas)
{
	std::string rez = (skaiciavimoTipas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";
	std::cout << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< std::setw(20) << rez << "\n";
	std::cout << "--------------------------------------------------\n";
	for (int i = 0; i < studentai.size(); i++)
	{
		std::cout << std::setw(15) << studentai[i].pavarde
			<< std::setw(15) << studentai[i].vardas
			<< std::fixed << std::setprecision(2) << studentai[i].rezultatas << "\n";
	}
}

void isvestiRezultatusIFailaVector(const std::vector<Studentas>& studentai, int skaiciavimoTipas, const std::string& failoPavadinimas)
{
	std::ofstream out(failoPavadinimas);
	if (!out.is_open())
	{
		std::cout << " Nepavyko sukurti rezultatu failo.\n";
		return;
	}
	std::string rez = (skaiciavimoTipas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";
	out << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< std::setw(20) << rez << "\n";
	out << "--------------------------------------------------\n";

	for (int i = 0; i < studentai.size(); i++)
	{
		out << std::setw(15) << studentai[i].pavarde
			<< std::setw(15) << studentai[i].vardas
			<< std::fixed << std::setprecision(2) << studentai[i].rezultatas << "\n";
	}
	out.close();
	std::cout << "Rezultatai issaugoti faile: " << failoPavadinimas << "\n";
}
