//ReSharper disable All

#include <cstdlib>
#include <ctime>
#include <limits>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<filesystem>

#include "struktura.h"
#include "Studentas_vector.h"

void paleistiVectorVersija()
{
	std::srand(std::time(nullptr));
	int pasirinkimas;
	do {
		std::cout << "\n=============MENIU=============\n";
		std::cout << "1 - Rankinis ivedimas\n";
		std::cout << "2 - Generuoti tik pazymius \n";
		std::cout << "3 - Generuoti studentus ir pazymius\n";
		std::cout << "4 - Nuskaityti is failo\n";
		std::cout << "5 - Baigti\n";
		std::cin >> pasirinkimas;
		if (std::cin.fail())
		{
			std::cout << "Ivestis turi buti skaicius.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (pasirinkimas)
		{
		case 1:
		{
			std::vector<Studentas> studentai;
			char testi;

			do {
				Studentas studentas;
				studentas.vardas = ivestiVardaArPavarde("Iveskite varda: ");
				studentas.pavarde = ivestiVardaArPavarde("Iveskite pavarde: ");

				std::cout << "Iveskite pazymi (0 - 10). Baigti -1\n";

				while (true)
				{
					int temp = ivestiIntSuValidacija("Pazymys: ", -1, 10);

					if (temp == -1)
					{
						break;
					}

					studentas.pazymiai.push_back(temp);
				}
				if (studentas.pazymiai.empty())
				{
					std::cout << "Nerasta pazymiu, galutinis bus skaiciuojamas tik is egzamino\n";
				}

				studentas.egzaminas = ivestiIntSuValidacija("Iveskite egzamino rezultata (0-10): ", 0, 10);

				studentai.push_back(studentas);

				std::cout << "Ar norite ivesti kito studento duomenis? (t/n) ";
				std::cin >> testi;

			} while (testi == 't' || testi == 'T');

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();

			skaicuotiRezultatus(studentai, skaiciavimoTipas);
			isvestiRezultatus(studentai, skaiciavimoTipas);

			break;
		}
		case 2:
		{
			std::vector<Studentas> studentai;
			char testi;

			do
			{
				Studentas studentas;
				studentas.vardas = ivestiVardaArPavarde("Iveskite varda: ");
				studentas.pavarde = ivestiVardaArPavarde("Iveskite pavarde: ");

				int kiekis = ivestiIntSuValidacija("Kiek generuoti namu darbu pazymiu? ", 1, INT_MAX - 1);


				for (int i = 0; i < kiekis; ++i)
				{
					int paz = std::rand() % 10 + 1;
					studentas.pazymiai.push_back(paz);
				}

				studentas.egzaminas = std::rand() % 10 + 1;

				studentai.push_back(studentas);

				std::cout << "Ar generuoti dar viena studenta? (t/n): ";
				std::cin >> testi;

			} while (testi == 't' || testi == 'T');

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();
			skaicuotiRezultatus(studentai, skaiciavimoTipas);
			isvestiRezultatus(studentai, skaiciavimoTipas);

			break;
		}
		case 3:
		{
			std::vector<Studentas> studentai;

			int studentuKiekis = ivestiIntSuValidacija("Kiek generuoti studentu? ", 1, INT_MAX - 1);
			int ndKiekis = ivestiIntSuValidacija("Kiek generuoti namu darbu pazymiu kiekvienam? ", 1, INT_MAX - 1);

			for (int i = 0; i < studentuKiekis; i++)
			{
				zmogus z = gen();

				Studentas studentas;
				studentas.vardas = z.vardas;
				studentas.pavarde = z.pavarde;

				for (int j = 0; j < ndKiekis; ++j)
				{
					studentas.pazymiai.push_back(gen().paz);
				}

				studentas.egzaminas = std::rand() % 10 + 1;
				studentai.push_back(studentas);
			}
			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();

			skaicuotiRezultatus(studentai, skaiciavimoTipas);
			isvestiRezultatus(studentai, skaiciavimoTipas);
			break;
		}
		case 4:
		{
			std::cout << "Working directory: "
				<< std::filesystem::current_path()
				<< std::endl;
			std::vector<Studentas> studentai;

			std::string failas;
			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> failas;

			auto start = std::chrono::high_resolution_clock::now();
			skaitytiIsFailo(failas, studentai);

			if (studentai.empty())
			{
				std::cout << "Nerasta studentu duomenu faile arba failas tuscias.\n";
				break;
			}

			int skaiciavimoTipas = pasirinktiSkaiciavimoTipa();
			skaicuotiRezultatus(studentai, skaiciavimoTipas);

			int rusiavimoTipas = pasirinktiRusiavimoTipa();
			rusiuotiStudentus(studentai, rusiavimoTipas);

			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> diff = end - start;
			std::cout << "Laikas: " << diff.count() << " sekundes\n";

			//spausdinu tik maza kieki nes su 1m lines uztrunka 10 min
			if (studentai.size() <= 10000) {
				isvestiRezultatus(studentai, skaiciavimoTipas);
			}
			break;
		}
		case 5:
		{
			std::cout << "Programa baigiama. \n";
			break;
		}
		default:
		{
			std::cout << "Neteisingas pasirinkimas";
			break;
		}
		}

	} while (pasirinkimas != 4);
}






