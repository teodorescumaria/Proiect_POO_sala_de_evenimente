#include "EvenimentConcert.h"

EvenimentConcert::EvenimentConcert() : Eveniment(), artist(""), genMuzical("") {}

EvenimentConcert::EvenimentConcert(const std::string &nume, const std::string &data, double pretBaza, const Sala &sala, const std::string &artist, const std::string &genMuzical) : Eveniment(nume, "Concert", data, pretBaza, sala), artist(artist), genMuzical(genMuzical) {}
