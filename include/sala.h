#ifndef sala_h
#define sala_h
#include <string>
#include <vector>
#include "loc.h"

class sala
{
  private:
    std::string tip_sala;
    int randuri;
    int locuriPeRand;
    std::vector<loc> locuri;
  public:
    sala(const std::string& tip_sala = "", int randuri = 1, int locuriPeRand = 1);
    const std::string& getTipSala() const;
    int getRanduri() const;
    int getLocuriPeRand() const;

//marcam un rand ca VIP
    void initializareLocuriVIP(int randVIP);
    bool esteLocVIP(int rand, int coloana);
    loc& getLoc(int rand, int coloana);
    void afisareLocuri() const;
};
    

#endif
