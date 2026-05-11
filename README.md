# Studentų pažymių skaičiavimo programa

## Apie programą

Ši programa skirta studentų duomenims apdoroti. Programa gali nuskaityti studentus iš failo, apskaičiuoti galutinį balą, surūšiuoti studentus ir padalinti juos į dvi grupes.

Studentai skirstomi į:

- `nuskriaustieji` – studentai, kurių galutinis balas mažesnis nei 5.0;
- `kietiakiai` – studentai, kurių galutinis balas yra 5.0 arba didesnis.

Mano programoje naudojamas pavadinimas `nuskriaustieji` atitinka užduotyje minimus „vargšiukus“.

---

## Versijos

### v0.1

Pradinė versija. Joje buvo realizuotas rankinis studentų duomenų įvedimas ir galutinio balo skaičiavimas.

### v0.2

Pridėtas duomenų nuskaitymas iš failo ir studentų rūšiavimas.

### v0.3

Patobulinta įvesties validacija ir klaidų tikrinimas.

### v0.4

Pridėtas studentų failų generavimas, skirstymas į dvi grupes ir pradinis veikimo spartos tyrimas su `std::vector`.

### v1.0 initial release

Sukurta `v1.0` šaka. Pridėtas darbas su trimis konteineriais:

- `std::vector`
- `std::list`
- `std::deque`

Taip pat pradėtas konteinerių tyrimas.

### v1.0 final release

Galutinėje v1.0 versijoje realizuotos visos trys skirstymo strategijos, atlikti konteinerių ir strategijų tyrimai, paruoštas `CMakeLists.txt` ir sutvarkytas `README.md`.

---

## Naudoti konteineriai

Tyrime buvo naudojami:

- `std::vector`
- `std::list`
- `std::deque`

Buvo tikrinama, kaip keičiasi programos veikimo laikas naudojant skirtingus konteinerius.

---

## Skirstymo strategijos

### 1 strategija

Studentai padalinami į du naujus konteinerius:

- `nuskriaustieji`
- `kietiakiai`

Ši strategija paprasta, bet naudoja daugiau atminties, nes studentai lieka ir bendrame konteineryje.

### 2 strategija

Sukuriamas tik vienas naujas konteineris `nuskriaustieji`.  
Studentai, kurių balas mažesnis nei 5.0, įdedami į `nuskriaustieji` konteinerį ir ištrinami iš bendro `studentai` konteinerio.

Po šio veiksmo bendrame konteineryje lieka tik `kietiakiai`.

### 3 strategija

Tai optimizuota strategija.

Naudota:

- `std::stable_partition` su `vector` ir `deque`;
- `splice` su `list`.

---

## Kas buvo matuojama

Buvo matuojami šie veiksmai:

- duomenų nuskaitymas iš failo;
- studentų rūšiavimas;
- studentų skirstymas į dvi grupes.

Failų generavimo ir rezultatų išvedimo į failus nematavau, nes šie veiksmai nepriklauso nuo konteinerio tipo.

---

## Tyrimo nustatymai

- Galutinis balas skaičiuotas pagal vidurkį.
- Studentai rūšiuoti didėjimo tvarka pagal vardą.
- Kiekvienas testas kartotas 5 kartus.
- Lentelėse pateikiamas vidutinis laikas sekundėmis.
- Tyrimai atlikti `Release` režimu.

---

## Testavimo sistema

- **CPU:** 13th Gen Intel(R) Core(TM) i7-13650HX, 2.60 GHz
- **RAM:** 24 GB
- **Diskas:** SSD
- **OS:** Windows 11
- **Aplinka:** Visual Studio 2026

---

## Testavimo failai

Naudoti šie iš anksto sugeneruoti failai:

- `studentai1000.txt`
- `studentai10000.txt`
- `studentai100000.txt`
- `studentai1000000.txt`
- `studentai10000000.txt`

---

## Programos paleidimas

