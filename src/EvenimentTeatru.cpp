#include "EvenimentTeatru.h"

EvenimentTeatru::EvenimentTeatru() : Eveniment(), regizor(""), trupa("") {}

EvenimentTeatru::EvenimentTeatru(const std::string& nume, const std::string& data, double pretBaza, const Sala& sala, const std::string& regizor, const std::string& trupa) : Eveniment(nume, "Teatru", data, pretBaza, sala), regizor(regizor), trupa(trupa) {}

EvenimentTeatru::EvenimentTeatru(const EvenimentTeatru&other) : Eveniment(other), regizor(other.regizor), trupa(other.trupa) {}

EvenimentTeatru& EvenimentTeatru::operator=(const EvenimentTeatru& other) {
  if(this != &other) {
    Eveniment::operator=(other);
    regizor = other.regizor;
    trupa = other.trupa;
  }
  return *this;
}

const std::string& EvenimentTeatru::getRegizor() const {
  return regizor;
}
const std::string& EvenimentTeatru::getTrupa() const {
  return trupa;
}

double EvenimentTeatru::calculeazaVenitMaximTeoretic() const {
  return Eveniment::calculeazaVenitMaximTeoretic() * 0.8;
}
std::string EvenimentTeatru::descriere() const {
  return "TEATRU | " + Eveniment::descriere() + " | regizor: " + regizor + ", trupa: " + trupa;
}
