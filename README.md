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

