#include "DequeFunkcijos.h"
#include "Bendra.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>


void skaitytiIsFailoDeque(const std::string& failoPavadinimas, std::deque<Studentas>& studentai)
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

void skaiciuotiRezultatusDeque(std::deque<Studentas>& studentai, int skaiciavimoTipas)
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

void rusiuotiStudentusDeque(std::deque<Studentas>& studentai, int pasirinkimas)
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

void padalintiStudentusDeque(const std::deque<Studentas>& studentai, std::deque<Studentas>& nuskriaustieji, std::deque<Studentas>& kietiakiai)
{
	nuskriaustieji.clear();
	kietiakiai.clear();
	for (int i = 0; i < studentai.size(); ++i)
	{
		if (studentai[i].rezultatas < 5)
		{
			nuskriaustieji.push_back(studentai[i]);
		}
		else
		{
			kietiakiai.push_back(studentai[i]);
		}
	}
}


