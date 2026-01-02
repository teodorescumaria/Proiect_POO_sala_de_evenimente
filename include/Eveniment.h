#ifndef EVENIMENT_H
#define EVENIMENT_H

#include <string>
#include <iostream>
#include "Sala.h"

class Eveniment {
private:
  std::string nume;
  std::string tip;
  std::string data;
  double pretBaza;
  int durataMinute;
  Sala sala;
  static int nrEvenimente;
public:
  Eveniment();
  Eveniment(const std::string& nume, const std::string& tip, const std::string& data, double pretBaza, int DurataMinute, const Sala& sala);
  Eveniment(const std::string& nume, const std::string& tip, const std::string& data, double pretBaza, const Sala& sala);
  Eveniment(const Eveniment& ev);
  virtual ~Eveniment();

  const std::string& getNume() const;
  const std::string& getTip() const;
  const std::string& getData() const;
  double getPretBAza() const;
  int getDurataMinute() const;
  const Sala& getsala() const;
  Sala& getSala();

};
#endif
