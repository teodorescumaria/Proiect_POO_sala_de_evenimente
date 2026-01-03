#include "EvenimentFilm.h"

EvenimentFilm::EvenimentFilm() : Eveniment(), regizor(""), rating("") {}

double EvenimentFilm::calculeazaVenitMaximTeoretic() const {
    return Eveniment::calculeazaVenitMaximTeoretic() * 0.9;
}
std::string EvenimentFilm::descriere() const {
    return "FILM | " + Eveniment::descriere() + " | regizor: " + regizor + ", rating: " + rating;
}
