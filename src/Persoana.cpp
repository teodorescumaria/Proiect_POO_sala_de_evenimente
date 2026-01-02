#include "Persoana.h"

Persoana::Persoana(const std::string& nume, int anulNasterii) : nume(nume), anulNasterii(anulNasterii) {}

const std::string& Persoana::getNume() const{
  return nume;
}

int Persoana::getVarsta() const {
  int anCurent = 2026;
  return anCurent - anulNasterii;
}
bool Persoana::esteCopil() const {
  return getVarsta() < 12;
}
bool Persoana::esteSenior() const {
  return getVarsta() >= 65;
}
