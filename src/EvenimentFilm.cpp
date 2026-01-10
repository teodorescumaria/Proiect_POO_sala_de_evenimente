#include "EvenimentFilm.h"

EvenimentFilm::EvenimentFilm() : Eveniment(), regizor(""), rating("") {}
EvenimentFilm::EvenimentFilm(const std::string& nume, const std::string& data, double pretBaza, const Sala& sala, const std::string& regizor, const std::string& rating) : Eveniment(nume, "Film", data, pretBaza, sala), regizor(regizor), rating(rating) {}

const std::string& EvenimentFilm::getRegizor() const {
    return regizor;
}
const std::string& EvenimentFilm::getRating() const {
    return rating;
}

double EvenimentFilm::calculeazaVenitMaximTeoretic() const {
    return Eveniment::calculeazaVenitMaximTeoretic() * 0.9;
}
std::string EvenimentFilm::descriere() const {
    return "FILM | " + Eveniment::descriere() + " | regizor: " + regizor + ", rating: " + rating;
}


