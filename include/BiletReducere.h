#ifndef BILET_REDUCERE_H
#define BILET_REDUCERE_H

#include "Bilet.h"

class BiletReducere : public Bilet
{
  public:
    explicit BiletReducere(const Persoana& persoana, const Loc& loc, double pretDeBaza, const std::string& tipEveniment);
    double calculeazaPret() const override;
    std::string descriere() const override;
};
#endif
