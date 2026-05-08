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

