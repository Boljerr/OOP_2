//ReSharper disable all
#include "Studentas_vector.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <limits>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdexcept>

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

int pasirinktiSkaiciavimoTipa()
{
		std::cout << "Ar rezultata skaiciuojama su mediana ar su vidurkiu\n";
		std::cout << "1 - vidurkis\n";
		std::cout << "2 - mediana\n";
	return ivestiIntSuValidacija("Pasirinkite: ",1,2);
}

void skaicuotiRezultatus(std::vector<Studentas>& studentai, int skaiciavimoTipas)
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

void isvestiRezultatus(const std::vector<Studentas>& studentai, int skaiciavimoTipas)
{
	std::string rez = (skaiciavimoTipas == 1) ? "Galutinis (Vid.)" : "Galutinis (Med.)";
	std::cout << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas"
		<< std::setw(20) << rez << "\n";
	for (int i = 0; i < studentai.size(); ++i)
	{
		std::cout << std::setw(15) << studentai[i].pavarde
			<< std::setw(15) << studentai[i].vardas
			<< std::fixed << std::setprecision(2) << studentai[i].rezultatas << "\n";
	}
}

int ivestiIntSuValidacija(const std::string& zinute, int min, int max)
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

std::string ivestiVardaArPavarde(const std::string& zinute)
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
				if (!std::isalpha(static_cast<unsigned char>(c)))
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

void skaitytiIsFailo(const std::string& failoPavadinimas, std::vector<Studentas>& studentai)
{
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

bool compareByVardas(const Studentas& a, const Studentas& b)
{
	return a.vardas < b.vardas;
}
bool compareByPavarde(const Studentas& a, const Studentas& b)
{
	return a.pavarde < b.pavarde;
}
bool compareByRezultatas(const Studentas& a, const Studentas& b)
{
	return a.rezultatas < b.rezultatas;
}
void rusiuotiStudentus(std::vector<Studentas>& studentai, int pasirinkimas)
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
		//std::cout << "Neteisingas pasirinkimas, rusiuojama pagal varda\n";
		//std::sort(studentai.begin(), studentai.end(), compareByVardas);
		break;
	}
}
int pasirinktiRusiavimoTipa()
{
	std::cout << "Pasirinkite rusiavimo tipa:\n";
	std::cout << "1 - pagal varda\n";
	std::cout << "2 - pagal pavarde\n";
	std::cout << "3 - pagal rezultata\n";
	return ivestiIntSuValidacija("Pasirinkite: ", 1, 3);
}

void isvestiRezultatusIFaila(const std::vector<Studentas>& studentai, int skaiciavimoTipas, const std::string& failoPavadinimas)
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
	
		for (int i = 0; i < studentai.size(); i++ )
		{
			out << std::setw(15) << studentai[i].pavarde
				<< std::setw(15) << studentai[i].vardas
				<< std::setw(20) << std::setprecision(2) << studentai[i].rezultatas << "\n";
		}

		out.close();
		std::cout << "Rezultatai issaugoti faile: " << failoPavadinimas << "\n";

}

void generuotiStudentuFaila(const std::string& failoPavadinimas, int studentuKiekis, int ndKiekis)
{
	std::ofstream out(failoPavadinimas);

	if (!out.is_open())
	{
		throw std::runtime_error("Nepavyko sukurti failo: " + failoPavadinimas);
	}
	out << std::left << std::setw(15) << "Pavarde"
		<< std::setw(15) << "Vardas";

	for (int i = 1; i <= ndKiekis; ++i)
	{
		out << "ND" << i << " ";
	}
	out << ""

}
