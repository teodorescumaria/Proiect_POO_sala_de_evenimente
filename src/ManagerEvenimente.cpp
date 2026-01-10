#include "ManagerEvenimente.h"
#include "BiletReducere.h"
#include "BiletStandard.h"
#include "BiletVip.h"
#include <iostream>

ManagerEvenimente::ManagerEvenimente() = default;

ManagerEvenimente& ManagerEvenimente::getInstance() {
    static ManagerEvenimente instance;
    return instance;
}

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
void ManagerEvenimente::afiseazaEvenimente(std::ostream& out) const {
    if (evenimente.empty()) {
        out<<"Nu exista evenimente inregistrate. \n";
        return;
    }
    out<<"Lista de evenimente: \n";
    for (std::size_t i = 0; i < evenimente.size(); ++i) {
        out<<i+1<<". "<<evenimente[i]->descriere()<<"\n";
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

Bilet *ManagerEvenimente::vindeBiletStandard(const Persoana &persoana, Eveniment &ev, int rand, int coloana, std::ostream& out) {

    out<<"Debug incepem vindeBiletStandard";
    out.flush();
    Sala& sala = ev.getSala();

    out << "DEBUG: Obtinem loc\n";
    out.flush();
    Loc& loc = sala.getLoc(rand, coloana);

    out << "DEBUG: Verificam daca e ocupat\n";
    out.flush();
    if (loc.esteOcupat()) {
        out<<"Locul ("<<rand<<", "<<coloana<<") este deja ocupat. \n";
        return nullptr;
    }

    out << "DEBUG: Verificam daca e VIP\n";
    out.flush();
    if (sala.esteLocVIP(rand, coloana)) {
        out<<"Locul ("<<rand<<", "<<coloana<<") este VIP\n";
        out<<"Pentru acest loc trebuie sa achizitionati loc VIP.\n";
        return nullptr;
    }

    out << "DEBUG: Ocupam locul\n";
    out.flush();
    loc.ocupa();

    out << "DEBUG: Cream biletul\n";
    out.flush();
    Bilet* b = new BiletStandard(persoana, loc, ev.getPretBaza(), ev.getTip());

    out << "DEBUG: Adaugam in vector\n";
    out.flush();
    bileteVandute.push_back(b);

    out << "DEBUG: Returnam biletul\n";
    out.flush();
    return b;
}

Bilet *ManagerEvenimente::vindeBiletReducere(const Persoana &persoana, Eveniment &ev, int rand, int coloana, std::ostream& out) {
    Sala& sala = ev.getSala();
    Loc& loc = sala.getLoc(rand, coloana);
    if (loc.esteOcupat()) {
        out<<"Locul ("<<rand<<", "<<coloana<<") este deja ocupat. \n";
        return nullptr;
    }

    if (!persoana.esteCopil() && !persoana.esteSenior()) {
        out<<"Persoana "<<persoana.getNume()<<" nu este eligibila pentru bilet redus. \n";
        return nullptr;
    }

    loc.ocupa();
    Bilet* b = new BiletReducere(persoana, loc, ev.getPretBaza(), ev.getTip());
    bileteVandute.push_back(b);
    return b;
}
Bilet* ManagerEvenimente::vindeBiletVip(const Persoana& persoana, Eveniment& ev, int rand, int coloana, bool arePopcorn, bool areBautura, std::ostream& out) {
    Sala& sala = ev.getSala();
    Loc& loc = sala.getLoc(rand, coloana);
    if (loc.esteOcupat()) {
        out<<"Locul ("<<rand<<", "<<coloana<<") este deja ocupat. \n";
        return nullptr;
    }
    if (!sala.esteLocVIP(rand, coloana)) {
        out<<"Locul ("<<rand<<", "<<coloana<<") nu este VIP. \n";
        return nullptr;
    }
    loc.ocupa();
    Bilet* b = new BiletVip(persoana, loc, ev.getPretBaza(), ev.getTip(), arePopcorn, areBautura);
    bileteVandute.push_back(b);
    return b;
}

void ManagerEvenimente::afiseazaBilete(std::ostream& out) const {
    if (bileteVandute.empty()) {
        out<<"Nu exista bilete vandute. \n";
        return;
    }
    out<<"Lista bilete vandute: \n";
    for (std::size_t i = 0; i < bileteVandute.size(); ++i) {
        const Bilet* b = bileteVandute[i];
        out<<i+1<<". "<<b->descriere()<<" | cumparator: "<<b->getPersoana().getNume()<<" | tip eveniment: "<<b->getTipEveniment()<<" | pret baza: "<<b->getPretDeBaza()<<" | pret final: "<<b->calculeazaPret()<<"\n";
    }
}

double ManagerEvenimente::calculeazaIncasariTotale() const {
    double total = 0.0;
    for (const Bilet* b : bileteVandute) {
        total+= b->calculeazaPret();
    }
    return total;
}

/*
Sala& sala = ev.getSala();
Loc& loc = sala.getLoc(rand, coloana);
if (loc.esteOcupat()) {
out<<"Locul ("<<rand<<", "<<coloana<<") este deja ocupat. \n";
return nullptr;
}
if (sala.esteLocVIP(rand, coloana)) {
out<<"Locul ("<<rand<<", "<<coloana<<") este VIP\n";
out<<"Pentru acest loc trebuie sa achizitionati loc VIP.\n";
return nullptr;
}
loc.ocupa();
Bilet* b = new BiletStandard(persoana, loc, ev.getPretBaza(), ev.getTip());
bileteVandute.push_back(b);
return b;*/