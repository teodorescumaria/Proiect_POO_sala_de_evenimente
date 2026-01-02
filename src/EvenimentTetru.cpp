#include "EvenimentTeatru.h"

EvenimentTeatru::EvenimentTeatru() : Eveniment(), regizor(""), trupa("") {}

EvenimentTeatru::EvenimentTeatru(const std::string& nume, const std::string& data, double pretBaza, const Sala& sala, const std::string& regizor, const std::string& trupa) : Eveniment(nume, "Teatru", data, pretBaza, sala), regizor(regizor), trupa(trupa) {}
double EvenimentTeatru::calculeazaVenitMaximTeoretic() const {
  return Eveniment::calculeazaVenitMaximTeoretic();
}

std::string EvenimentTeatru::descriere() const {
  return "TEATRU | " + Eveniment::descriere() + " | regizor: " + regizor + ", trupa: " + trupa;
}
