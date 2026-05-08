#include "ListFunkcijos.h"

#include <algorithm>

#include "Bendra.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void skaitytiIsFailoList(const std::string& failoPavadinimas, std::list<Studentas>& studentai)
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

void skaiciuotiRezultatusList(std::list<Studentas>& studentai, int skaiciavimoTipas)
{
	for (auto& studentas : studentai)
	{
		double nd;
		if (skaiciavimoTipas == 1)
		{
			nd = calculateAverage(studentas.pazymiai);
		}
		else
		{
			nd = calculateMedian(studentas.pazymiai);
		}
		studentas.rezultatas = calculateFinal(nd, studentas.egzaminas);
	}
}

void rusiuotiStudentusList(std::list<Studentas>& studentai, int pasirinkimas)
{
	switch (pasirinkimas)
	{
	case 1:
		studentai.sort(compareByVardas);
		break;
	case 2:
		studentai.sort(compareByPavarde);
		break;
	case 3:
		studentai.sort(compareByRezultatas);
		break;
	default:
		break;
	}
}

void padalintiStudentus1List(const std::list<Studentas>& studentai, std::list<Studentas>& nuskriaustieji, std::list<Studentas>& kietiakiai)
{
	nuskriaustieji.clear();
	kietiakiai.clear();

	for (const auto& studentas : studentai)
	{
		if (studentas.rezultatas < 5)
		{
			nuskriaustieji.push_back(studentas);
		}
		else
		{
			kietiakiai.push_back(studentas);
		}
	}
}
