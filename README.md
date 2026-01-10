# Gestionare de Evenimente si vanzare de bilete - Proiect POO C++

### Descriere

Aplicati in C++ care simuleaza un sistem de gestiune si vanzare a biletelor pentru evenimente (teatru, concerte, filme)

### Functionalitati principale

Gestionare persoane:
- introducere persoana: nume, anul nasterii
- calcul de varsta
- determinare tip client (copil / adult / senior)

Evenimente:
- evenimente de tip: Teatru, Concert, Film
- fiecare tip are atribute specifice si descriere personalizata

Gestionarea salilor:
- harti cu locurile din sali, locurile pot fi: locuri normale, VIP sau ocupate
- verificari ca locurile sa fie valide

Vanzare bilete:
- bilete standard
- bilete cu reducere: copil (sub 12 ani), senior (65+)
- bilete VIP cu optiuni extra (popcorn si/sau bautura incluse)
- afisare bilete vandute si incasari totale
- afisare locuri, validare disponibilitate, calcul pret final

### Concepte POO folosite:

- clase abstracte si metode virtuale
- mostenire si override
- polimorfism prin apeluri la baza
- Singleton pentru managementul evenimentelor
- exceptii personalizate pentru validari
- STL

<<<<<<< HEAD
### Structura proiect 
=======
### Structura proiect
>>>>>>> a8ba8e7 (Am modificat ReadMe ul din Clion)
- include/ – headere(.h)
- src/ – implementări (.cpp)
- CMakeLists.txt – build
- README.md – descriere proiect

<<<<<<< HEAD
### Exemplu de rulare 
=======
### Exemplu de rulare
>>>>>>> a8ba8e7 (Am modificat ReadMe ul din Clion)
Programul afiseaza un meniu interactiv similar cu:

=== MENIU ===
1. Afiseaza evenimente
2. Afiseaza bilete vandute
3. Vinde bilet
4. Afiseaza incasari totale
5. Afiseaza locuri pentru un eveniment
0. Iesire

### Autor:
Proiect realizat de: Teodorescu Maria

Grupa: 211

Template folosit: https://github.com/Ionnier/oop-template

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# sau ./scripts/cmake.sh configure
```

Sau pe Windows cu GCC:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
# sau ./scripts/cmake.sh configure -g Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.
