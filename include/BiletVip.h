#ifndef BILET_VIP_H
#define BILET_VIP_H
#include "Bilet.h"

class BiletVip : public Bilet {
  private:
    bool arePopcorn;
    bool areBautura;
  public:
    BiletVip(const Persoana& persoana, const Loc& loc, double pretDeBaza, const std::string& tipEveniment, bool arePopcorn = true, bool areBautura = true);
    double calculeazaPret() const override;
    std::string descriere() const override;
};

#endif
