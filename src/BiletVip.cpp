#include "BiletVip.h"
#include <string>

BiletVip::BiletVip(const Persoana& persoana, const Loc& loc, double pretDeBaza, const std::string& tipEveniment, bool arePopcorn, bool areBautura) : Bilet(persoana, loc, pretDeBaza, tipEveniment), arePopcorn(arePopcorn), areBautura(areBautura) {}

double BiletVip::calculeazaPret() const {
  double pret = pretDeBaza*1.3;
  return pret;
}

std::string BiletVip::descriere() const {
  std::string extrauri = " (extrauri: ";
  if(arePopcorn) {
    extrauri += "popcorn";
  }
  if(areBautura) {
    if(arePopcorn) 
      extrauri += ", ";
    extrauri += "bautura";
  }
  if(!arePopcorn && !areBautura) {
    extrauri += "fara nimic extra";
  }
  extrauri += ")";
  return "Bilet VIP | " + Bilet::descriere() + extrauri + " | Pret VIP: " + std::to_string(calculeazaPret());
}
