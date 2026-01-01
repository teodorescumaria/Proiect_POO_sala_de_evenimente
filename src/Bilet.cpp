#include "Bilet.h"

Bilet::Bilet(cont Persoana& persoana, const Loc& loc, double pretBaza, const std::string& tipEveniment) : persoana(persoana), loc(loc), pretBaza(pretBaza), tipEveniment(tipEveniment) {}

const Persoana& Bilet::getPersoana() const {
  return persoana;
}

const Loc& Bilet::getLoc() const {
  return loc;
}

double Bilet::getPretDeBaza() const {
  return pretDeBaza;
}
const std::string& Bilet::getTipEveniment() const {
  return tipEveniment;
}
std::string Bilet::descriere() const {
  return "Bilet pentru " + persoana.getNume() + " la " + tipEveniment;
}
