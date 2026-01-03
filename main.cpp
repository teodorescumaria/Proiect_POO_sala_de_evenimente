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

    auto* evTeatru = new EvenimentTeatru("Aici nu moare nimeni niciodata", "10-02-2026", 50.0, salaTeatru, "Bogdan Olteanu", "Trupa IELE");
    auto* evConcert = new EvenimentConcert("Concert Vama", "14-01-2026", 80.0, salaConcert, "Vama", "Pop-Rock");
    auto* evFilm = new EvenimentFilm("Avatar foc si cenusa", "10-01-2026", 40.0, salaFilm, "James Cameron", "AP-12");
    

    return 0;
}
