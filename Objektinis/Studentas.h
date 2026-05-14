#pragma once
#ifndef STUDENTAS_H
#define STUDENTAS_H
#include "Zmogus.h"

#include <string>
#include <vector>
#include <iostream>


class Studentas : public Zmogus
{
private:
	std::vector<int> pazymiai_;
	int egzaminas_;
	double rezultatas_;

	static int sunaikintuObjektuKiekis_;

public:

	Studentas();
	Studentas(const std::string& vardas, const std::string& pavarde);
	Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& pazymiai, int egzaminas);


	~Studentas();

	static int getSunaikintuObjektuKiekis();

	Studentas(const Studentas& kitas);
	Studentas& operator=(const Studentas& kitas);

	Studentas(Studentas&& kitas) noexcept;
	Studentas& operator=(Studentas&& kitas) noexcept;

	std::string getVardas() const;
	std::string getPavarde() const;
	const std::vector<int>& getPazymiai() const;
	int getEgzaminas() const;
	double getRezultatas() const;

	void setPazymiai(const std::vector<int>& namuDarbai);
	void setEgzaminas(int egzaminas);
	void setRezultatas(double rezultatas);

	void pridetiPazymi(int pazymys);

	void read(std::istream& in) override;
	void print(std::ostream& out) const override;

	friend std::istream& operator>>(std::istream& in, Studentas& studentas);
	friend std::ostream& operator<<(std::ostream& out, const Studentas& studentas);
	
};

#endif // STUDENTAS_H