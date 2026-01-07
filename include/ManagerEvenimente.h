#ifndef MANAGEREVENIMENTE_H
#define MANAGEREVENIMENTE_H

#include <vector>
#include <string>
#include "Eveniment.h"
#include "EvenimentFilm.h"
#include "EvenimentConcert.h"
#include "EvenimentTeatru.h"
#include "Bilet.h"
#include "BiletStandard.h"
#include "BiletReducere.h"
#include "BiletVip.h"

class ManagerEvenimente {
private:
    std::vector<Eveniment*> evenimente;
    std::vector<Bilet*> bileteVandute;
public:
    ManagerEvenimente();
    ~ManagerEvenimente();

    void adaugaEveniment(Eveniment* ev);

    void afiseazaEvenimente(std::ostream& out) const;

    Eveniment* gasesteEvenimentDupaNume(const std::string& nume) const;

    Bilet* vindeBiletStandard(const Persoana& persoana, Eveniment& ev, int rand, int coloana, std::ostream& out);
    Bilet* vindeBiletReducere(const Persoana& persoana, Eveniment& ev, int rand, int coloana, std::ostream& out);
    Bilet* vindeBiletVip(const Persoana& persoana, Eveniment& ev, int rand, int coloana, bool arePopcorn, bool areBautura, std::ostream& out);

    void afiseazaBilete(std::ostream& out) const;

    double calculeazaIncasariTotale() const;

};

#endif
