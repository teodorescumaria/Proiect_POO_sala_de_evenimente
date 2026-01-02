#include "Eveniment.h"

int Eveniment::nrEvenimente=0;

Eveniment::Eveniment() : nume(""), tip(""), data(""), pretBaza(0.0), durataMinute(0), sala() {
  ++nrEvenimente;
}

Eveniment::Eveniment(const std::string& nume, const std::string& tip, const std::string& data, double pretBaza, int durataMinute, const Sala& sala) : nume(nume), tip(tip), data(data), pretBaza(pretBaza), durataMinute(durataMinute), sala(sala) {
  ++nrEvenimente;
}
Eveniment::Eveniment(const std::string& nume, const std::string& tip, const std::string& data, double pretBaza, const Sala& sala) : nume(nume), tip(tip), data(data), pretBaza(pretBaza), durataMinute(90), sala(sala) {
  ++nrEvenimente;
}

Eveniment::Eveniment(const Eveniment& ev) : nume(ev.nume), tip(ev.tip), data(ev.data), pretBaza(ev.pretBaza), durataMinute(ev.durataMinute), sala(ev.sala) {
  ++nrEvenimente;
}

Eveniment::~Eveniment() = default;

double Eveniment::calculeazaVenitMaximTeoretic() const {
  return pretBaza * sala.getRanduri()*sala.getLocuriPeRand();
}

std::string Eveniment::descriere() const {
  return "Eveniment: " + nume+" ("+tip+") la data " + data;
}

int Eveniment::getNrEvenimente(){
  return nrEvenimente;
}
