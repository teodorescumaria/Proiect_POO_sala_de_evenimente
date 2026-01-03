#include "ManagerEvenimente.h"
#include <iostream>

ManagerEvenimente::ManagerEvenimente() = default;

ManagerEvenimente::~ManagerEvenimente() {
    for (Eveniment* ev : evenimente) {
        delete ev;
    }
    evenimente.clear();

    for (Bilet* b : bileteVandute) {
        delete b;
    }
    bileteVandute.clear();
}

void ManagerEvenimente::adaugaEveniment(Eveniment* ev) {
    if (ev!=nullptr) {
        evenimente.push_back(ev);
    }
}
void ManagerEvenimente::afiseazaEvenimente() const {
    if (evenimente.empty()) {
        std::cout<<"Nu exista evenimente inregistrate. \n";
        return;
    }
    std::cout<<"Lista de evenimente: \n";
    for (std::size_t i = 0; i < evenimente.size(); ++i) {
        std::cout<<i+1<<". "<<evenimente[i]->descriere()<<"\n";
    }
}

Eveniment *ManagerEvenimente::gasesteEvenimentDupaNume(const std::string &nume) const {
    for (Eveniment* ev : evenimente) {
        if (ev->getNume() == nume) {
            return ev;
        }
    }
    return nullptr;
}

Bilet *ManagerEvenimente::vindeBiletStandard(const Persoana &persoana, Eveniment &ev, int rand, int coloana) {
    Sala& sala = ev.getSala();
    Loc& loc = sala.getLoc(rand, coloana);
    if (loc.esteOcupat()) {
        std::cout<<"Locul ("<<rand<<", "<<coloana<<") este deja ocupat. \n";
        return nullptr;
    }
    loc.ocupa();
    Bilet* b = new BiletStandard(persoana, loc, ev.getPretBaza(), ev.getTip());
    bileteVandute.push_back(b);
    return b;
}

Bilet *ManagerEvenimente::vindeBiletReducere(const Persoana &persoana, Eveniment &ev, int rand, int coloana) {
    Sala& sala = ev.getSala();
    Loc& loc = sala.getLoc(rand, coloana);
    if (loc.esteOcupat()) {
        std::cout<<"Locul ("<<rand<<", "<<coloana<<") este deja ocupat. \n";
        return nullptr;
    }

    if (!persoana.esteCopil() && !persoana.esteSenior()) {
        std::cout<<"Persoana "<<persoana.getNume()<<" nu este eligibila pentru bilet redus. \n";
        return nullptr;
    }

    loc.ocupa();
    Bilet* b = new BiletReducere(persoana, loc, ev.getPretBaza(), ev.getTip());
    bileteVandute.push_back(b);
    return b;
}
Bilet* ManagerEvenimente::vindeBiletVip(const Persoana& persoana, Eveniment& ev, int rand, int coloana, bool arePopcorn, bool areBautura) {
    Sala& sala = ev.getSala();
    Loc& loc = sala.getLoc(rand, coloana);
    if (loc.esteOcupat()) {
        std::cout<<"Locul ("<<rand<<", "<<coloana<<") este deja ocupat. \n";
        return nullptr;
    }
    if (!sala.esteLocVIP(rand, coloana)) {
        std::cout<<"Locul ("<<rand<<", "<<coloana<<") nu este VIP. \n";
        return nullptr;
    }
    loc.ocupa();
    Bilet* b = new BiletVip(persoana, loc, ev.getPretBaza(), ev.getTip(), arePopcorn, areBautura);
    bileteVandute.push_back(b);
    return b;
}
