#include "Tyrimai.h"
#include "VectorFunkcijos.h"
#include "ListFunkcijos.h"
#include "DequeFunkcijos.h"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>


TyrimoRezultatai atliktiVectorTyrima(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
    TyrimoRezultatai rezultatai;
    std::vector<Studentas> studentai;

    auto startRead = std::chrono::high_resolution_clock::now();
    skaitytiIsFailoVector(failoPavadinimas, studentai);
    auto endRead = std::chrono::high_resolution_clock::now();

    skaiciuotiRezultatusVector(studentai, skaiciavimoTipas);

    std::vector<Studentas> studentaiRusiavimui = studentai;
    auto startSort = std::chrono::high_resolution_clock::now();
    rusiuotiStudentusVector(studentaiRusiavimui, rusiavimoTipas);
    auto endSort = std::chrono::high_resolution_clock::now();

    std::vector<Studentas> studentaiSkirstymui = studentai;
    std::vector<Studentas> nuskriaustieji;
    std::vector<Studentas> kietiakiai;
    auto startSplit = std::chrono::high_resolution_clock::now();
    padalintiStudentus1Vector(studentaiSkirstymui, nuskriaustieji, kietiakiai);
    auto endSplit = std::chrono::high_resolution_clock::now();

    rezultatai.nuskaitymas = std::chrono::duration<double>(endRead - startRead).count();
    rezultatai.rusiavimas = std::chrono::duration<double>(endSort - startSort).count();
    rezultatai.skirstymas = std::chrono::duration<double>(endSplit - startSplit).count();

    return rezultatai;
}

TyrimoRezultatai atliktiListTyrima(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
    TyrimoRezultatai rezultatai;
    std::list<Studentas> studentai;

    auto startRead = std::chrono::high_resolution_clock::now();
    skaitytiIsFailoList(failoPavadinimas, studentai);
    auto endRead = std::chrono::high_resolution_clock::now();

    skaiciuotiRezultatusList(studentai, skaiciavimoTipas);

    std::list<Studentas> studentaiRusiavimui = studentai;
    auto startSort = std::chrono::high_resolution_clock::now();
    rusiuotiStudentusList(studentaiRusiavimui, rusiavimoTipas);
    auto endSort = std::chrono::high_resolution_clock::now();
    
	std::list<Studentas> studentaiSkirstymui = studentai;
    std::list<Studentas> nuskriaustieji;
    std::list<Studentas> kietiakiai;
    auto startSplit = std::chrono::high_resolution_clock::now();
    padalintiStudentus1List(studentaiSkirstymui, nuskriaustieji, kietiakiai);
    auto endSplit = std::chrono::high_resolution_clock::now();

    rezultatai.nuskaitymas = std::chrono::duration<double>(endRead - startRead).count();
    rezultatai.rusiavimas = std::chrono::duration<double>(endSort - startSort).count();
    rezultatai.skirstymas = std::chrono::duration<double>(endSplit - startSplit).count();

    return rezultatai;
}

TyrimoRezultatai atliktiDequeTyrima(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
    TyrimoRezultatai rezultatai;
    std::deque<Studentas> studentai;

    auto startRead = std::chrono::high_resolution_clock::now();
    skaitytiIsFailoDeque(failoPavadinimas, studentai);
    auto endRead = std::chrono::high_resolution_clock::now();

    skaiciuotiRezultatusDeque(studentai, skaiciavimoTipas);

    std::deque<Studentas> studentaiRusiavimui = studentai;
    auto startSort = std::chrono::high_resolution_clock::now();
    rusiuotiStudentusDeque(studentaiRusiavimui, rusiavimoTipas);
    auto endSort = std::chrono::high_resolution_clock::now();

    std::deque<Studentas> studentaiSkirstymui = studentai;
    std::deque<Studentas> nuskriaustieji;
    std::deque<Studentas> kietiakiai;

    auto startSplit = std::chrono::high_resolution_clock::now();
    padalintiStudentus1Deque(studentaiSkirstymui, nuskriaustieji, kietiakiai);
    auto endSplit = std::chrono::high_resolution_clock::now();

    rezultatai.nuskaitymas = std::chrono::duration<double>(endRead - startRead).count();
    rezultatai.rusiavimas = std::chrono::duration<double>(endSort - startSort).count();
    rezultatai.skirstymas = std::chrono::duration<double>(endSplit - startSplit).count();

    return rezultatai;
}

StrategijuRezultatai atliktiStrategijuTyrimaVector(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
	StrategijuRezultatai rezultatai;

    std::vector<Studentas> pradinis;
	skaitytiIsFailoVector(failoPavadinimas, pradinis);
	skaiciuotiRezultatusVector(pradinis, skaiciavimoTipas);
    rusiuotiStudentusVector(pradinis, rusiavimoTipas);

	std::vector<Studentas> s1 = pradinis;
	std::vector<Studentas> s2 = pradinis;
	std::vector<Studentas> s3 = pradinis;

	std::vector<Studentas> nuskriaustieji1;
	std::vector<Studentas> kietiakiai1;
	std::vector<Studentas> nuskriaustieji2;
	std::vector<Studentas> nuskriaustieji3;

	auto start1 = std::chrono::high_resolution_clock::now();
	padalintiStudentus1Vector(s1, nuskriaustieji1, kietiakiai1);
	auto end1 = std::chrono::high_resolution_clock::now();

	auto start2 = std::chrono::high_resolution_clock::now();
	padalintiStudentus2Vector(s2, nuskriaustieji2);
	auto end2 = std::chrono::high_resolution_clock::now();
    
	auto start3 = std::chrono::high_resolution_clock::now();
	padalintiStudentus3Vector(s3, nuskriaustieji3);
	auto end3 = std::chrono::high_resolution_clock::now();\

	rezultatai.strategija1 = std::chrono::duration<double>(end1 - start1).count();
	rezultatai.strategija2 = std::chrono::duration<double>(end2 - start2).count();
	rezultatai.strategija3 = std::chrono::duration<double>(end3 - start3).count();

	return rezultatai;
}

StrategijuRezultatai atliktiStrategijuTyrimaList(const std::string& failoPavadinimas, int skaiciavimoTipas, int rusiavimoTipas)
{
    StrategijuRezultatai rezultatai;

    std::list<Studentas> pradinis;
    skaitytiIsFailoList(failoPavadinimas, pradinis);
    skaiciuotiRezultatusList(pradinis, skaiciavimoTipas);
    rusiuotiStudentusList(pradinis, rusiavimoTipas);

    std::list<Studentas> s1 = pradinis;
    std::list<Studentas> s2 = pradinis;
    std::list<Studentas> s3 = pradinis;

    std::list<Studentas> nuskriaustieji1;
    std::list<Studentas> kietiakiai1;
    std::list<Studentas> nuskriaustieji2;
    std::list<Studentas> nuskriaustieji3;

    auto start1 = std::chrono::high_resolution_clock::now();
    padalintiStudentus1List(s1, nuskriaustieji1, kietiakiai1);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    padalintiStudentus2List(s2, nuskriaustieji2);
    auto end2 = std::chrono::high_resolution_clock::now();
    
    auto start3 = std::chrono::high_resolution_clock::now();
    padalintiStudentus3List(s3, nuskriaustieji3);
    auto end3 = std::chrono::high_resolution_clock::now();

    rezultatai.strategija1 = std::chrono::duration<double>(end1 - start1).count();
    rezultatai.strategija2 = std::chrono::duration<double>(end2 - start2).count();
    rezultatai.strategija3 = std::chrono::duration<double>(end3 - start3).count();

    return rezultatai;
}