### Paleidimas su CMake

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
8 - Atlikti v1.0 konteineriu tyrima
9 - Atlikti v1.0 skirstymo strategiju tyrima
10 - Baigti
```

Tyrimams naudojau:

- 8 punktą konteinerių tyrimui;
- 9 punktą skirstymo strategijų tyrimui.

---

# Konteinerių tyrimo rezultatai

## 1000 įrašų

| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|---|---:|---:|---:|
| vector | 0.0038286 | 0.00013016 | 0.0001332 |
| list | 0.00397098 | 0.00003872 | 0.00010474 |
| deque | 0.00397676 | 0.00013634 | 0.00010326 |

## 10000 įrašų

| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|---|---:|---:|---:|
| vector | 0.0391368 | 0.00199554 | 0.001352 |
| list | 0.0389924 | 0.00055958 | 0.00124168 |
| deque | 0.0389072 | 0.00194444 | 0.00122962 |

## 100000 įrašų

| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|---|---:|---:|---:|
| vector | 0.394905 | 0.0245719 | 0.0161668 |
| list | 0.389708 | 0.0107575 | 0.0138554 |
| deque | 0.391391 | 0.026335 | 0.0143592 |

## 1000000 įrašų

| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|---|---:|---:|---:|
| vector | 4.03927 | 0.307971 | 0.172857 |
| list | 3.97819 | 0.149201 | 0.152098 |
| deque | 3.98121 | 0.328185 | 0.164155 |

## 10000000 įrašų

| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|---|---:|---:|---:|
| vector | 41.1027 | 3.75758 | 2.15916 |
| list | 41.627 | 1.96594 | 1.98948 |
| deque | 43.7243 | 4.09207 | 2.46148 |

---

# Skirstymo strategijų tyrimo rezultatai

## 1000 įrašų

| Konteineris | 1 strategija (s) | 2 strategija (s) | 3 strategija (s) |
|---|---:|---:|---:|
| vector | 0.00008598 | 0.00112666 | 0.00006012 |
| list | 0.0000612 | 0.00003086 | 0.00000544 |
| deque | 0.00007386 | 0.0004226 | 0.00004284 |

## 10000 įrašų

| Konteineris | 1 strategija (s) | 2 strategija (s) | 3 strategija (s) |
|---|---:|---:|---:|
| vector | 0.00188102 | 0.125927 | 0.0026321 |
| list | 0.00094552 | 0.00049268 | 0.00022338 |
| deque | 0.00097416 | 0.0437668 | 0.0028793 |

## 100000 įrašų

| Konteineris | 1 strategija (s) | 2 strategija (s) | 3 strategija (s) |
|---|---:|---:|---:|
| vector | 0.0167798 | 14.0272 | 0.0139586 |
| list | 0.0112819 | 0.00528988 | 0.00173928 |
| deque | 0.0113407 | 4.63977 | 0.0110734 |

## 1000000 įrašų

| Konteineris | 1 strategija (s) | 2 strategija (s) | 3 strategija (s) |
|---|---:|---:|---:|
| vector | 0.161006 | 2446.45 | 0.1751 |
| list | 0.143909 | 0.0643625 | 0.0210856 |
| deque | 0.144442 | 994.201 | 0.132825 |

## 10000000 įrašų

| Konteineris | 1 strategija (s) | 2 strategija (s) | 3 strategija (s) |
|---|---:|---:|---:|
| vector | 2.29328 | neatlikta* | 1.6564 |
| list | 2.44978 | 0.686876 | 0.256114 |
| deque | 2.06104 | neatlikta* | 1.58908 |

\* 2 strategija su `vector` ir `deque` konteineriais nebuvo pilnai testuojama su 10 000 000 įrašų, nes jau su 1 000 000 įrašų ji užtruko labai ilgai. `vector` atveju 2 strategija užtruko 2446.45 s, o `deque` atveju 994.201 s.

---

# Trumpas rezultatų aptarimas

Konteinerių tyrime nuskaitymo laikai tarp `vector`, `list` ir `deque` buvo gana panašūs. Didesni skirtumai pasimatė rūšiavimo ir skirstymo dalyse.

`list` rūšiavimas dažnai buvo greitesnis, nes `list` turi savo `sort()` metodą.

Strategijų tyrime labiausiai išsiskyrė 2 strategija. Su `vector` ir `deque` ji buvo labai lėta, nes trinami elementai iš konteinerio vidurio. Su `list` ši problema mažesnė.

3 strategija daugelyje atvejų buvo geriausia arba viena iš geriausių.

---

# Išvados

1. Skirtingi konteineriai turi skirtingą veikimo spartą.
2. Programos greitis priklauso ne tik nuo konteinerio, bet ir nuo pasirinktos strategijos.
3. 1 strategija yra paprasta, bet naudoja daugiau atminties.
4. 2 strategija su `vector` ir `deque` dideliems failams yra labai lėta.
5. 2 strategija su `list` veikia daug geriau.
6. 3 strategija pasirodė geriausiai daugelyje atvejų.
7. Šis tyrimas parodė, kad konteinerio ir algoritmo pasirinkimas turi didelę įtaką programos veikimui.
