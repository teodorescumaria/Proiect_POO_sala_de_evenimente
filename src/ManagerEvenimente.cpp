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
