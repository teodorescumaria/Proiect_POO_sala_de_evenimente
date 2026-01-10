#include "Sala.h"
#include "Exceptii.h"
#include <stdexcept>
#include <iostream>

Sala::Sala(const std::string& tip_sala, int randuri, int locuriPeRand) : tip_sala(tip_sala), randuri(randuri), locuriPeRand(locuriPeRand) {
    locuri.reserve(randuri*locuriPeRand);
    for(int r=1; r<=randuri; ++r) {
        for(int c = 1; c<= locuriPeRand; ++c) {
            locuri.emplace_back(r, c, false, false);
        }
    }
}

const std::string& Sala::getTipSala() const {
    return tip_sala;
}
int Sala::getRanduri() const{
    return randuri;
}
int Sala::getLocuriPeRand() const {
    return locuriPeRand;
}
void Sala::initializareLocuriVIP(int randVIP) {
    for(auto &loc : locuri) {
        if(loc.getRand() == randVIP) {
            loc = Loc(loc.getRand(), loc.getColoana(), true, loc.esteOcupat());
        }
    }
}

bool Sala::esteLocVIP(int rand, int coloana) const {
    if(rand < 1 || rand > randuri || coloana < 1 || coloana > locuriPeRand) {
        return false;
    }
    int index = (rand-1)* locuriPeRand +(coloana - 1);
    return locuri[index].esteVIP();
}

Loc& Sala::getLoc(int rand, int coloana) {
    if (rand < 1 || rand > randuri || coloana < 1 || coloana > locuriPeRand) {
        throw EroareLocInvalid("EroareLocInvalid");
    }
    int index = (rand-1) * locuriPeRand + (coloana-1);
    return locuri[index];
}

void Sala::afisareLocuri(std::ostream& out) const {
    out << "SALA (" <<tip_sala<<") are "<<randuri<<" randuri si "<<locuriPeRand<<" locuri pe rand. \n";
    for(int r=1; r<=randuri; ++r) {
        for(int c = 1; c<=locuriPeRand; ++c) {
            int index = (r-1)*locuriPeRand+(c-1);
            const Loc& loc = locuri[index];
            char simbol = '-';
            if(loc.esteVIP()) {
                simbol = 'V';
            }
            if(loc.esteOcupat()) {
                simbol = 'X';
            }
            out<<simbol<<' ';
        }
        out<<"\n";
    }
}
