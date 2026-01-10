#ifndef BILET_STANDARD_H
#define BILET_STANDARD_H

#include "Bilet.h"

class BiletStandard : public Bilet
{
  public:
    explicit BiletStandard(const Persoana& persoana, const Loc& loc, double pretDeBaza, const std::string& tipEveniment);
    double calculeazaPret() const override;
    std::string descriere() const override;
};
#endif
