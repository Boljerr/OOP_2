## v1.1

Šioje versijoje `Studentas` struktūra buvo pakeista į klasę.

### Pakeitimai

- Sukurta `Studentas` klasė.
- Studentų duomenys perkelti į privačius klasės laukus.
- Pridėti konstruktoriai ir destruktorius.
- Pridėti getteriai ir setteriai.
- Atnaujintos skaitymo, skaičiavimo, rūšiavimo, išvedimo ir studentų dalijimo funkcijos.
- Programa sėkmingai susikompiliuoja po perėjimo nuo `struct` prie `class`.

## Struct ir class versijų palyginimas su optimizavimo flag'ais

Šiame tyrime buvo lyginama ankstesnė `v1.0` versija, kurioje naudota `struct Studentas`, su `v1.1` versija, kurioje realizuota `class Studentas`.

Lyginimui naudotas vienas konteineris: `std::vector`.  
Taip pat naudota 3 skirstymo strategija, kurioje naudojamas `std::stable_partition`.

Buvo testuojami du failai:

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
- sugeneruoto `.exe` failo dydis.

### 100000 studentų

| Tipas | Flag'as | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) | Bendras laikas (s) | Exe dydis |
|---|---|---:|---:|---:|---:|---:|
| struct | O1 | 0.128871 | 0.0214705 | 0.00965262 | 0.159994 | 476.63 KB |
| class | O1 | 0.141192 | 0.0727069 | 0.0187958 | 0.232695 | 461 KB |
| struct | O2 | 0.127751 | 0.024143 | 0.0100833 | 0.161977 | 445.3 KB |
| class | O2 | 0.140951 | 0.0677228 | 0.0176268 | 0.226301 | 439 KB |
| struct | O3 | 0.135141 | 0.0242252 | 0.00967596 | 0.169042 | 500.92 KB |
| class | O3 | 0.148007 | 0.071053 | 0.0213828 | 0.240443 | 465 KB |

### 1000000 studentų

| Tipas | Flag'as | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) | Bendras laikas (s) | Exe dydis |
|---|---|---:|---:|---:|---:|---:|
| struct | O1 | 1.29387 | 0.311969 | 0.108226 | 1.714065 | 476.63 KB |
| class | O1 | 1.39 | 0.959227 | 0.181107 | 2.530334 | 461 KB |
| struct | O2 | 1.27606 | 0.343802 | 0.104341 | 1.724203 | 445.3 KB |
| class | O2 | 1.36695 | 0.882767 | 0.183637 | 2.433354 | 439 KB |
| struct | O3 | 1.30262 | 0.327598 | 0.103798 | 1.733016 | 500.92 KB |
| class | O3 | 1.37412 | 0.842216 | 0.175483 | 2.391819 | 465 KB |

### Pastebėjimai

Pagal gautus rezultatus matyti, kad `class` versija veikia lėčiau negu `struct` versija. Didžiausias skirtumas matomas rūšiavimo dalyje. Taip gali būti dėl to, kad `class` versijoje duomenys pasiekiami per getterius, o ne tiesiogiai per viešus laukus.

Tačiau `class` versija yra tvarkingesnė objektinio programavimo požiūriu. Studentų duomenys yra privatūs, todėl jie negali būti keičiami tiesiogiai iš kitų programos vietų. Tai pagerina duomenų apsaugą ir programos struktūrą.

Optimizavimo flag'ai turėjo įtakos tiek programos veikimo laikui, tiek `.exe` failo dydžiui. Šiame tyrime `class` versijoje geriausias bendras laikas su 1000000 studentų buvo gautas naudojant `O3` flag'ą, o mažiausias `.exe` failas buvo gautas naudojant `O2` flag'ą.