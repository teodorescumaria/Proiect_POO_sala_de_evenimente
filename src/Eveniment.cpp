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

Eveniment::~Eveniment() {
  --nrEvenimente;
}

double Eveniment::calculeazaVenitMaximTeoretic() const {
  return pretBaza * sala.getRanduri()*sala.getLocuriPeRand();
}

std::string Eveniment::descriere() const {
  return "Eveniment: " + nume+" ("+tip+") la data " + data;
}

int Eveniment::getNrEvenimente(){
  return nrEvenimente;
}

const std::string& Eveniment::getNume() const { return nume; }
const std::string& Eveniment::getTip() const { return tip; }
const std::string& Eveniment::getData() const { return data; }
double Eveniment::getPretBaza() const {return pretBaza;}
int Eveniment::getDurataMinute() const { return durataMinute; }
const Sala& Eveniment::getSala() const { return sala; }
Sala& Eveniment::getSala() { return sala; }

Eveniment& Eveniment::operator=(const Eveniment& ev) {
  if(this != &ev) {
    nume = ev.nume;
    tip = ev.tip;
    data = ev.data;
    pretBaza = ev.pretBaza;
    durataMinute = ev.durataMinute;
    sala = ev.sala;
  }
  return *this;
}

bool Eveniment::operator<(const Eveniment& ev) const {
  if(data != ev.data)
    return data < ev.data;
  return nume < ev.nume;
}

bool operator==(const Eveniment& lhs, const Eveniment& rhs) {
  return lhs.getNume() == rhs.getNume() && lhs.getTip() == rhs.getTip() && lhs.getData() == rhs.getData();
}

std::ostream& operator<<(std::ostream& out, const Eveniment& e) {
  out<< "Eveniment: "<<e.getTip()<<", data: "<<e.getData()<<", durata: "<<e.getDurataMinute()<<" min"<<", pret baza: "<<e.getPretBaza()<<", sala: "<<e.getSala().getTipSala();
  return out;
}

std::istream& operator>>(std::istream& in, Eveniment& e) {
  std::string nume;
  std::string tip;
  std::string data;
  double pret;
  int durata;

  std::string tipSala;
  int randuri;
  int locuriPeRand;

  in>>std::ws;
  std::getline(in, nume);

  in>>tip>>data>>pret>>durata;
  in>>tipSala>>randuri>>locuriPeRand;

  e = Eveniment(nume, tip, data, pret, durata, Sala(tipSala, randuri, locuriPeRand));
  return in;
}


