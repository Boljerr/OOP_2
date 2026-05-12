#pragma once
#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>


class Studentas
{
public:
	std::string vardas;
	std::string pavarde;
	std::vector<int> namuDarbai;
	int egzaminas;
	double rezultatas;


	Studentas();
	Studentas(std::string& vardas, std::string& pavarde);
	~Studentas();

	std::string getVardas() const;
	std::string getPavarde() const;
	const std::vector<int>& getNamuDarbai() const;
	int getEgzaminas() const;
	double getRezultatas() const;


	void setVardas(std::string& vardas);
	void setPavarde(std::string& pavarde);
	void setNamuDarbai(std::vector<int>& namuDarbai);
	void setEgzaminas(int egzaminas);
	void setRezultatas(double rezultatas);

	void pridetiNamuDarba(int pazymys);
	
};

#endif // STUDENTAS_H