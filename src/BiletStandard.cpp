#include "BiletStandard.h"
#include <string>

BiletStandard::BiletStandard(const Persoana& persoana, const Loc& loc, double pretDeBaza, const std::string& tipEveniment) : Bilet(persoana, loc, pretDeBaza, tipEveniment) {}

double BiletStandard::calculeazaPret() const {
  return pretDeBaza;
}

std::string BiletStandard::descriere() const {
  return "Bilet STANDARD | " + Bilet::descriere() + " | Pret: " + std::to_string(calculeazaPret());
}
