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

Testavimui naudotas `std::vector` konteineris ir greičiausia ankstesniame darbe nustatyta studentų dalijimo strategija.

| Versija | Konteineris | Strategija | Failo dydis | Laikas |
|---|---|---|---:|---:|
| v1.0 struct | vector | Strategija 3 | 100000 | ... s |
| v1.1 class | vector | Strategija 3 | 100000 | ... s |
| v1.0 struct | vector | Strategija 3 | 1000000 | ... s |
| v1.1 class | vector | Strategija 3 | 1000000 | ... s |

## Kompiliatoriaus optimizavimo flag analizė

Testavimui naudotas `std::vector` konteineris, greičiausia studentų dalijimo strategija ir 1000000 įrašų failas.

| Optimizavimo flag'as | Laikas | Exe failo dydis |
|---|---:|---:|
| O1 | ... s | ... KB |
| O2 | ... s | ... KB |
| O3 | ... s | ... KB |

Pagal rezultatus matyti, kad kompiliatoriaus optimizavimo lygis turi įtakos programos veikimo laikui. Didesnis optimizavimo lygis dažniausiai leidžia programai veikti greičiau, tačiau exe failo dydis gali skirtis.