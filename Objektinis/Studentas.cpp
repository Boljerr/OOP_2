#include "Studentas.h"


Studentas::Studentas()
{
	vardas_ = "";
	pavarde_ = "";
	egzaminas_ = 0;
	rezultatas_ = 0.0;
}



Studentas::Studentas(std::string& vardas, std::string& pavarde)
{
	vardas_ = vardas;
	pavarde_ = pavarde;
	egzaminas_ = 0;
	rezultatas_ = 0.0;
}

Studentas::~Studentas()
{
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

void Studentas::setVardas(std::string& vardas)
{
	vardas_ = vardas;
}

void Studentas::setPavarde(std::string& pavarde)
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






