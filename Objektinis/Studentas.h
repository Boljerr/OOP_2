#pragma once
#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>


class Studentas
{
private:
	std::string vardas_;
	std::string pavarde_;
	std::vector<int> pazymiai_;
	int egzaminas_;
	double rezultatas_;

public:

	Studentas();
	Studentas(std::string& vardas, std::string& pavarde);
	Studentas(std::string& vardas, std::string& pavarde, std::vector<int>& pazymiai, int egzaminas);
	~Studentas();

	std::string getVardas() const;
	std::string getPavarde() const;
	const std::vector<int>& getPazymiai() const;
	int getEgzaminas() const;
	double getRezultatas() const;


	void setVardas(std::string& vardas);
	void setPavarde(std::string& pavarde);
	void setPazymiai(const std::vector<int>& namuDarbai);
	void setEgzaminas(int egzaminas);
	void setRezultatas(double rezultatas);

	void pridetiPazymi(int pazymys);
	
};

#endif // STUDENTAS_H