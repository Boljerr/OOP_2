#include "Studentas.h"
#include <utility>

Studentas::Studentas()
{
	vardas_ = "";
	pavarde_ = "";
	egzaminas_ = 0;
	rezultatas_ = 0.0;
}



Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
{
	vardas_ = vardas;
	pavarde_ = pavarde;
	pazymiai_.clear();
	egzaminas_ = 0;
	rezultatas_ = 0.0;
}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& pazymiai, int egzaminas)
{
	vardas_ = vardas;
	pavarde_ = pavarde;
	pazymiai_ = pazymiai;
	egzaminas_ = egzaminas;
	rezultatas_ = 0.0;
}

Studentas::~Studentas()
{
	pazymiai_.clear();
}

Studentas::Studentas(const Studentas& kitas)
{
	vardas_ = kitas.vardas_;
	pavarde_ = kitas.pavarde_;
	pazymiai_ = kitas.pazymiai_;
	egzaminas_ = kitas.egzaminas_;
	rezultatas_ = kitas.rezultatas_;
}
Studentas& Studentas::operator=(const Studentas& kitas)
{
	if (this != &kitas)
	{
		vardas_ = kitas.vardas_;
		pavarde_ = kitas.pavarde_;
		pazymiai_ = kitas.pazymiai_;
		egzaminas_ = kitas.egzaminas_;
		rezultatas_ = kitas.rezultatas_;
	}
	return *this;
}

Studentas::Studentas(Studentas&& kitas) noexcept
{
	vardas_ = std::move(kitas.vardas_);
	pavarde_ = std::move(kitas.pavarde_);
	pazymiai_ = std::move(kitas.pazymiai_);
	egzaminas_ = kitas.egzaminas_;
	rezultatas_ = kitas.rezultatas_;

	kitas.egzaminas_ = 0;
	kitas.rezultatas_ = 0.0;
}

Studentas& Studentas::operator=(Studentas&& kitas) noexcept
{
	if (this != &kitas)
	{
		vardas_ = std::move(kitas.vardas_);
		pavarde_ = std::move(kitas.pavarde_);
		pazymiai_ = std::move(kitas.pazymiai_);
		egzaminas_ = kitas.egzaminas_;
		rezultatas_ = kitas.rezultatas_;

		kitas.egzaminas_ = 0;
		kitas.rezultatas_ = 0.0;
	}
	return *this;
}

std::string Studentas::getVardas() const
{
	return vardas_;
}

std::string Studentas::getPavarde() const
{
	return pavarde_;
}

const std::vector<int>& Studentas::getPazymiai() const
{
	return pazymiai_;
}

int Studentas::getEgzaminas() const
{
	return egzaminas_;
}

double Studentas::getRezultatas() const
{
	return rezultatas_;
}

void Studentas::setVardas(std::string vardas)
{
	vardas_ = vardas;
}

void Studentas::setPavarde(std::string pavarde)
{
	pavarde_ = pavarde;
}

void Studentas::setPazymiai(const std::vector<int>& pazymiai)
{
	pazymiai_ = pazymiai;
}

void Studentas::setEgzaminas(int egzaminas)
{
	egzaminas_ = egzaminas;
}

void Studentas::setRezultatas(double rezultatas)
{
	rezultatas_ = rezultatas;
}

void Studentas::pridetiPazymi(int pazymys)
{
	pazymiai_.push_back(pazymys);
}






