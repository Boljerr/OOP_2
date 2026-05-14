#pragma once
#ifndef ZMOGUS_H
#define ZMOGUS_H
#include <iostream>
#include <string>

class Zmogus
{
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    Zmogus();

    Zmogus(const std::string& vardas, const std::string& pavarde);
    
	virtual ~Zmogus();

    std::string getVardas() const;
    std::string getPavarde() const;

    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);

    virtual void read(std::istream& in) = 0;
	virtual void print(std::ostream& out) const = 0;
};

#endif // ZMOGUS_H
