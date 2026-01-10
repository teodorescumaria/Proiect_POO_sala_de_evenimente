#include "BiletReducere.h"
#include <string>

BiletReducere::BiletReducere(const Persoana& persoana, const Loc& loc, double pretDeBaza, const std::string& tipEveniment) : Bilet(persoana, loc, pretDeBaza, tipEveniment) {}

double BiletReducere::calculeazaPret() const {
  double pret = pretDeBaza;
  if(persoana.esteCopil()) {
    pret *= 0.5;
  }
  else if(persoana.esteSenior()) {
    pret*=0.7;
  }
  return pret;
}
std::string BiletReducere::descriere() const {
  return "Bilet REDUS | " +Bilet::descriere() + " | Pret redus " + std::to_string(calculeazaPret());
}
