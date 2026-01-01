#ifndef BILET_H
#define BILET_H

#include "Persoana.h"
#include "Loc.h"
#include <string>

class Bilet
{
  protected:
    Persoana persoana;
    Loc loc;
    double pretDeBaza;
    std::string tipEveniment;
  public:
    Bilet(const Persoana& persoana, const Loc& loc, double pretDeBaza, std::string& tipEveniment);
    virtual ~Bilet() = default;

    const Persoana& getPersoana() const;
    const Loc& getLoc() const;
    double getPretDeBaza() const;
    const std::string& getTipEveniment() const;

    virtual double calculeazaPret() const = 0;
    virtual std::string descriere() const;

};
#endif
