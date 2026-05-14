# Studentų pažymių skaičiavimo programa

## Apie programą

Ši programa skirta studentų duomenims apdoroti. Programa gali nuskaityti studentus iš failo, apskaičiuoti galutinį balą, surūšiuoti studentus ir padalinti juos į dvi grupes.

Studentai skirstomi į:

- `nuskriaustieji` - studentai, kurių galutinis balas mažesnis nei 5.0;
- `kietiakiai` - studentai, kurių galutinis balas yra 5.0 arba didesnis.

Programoje naudojamas pavadinimas `nuskriaustieji` atitinka užduotyje minimus „vargšiukus“.

---

## Programos funkcijos

Programa leidžia:

- rankiniu būdu įvesti studentų duomenis;
- generuoti pažymius;
- generuoti studentus ir jų pažymius;
- nuskaityti studentų duomenis iš failo;
- generuoti studentų failus;
- skaičiuoti galutinį balą pagal vidurkį arba medianą;
- rūšiuoti studentus pagal vardą, pavardę arba rezultatą;
- skirstyti studentus į dvi grupes;
- atlikti veikimo spartos tyrimus.

---

## Reikalavimai

- C++ kompiliatorius su C++17 palaikymu;
- CMake;
- Git.

---

## Programos įdiegimas ir paleidimas

Projekto atsisiuntimas:

```bash
git clone https://github.com/Boljerr/OOP_2.git
cd OOP_2
```

Kompiliavimas su CMake:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Windows aplinkoje programa paleidžiama, pvz.:

```bash
.\Release\StudentaiV1.exe
```

Programa taip pat gali būti paleidžiama iš tos vietos, kurioje CMake sugeneruoja `.exe` failą.

---

## Meniu

```text
1 - Rankinis ivedimas
2 - Generuoti tik pazymius
3 - Generuoti studentus ir pazymius
4 - Nuskaityti is failo
5 - Generuoti studentu faila
6 - Atlikti failo kurimo tyrima
7 - Atlikti v0.4 duomenu apdorojimo tyrima(vector)
8 - Atlikti v1.1 konteineriu tyrima
9 - Atlikti v1.1 skirstymo strategiju tyrima
10 - Baigti
```

### Meniu punktų paaiškinimas

**1 punktas** - rankinis studento duomenų įvedimas.

**2 punktas** - įvedamas studento vardas ir pavardė, o pažymiai sugeneruojami automatiškai.

**3 punktas** - automatiškai generuojami studentai ir jų pažymiai.

**4 punktas** - studentai nuskaitomi iš failo, apskaičiuojamas galutinis balas, atliekamas rūšiavimas ir rezultatai išvedami į ekraną arba failą.

**5 punktas** - sugeneruojamas studentų failas.

**6 punktas** - atliekamas failo kūrimo tyrimas.

**7 punktas** - atliekamas ankstesnės versijos tyrimas su `std::vector`.

**8 punktas** - atliekamas konteinerių tyrimas.

**9 punktas** - atliekamas skirstymo strategijų tyrimas.

**10 punktas** - programa baigia darbą.

---

## Studentas klasė

Šioje versijoje `Studentas` struktūra buvo pakeista į klasę.

Klasėje studento duomenys laikomi privačiuose laukuose:

- vardas;
- pavardė;
- pažymiai;
- egzamino rezultatas;
- galutinis rezultatas.

Duomenims pasiekti ir pakeisti naudojami getteriai ir setteriai. Taip pat realizuoti konstruktoriai ir destruktorius.

Pagrindinis pakeitimo tikslas buvo geriau pritaikyti programą objektinio programavimo principams ir apsaugoti studento duomenis nuo tiesioginio keitimo kitose programos vietose.

---

## Tyrimo nustatymai

Tyrime buvo lyginama `struct` tipo realizacija su `class` tipo realizacija.

Lyginimui naudotas vienas konteineris:

- `std::vector`

Tyrimui naudota 3 skirstymo strategija, kurioje su `std::vector` naudojamas `std::stable_partition`.

Testuoti failai:

- `studentai100000.txt`
- `studentai1000000.txt`

Testai atlikti su kompiliatoriaus optimizavimo flag'ais:

- `O1`
- `O2`
- `O3`

Buvo matuojama:

- nuskaitymo laikas;
- rūšiavimo laikas;
- skirstymo laikas;
- bendras laikas;
- `.exe` failo dydis.

Papildomi nustatymai:

- galutinis balas skaičiuotas pagal vidurkį;
- studentai rūšiuoti pagal vardą;
- kiekvienas testas kartotas 5 kartus;
- lentelėse pateikiamas vidutinis laikas sekundėmis.

---

## Testavimo sistema

- **CPU:** 13th Gen Intel(R) Core(TM) i7-13650HX, 2.60 GHz
- **RAM:** 24 GB
- **Diskas:** SSD
- **OS:** Windows 11
- **Aplinka:** Visual Studio 2026 / terminalas su `g++`

---

## Testavimo failai

Naudoti failai:

- `studentai100000.txt`
- `studentai1000000.txt`

---

# Tyrimo rezultatai

## 100000 studentų

