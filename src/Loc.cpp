#include "Loc.h"

Loc::Loc(int rand, int coloana, bool esteVip, bool ocupat) : rand(rand), coloana(coloana), esteVip(esteVip), ocupat(ocupat) {}

int Loc::getRand() const {
  return rand;
}
int Loc::getColoana() const {
  return coloana;
}
bool Loc::esteVIP() const {
  return esteVip;
}
bool Loc::esteOcupat() const {
  return ocupat;
}

void Loc::ocupa() {
  ocupat = true;
}

