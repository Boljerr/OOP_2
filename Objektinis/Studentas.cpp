#include "Studentas.h"


Studentas::Studentas()
{
	vardas = "";
	pavarde = "";
	egzaminas = 0;
	rezultatas = 0.0;
}



Studentas::Studentas(std::string& vardas, std::string& pavarde)
{
	this->vardas = vardas;
	this->pavarde = pavarde;
	egzaminas = 0;
	rezultatas = 0.0;
}

Studentas::~Studentas()
{
}

std::string Studentas::getVardas() const
{
	return vardas;
}

std::string Studentas::getPavarde() const
{
	return pavarde;
}

const std::vector<int>& Studentas::getPazymiai() const
{
	return pazymiai;
}

int Studentas::getEgzaminas() const
{
	return egzaminas;
}

double Studentas::getRezultatas() const
{
	return rezultatas;
}

void Studentas::setVardas(std::string& vardas)
{
	this->vardas = vardas;
}

void Studentas::setPavarde(std::string& pavarde)
{
	this->pavarde = pavarde;
}

void Studentas::setPazymiai(const std::vector<int>& pazymiai)
{
	this->pazymiai = pazymiai;
}

void Studentas::setEgzaminas(int egzaminas)
{
	this->egzaminas = egzaminas;
}

void Studentas::setRezultatas(double rezultatas)
{
	this->rezultatas = rezultatas;
}

void Studentas::pridetiPazymi(int pazymys)
{
	pazymiai.push_back(pazymys);
}






