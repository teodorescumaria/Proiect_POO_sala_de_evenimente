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
