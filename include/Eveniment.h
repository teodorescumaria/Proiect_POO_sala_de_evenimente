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

}
#endif
