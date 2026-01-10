#include "EvenimentConcert.h"

EvenimentConcert::EvenimentConcert() : Eveniment(), artist(""), genMuzical("") {}
EvenimentConcert::EvenimentConcert(const std::string &nume, const std::string &data, double pretBaza, const Sala &sala, const std::string &artist, const std::string &genMuzical) : Eveniment(nume, "Concert", data, pretBaza, sala), artist(artist), genMuzical(genMuzical) {}

const std::string& EvenimentConcert::getArtist() const {
    return artist;
}
const std::string& EvenimentConcert::getGenMuzical() const {
    return genMuzical;
}

double EvenimentConcert::calculeazaVenitMaximTeoretic() const {
    return Eveniment::calculeazaVenitMaximTeoretic()*1.2;
}
std::string EvenimentConcert::descriere() const {
    return "CONCERT | "+ Eveniment::descriere() + " | artist: " + artist + " | gen: " + genMuzical;
}

