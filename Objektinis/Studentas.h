#pragma once
#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <iostream>


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
	Studentas(const std::string& vardas, const std::string& pavarde);
	Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& pazymiai, int egzaminas);


	~Studentas();

	Studentas(const Studentas& kitas);
	Studentas& operator=(const Studentas& kitas);

	Studentas(Studentas&& kitas) noexcept;
	Studentas& operator=(Studentas&& kitas) noexcept;

	std::string getVardas() const;
	std::string getPavarde() const;
	const std::vector<int>& getPazymiai() const;
	int getEgzaminas() const;
	double getRezultatas() const;


	void setVardas(std::string vardas);
	void setPavarde(std::string pavarde);
	void setPazymiai(const std::vector<int>& namuDarbai);
	void setEgzaminas(int egzaminas);
	void setRezultatas(double rezultatas);

	void pridetiPazymi(int pazymys);

	void read(std::istream& in);
	void print(std::ostream& out) const;

	friend std::istream& operator>>(std::istream& in, Studentas& studentas);
	friend std::ostream& operator<<(std::ostream& out, const Studentas& studentas);
	
};

#endif // STUDENTAS_H