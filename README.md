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

## Kompiliatoriaus optimizavimo flag analizė

Testavimui naudotas `std::vector` konteineris, greičiausia studentų dalijimo strategija ir 1000000 įrašų failas.

| Optimizavimo flag'as | Laikas | Exe failo dydis |
|---|---:|---:|
| O1 | ... s | ... KB |
| O2 | ... s | ... KB |
| O3 | ... s | ... KB |

Pagal rezultatus matyti, kad kompiliatoriaus optimizavimo lygis turi įtakos programos veikimo laikui. Didesnis optimizavimo lygis dažniausiai leidžia programai veikti greičiau, tačiau exe failo dydis gali skirtis.