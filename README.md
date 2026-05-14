## v1.1

Šioje versijoje `Studentas` struktūra buvo pakeista į klasę.

### Pakeitimai

- Sukurta `Studentas` klasė.
- Studentų duomenys perkelti į privačius klasės laukus.
- Pridėti konstruktoriai ir destruktorius.
- Pridėti getteriai ir setteriai.
- Atnaujintos skaitymo, skaičiavimo, rūšiavimo, išvedimo ir studentų dalijimo funkcijos.
- Programa sėkmingai susikompiliuoja po perėjimo nuo `struct` prie `class`.

## Struct ir class versijų palyginimas

Lyginimui naudotas `std::vector` konteineris ir 3 skirstymo strategija.  
Buvo matuojamas tik studentų skirstymo į dvi grupes laikas.

| Versija | Tipas | Konteineris | Strategija | Failas | Skirstymo laikas |
|---|---|---|---|---:|---:|
| v1.0 | struct | vector | 3 | 100000 | 0.0139586 s |
| v1.1 | class | vector | 3 | 100000 | 0.018759 s |
| v1.0 | struct | vector | 3 | 1000000 | 0.1751 s |
| v1.1 | class | vector | 3 | 1000000 | 0.185562 s |

Pagal gautus rezultatus matyti, kad perėjimas nuo `struct` prie `class` skirstymo laiko reikšmingai nepakeitė. `class` versija buvo šiek tiek lėtesnė, tačiau skirtumas nėra didelis. Pagrindinis `class` versijos privalumas yra ne greitis, o geresnė duomenų apsauga, nes studento duomenys yra privatūs ir pasiekiami per metodus.

## Kompiliatoriaus optimizavimo flag'ų analizė

Testavimui naudota v1.1 `class` versija, `std::vector` konteineris, 3 skirstymo strategija ir `studentai1000000.txt` failas.  
Buvo matuojamas tik studentų skirstymo į dvi grupes laikas.

| Optimizavimo flag'as | Skirstymo laikas | Exe failo dydis |
|---|---:|---:|
| O1 | 0.19621 s | 461 KB |
| O2 | 0.191401 s | 440 KB |
| O3 | 0.197236 s | 465 KB |

Pagal gautus rezultatus matyti, kad optimizavimo flag'ai šiuo atveju skirstymo laikui didelės įtakos neturėjo. Greičiausias rezultatas gautas su `O2` flag'u. Exe failo dydis taip pat šiek tiek skyrėsi: mažiausias failas buvo sugeneruotas naudojant `O2`, o didžiausias naudojant `O3`.