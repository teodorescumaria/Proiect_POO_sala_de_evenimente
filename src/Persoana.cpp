#include "Persoana.h"

Persoana::Persoana(const std::string& nume, int anulNasterii) : nume(nume), anulNasterii(anulNasterii) {}

const std::string& Persoana::getNume() const{
  return nume;
}
int Persoana::anCurent = 2026;
void Persoana::setAnCurent(int an) {
  anCurent = an;
}

int Persoana::getVarsta() const {
  return anCurent - anulNasterii;
}
bool Persoana::esteCopil() const {
  return getVarsta() < 12;
}
bool Persoana::esteSenior() const {
  return getVarsta() >= 65;
}
