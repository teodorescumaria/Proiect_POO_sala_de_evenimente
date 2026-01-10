//
// Created by Mackbook Pro 14 on 01.01.2026.
//

#ifndef SALA_H
#define SALA_H
#include <string>
#include <vector>
#include "Loc.h"

class Sala
{
private:
    std::string tip_sala;
    int randuri;
    int locuriPeRand;
    std::vector<Loc> locuri;
public:
    explicit Sala(const std::string& tip_sala = "", int randuri = 1, int locuriPeRand = 1);
    const std::string& getTipSala() const;
    int getRanduri() const;
    int getLocuriPeRand() const;

    //marcam un rand ca VIP
    void initializareLocuriVIP(int randVIP);

    bool esteLocVIP(int rand, int coloana) const;
    Loc& getLoc(int rand, int coloana);
    void afisareLocuri(std::ostream& out) const;
};


#endif
