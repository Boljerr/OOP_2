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

## v1.2

Šioje versijoje buvo praplėsta `Studentas` klasė. Pagrindinis šios versijos tikslas buvo realizuoti penkių metodų taisyklę, įvesties ir išvesties operatorius bei patikrinti šiuos metodus rankiniais testais.

### Atlikti pakeitimai

| Pakeitimas | Aprašymas |
|---|---|
| Rule of five | Realizuotas destruktorius, kopijavimo konstruktorius, kopijavimo priskyrimo operatorius, perkėlimo konstruktorius ir perkėlimo priskyrimo operatorius |
| Įvesties operatorius `>>` | Leidžia nuskaityti studento duomenis iš įvesties srauto |
| Išvesties operatorius `<<` | Leidžia išvesti studento duomenis į ekraną arba į failą |
| `read()` metodas | Naudojamas studento duomenų nuskaitymui |
| `print()` metodas | Naudojamas studento duomenų išvedimui |
| Rankiniai testai | Pridėta testavimo funkcija, kuri patikrina pagrindinius `Studentas` klasės metodus |

---

### Rule of five

`Studentas` klasėje buvo realizuoti visi penki specialūs metodai:

| Metodas | Paskirtis |
|---|---|
| `~Studentas()` | Destruktorius, kuris iškviečiamas sunaikinant objektą |
| `Studentas(const Studentas& kitas)` | Kopijavimo konstruktorius, kuris sukuria naują objektą kopijuojant kitą objektą |
| `operator=(const Studentas& kitas)` | Kopijavimo operatorius, kuris priskiria vieno objekto reikšmes kitam jau egzistuojančiam objektui |
| `Studentas(Studentas&& kitas) noexcept` | Perkėlimo konstruktorius, kuris perkelia duomenis iš kito objekto |
| `operator=(Studentas&& kitas) noexcept` | Perkėlimo operatorius, kuris perkelia duomenis į jau egzistuojantį objektą |

Nors `Studentas` klasėje naudojami `std::string` ir `std::vector`, kurie patys tvarko atmintį, šie metodai buvo realizuoti rankiniu būdu, nes to reikalauja v1.2 užduotis.

---

### Įvesties operatorius

Buvo realizuotas įvesties operatorius:

```cpp
std::istream& operator>>(std::istream& in, Studentas& studentas)
```

Operatorius iškviečia `read()` metodą:

```cpp
std::istream& operator>>(std::istream& in, Studentas& studentas)
{
	studentas.read(in);
	return in;
}
```

Tokiu būdu studento objektą galima nuskaityti iš įvesties srauto.

Pavyzdinė įvesties eilutė:

```txt
Petras Petraitis 6 7 8 9
```

Šiuo atveju:

| Duomuo | Reikšmė |
|---|---|
| `Petras` | Vardas |
| `Petraitis` | Pavardė |
| `6 7 8` | Namų darbų pažymiai |
| `9` | Egzamino pažymys |

Paskutinis skaičius laikomas egzamino pažymiu, o visi prieš jį esantys skaičiai laikomi namų darbų pažymiais.

---

### Išvesties operatorius

Buvo realizuotas išvesties operatorius:

```cpp
std::ostream& operator<<(std::ostream& out, const Studentas& studentas)
```

Operatorius iškviečia `print()` metodą:

```cpp
std::ostream& operator<<(std::ostream& out, const Studentas& studentas)
{
	studentas.print(out);
	return out;
}
```

Studento duomenis galima išvesti į ekraną:

```cpp
std::cout << studentas;
```

Taip pat tą patį operatorių galima naudoti rašant duomenis į failą.

---

### Duomenų įvestis ir išvestis

| Veiksmas | Kaip realizuota |
|---|---|
| Rankinė įvestis | Studentų duomenys gali būti įvedami per konsolę |
| Automatinė įvestis | Studentų duomenys gali būti generuojami automatiškai |
| Įvestis iš failo | Studentų duomenys gali būti nuskaitomi iš failo |
| Išvestis į ekraną | Studentų duomenys gali būti išvedami į konsolę |
| Išvestis į failą | Studentų duomenys gali būti rašomi į failą |

---

### Testavimas

Buvo sukurta rankinė testavimo funkcija:

```cpp
void testuotiStudentoKlase();
```

Ji patikrina pagrindinius `Studentas` klasės metodus.

| Testas | Rezultatas |
|---|---|
| Default konstruktorius | Pavyko |
| Konstruktorius su duomenimis | Pavyko |
| Kopijavimo konstruktorius | Pavyko |
| Kopijavimo operatorius | Pavyko |
| Perkėlimo konstruktorius | Pavyko |
| Perkėlimo operatorius | Pavyko |
| Įvesties operatorius `>>` | Pavyko |
| Išvesties operatorius `<<` | Pavyko |
| Destruktorius | Pavyko |

Destruktorius buvo tikrinamas per lokalų bloką. Sukūrus objektą bloke, jam išėjus iš bloko objektas sunaikinamas automatiškai. Papildomai naudojamas skaitliukas, kuris leidžia patikrinti, ar destruktorius tikrai buvo iškviestas.

---

### Testavimo rezultatai

Žemiau pateiktas rankinio testavimo rezultatas:

![v1.2 testavimo rezultatai](images/v12_testai.png)

---

### v1.2 išvada

Šioje versijoje `Studentas` klasė tapo pilnesnė ir patogesnė naudoti. Dabar studento objektus galima kopijuoti, perkelti, nuskaityti naudojant `>>` operatorių ir išvesti naudojant `<<` operatorių.

Taip pat buvo pridėti rankiniai testai, kurie parodo, kad pagrindiniai klasės metodai veikia tinkamai.

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