| Tipas | Flag'as | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) | Bendras laikas (s) | Exe dydis |
|---|---|---:|---:|---:|---:|---:|
| struct | O1 | 0.128871 | 0.0214705 | 0.00965262 | 0.159994 | 477 KB |
| class | O1 | 0.141192 | 0.0727069 | 0.0187958 | 0.232695 | 461 KB |
| struct | O2 | 0.127751 | 0.024143 | 0.0100833 | 0.161977 | 445 KB |
| class | O2 | 0.140951 | 0.0677228 | 0.0176268 | 0.226301 | 439 KB |
| struct | O3 | 0.135141 | 0.0242252 | 0.00967596 | 0.169042 | 501 KB |
| class | O3 | 0.148007 | 0.071053 | 0.0213828 | 0.240443 | 465 KB |

---

## 1000000 studentų

| Tipas | Flag'as | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) | Bendras laikas (s) | Exe dydis |
|---|---|---:|---:|---:|---:|---:|
| struct | O1 | 1.29387 | 0.311969 | 0.108226 | 1.714065 | 477 KB |
| class | O1 | 1.39 | 0.959227 | 0.181107 | 2.530334 | 461 KB |
| struct | O2 | 1.27606 | 0.343802 | 0.104341 | 1.724203 | 445 KB |
| class | O2 | 1.36695 | 0.882767 | 0.183637 | 2.433354 | 439 KB |
| struct | O3 | 1.30262 | 0.327598 | 0.103798 | 1.733016 | 501 KB |
| class | O3 | 1.37412 | 0.842216 | 0.175483 | 2.391819 | 465 KB |

---

## Rezultatų aptarimas

Pagal gautus rezultatus matyti, kad šiame tyrime `class` versija veikė lėčiau negu `struct` versija. Didžiausias skirtumas matomas rūšiavimo dalyje.

Taip galėjo nutikti dėl to, kad `class` versijoje studento duomenys pasiekiami per getterius, o ne tiesiogiai per viešus laukus. Taip pat rūšiavimo metu studentai daug kartų lyginami tarpusavyje, todėl skirtumas labiau pasimato.

Nors `class` versija šiame tyrime buvo lėtesnė, ji yra tvarkingesnė objektinio programavimo požiūriu. Studentų duomenys yra privatūs, todėl jų negalima keisti tiesiogiai iš kitų programos vietų.

Optimizavimo flag'ai turėjo įtakos tiek programos veikimo laikui, tiek `.exe` failo dydžiui. Didesnis optimizavimo lygis ne visada reiškė geriausią rezultatą.

Šiame tyrime `class` versijoje geriausias bendras laikas su 1000000 studentų buvo gautas naudojant `O3` flag'ą, o mažiausias `.exe` failas buvo gautas naudojant `O2` flag'ą.

---

## v1.1 išvados

1. `Studentas` struktūrą pakeitus į klasę, programa tapo tvarkingesnė objektinio programavimo požiūriu.

2. `class` versijoje studento duomenys yra privatūs ir pasiekiami tik per metodus.

3. Po perėjimo prie klasės reikėjo atnaujinti funkcijas, kurios dirba su studento duomenimis.

4. Tyrime `class` versija veikė lėčiau negu `struct` versija.

5. Didžiausias skirtumas matomas rūšiavimo dalyje.

6. Optimizavimo flag'ai `O1`, `O2` ir `O3` turėjo įtakos veikimo laikui ir `.exe` failo dydžiui.

7. Nors `struct` versija buvo greitesnė, `class` versija yra geresnė programos struktūros ir duomenų apsaugos prasme.

---

## Relizų aprašas

### v1.1

- `Studentas` struktūra pakeista į klasę.
- Studentų duomenys perkelti į privačius laukus.
- Pridėti getteriai ir setteriai.
- Realizuoti konstruktoriai ir destruktorius.
- Atnaujintos funkcijos, kurios dirba su `Studentas` objektais.
- Atliktas `struct` ir `class` versijų palyginimas.
- Atlikta analizė su `O1`, `O2` ir `O3` optimizavimo flag'ais.
- README faile pateikti greičio ir `.exe` dydžio rezultatai.

### v1.0

- Pridėtas darbas su trimis konteineriais:
  - `std::vector`;
  - `std::list`;
  - `std::deque`.
- Pridėtos trys studentų skirstymo strategijos.
- Atliktas konteinerių tyrimas.
- Atliktas skirstymo strategijų tyrimas.
- Paruoštas `CMakeLists.txt`.

### v0.4

- Pridėtas studentų failų generavimas.
- Pridėtas studentų skirstymas į dvi grupes.
- Atliktas pradinis veikimo spartos tyrimas su `std::vector`.

### v0.3

- Patobulinta įvesties validacija.
- Pridėtas klaidų tikrinimas.
- Kodas išskaidytas į `.h` ir `.cpp` failus.

### v0.2

- Pridėtas duomenų nuskaitymas iš failo.
- Pridėtas studentų rūšiavimas.

### v0.1

- Realizuotas rankinis studentų duomenų įvedimas.
- Pridėtas galutinio balo skaičiavimas pagal vidurkį arba medianą.

### v.pradinė

- Sukurta pradinė studento duomenų struktūra.
- Realizuotas pradinis vidurkio ir medianos skaičiavimas.