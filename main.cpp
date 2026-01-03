#include <iostream>
#include <string>

#include "Persoana.h"
#include "Sala.h"
#include "EvenimentTeatru.h"
#include "EvenimentConcert.h"
#include "EvenimentFilm.h"
#include "ManagerEvenimente.h"

int main() {

    std::cout<<"=== Sistem de vanzare bilete la evenimente === \n";

    Sala salaTeatru("Teatru", 5, 10);
    salaTeatru.initializareLocuriVIP(2);
    Sala salaConcert("Concert", 5, 10);
    salaConcert.initializareLocuriVIP(1);
    Sala salaFilm("Film", 5, 10);
    salaFilm.initializareLocuriVIP(3);

    return 0;
}
