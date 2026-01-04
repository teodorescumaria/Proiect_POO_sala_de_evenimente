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

     ManagerEvenimente manager;
    manager.adaugaEveniment(evTeatru);
    manager.adaugaEveniment(evConcert);
    manager.adaugaEveniment(evFilm);

    int optiune = -1;

    while (true) {
        std::cout<<"\n === MENIU === \n";
        std::cout<<"1. Afiseaza evenimente\n";
        std::cout<<"2. Afiseaza bilete vandute\n";
        std::cout<<"3. Vinde bilet\n";
        std::cout<<"4. Afiseaza incasari totale\n";
        std::cout<<"0. Iesire\n";
        std::cout<<"Alegeti optiunea: ";
        std::cin>>optiune;

        if (!std::cin) {
            std::cout<<"Eroare la citire \n";
            break;
        }
        if (optiune == 0) {
            std::cout<<"LA REVEDER! \n";
            break;
        } else if (optiune == 1) {
            manager.afiseazaEvenimente();
        } else if (optiune == 2) {
            manager.afiseazaBilete();
        } else if (optiune == 3) {
            std::cout<<"\n --- Vanzare bilet ---\n";
            std::cout<<"Introdu numele evenimentului (Aici_nu moare_nimeni_niciodata / ConcertVama / AvatarFocSiCenusa): ";
            std::string numeEveniment;
            std::cin>>numeEveniment;

            Eveniment* eveniment = manager.gasesteEvenimentDupaNume(numeEveniment);
            if (!eveniment) {
                std::cout<<"Evenimentul nu a fost gasit. \n";
                continue;
            }

            std::cout<<"Nume persoana: ";
            std::string numePersoana;
            std::cin>>numePersoana;

            std::cout<<"Anul nasterii persoanei: ";
            int anulNasterii;
            std::cin>>anulNasterii;

            Persoana p(numePersoana, anulNasterii);

            std::cout<<"Tip bilet (1 = Standard, 2 = Redus, 3 = VIP): ";
            int tipBilet;
            std::cin>>tipBilet;

            std::cout<<"Rand: ";
            int rand;
            std::cin>>rand;
            std::cout<<"Coloana: ";
            int coloana;
            std::cin>>coloana;

            const Bilet* b = nullptr;

            if (tipBilet == 1) {
                b = manager.vindeBiletStandard(p, *eveniment, rand, coloana);
            } else if (tipBilet == 2) {
                b = manager.vindeBiletReducere(p, *eveniment, rand, coloana);
            } else if (tipBilet == 3) {
                int pop, baut;
                std::cout<<"Popcorn inclus? (1 = da, 0 = nu): ";
                std::cin>>pop;
                std::cout<<"Bautura inclusa? (1 = da, 0 = nu): ";
                std::cin>>baut;
                b = manager.vindeBiletVip(p, *eveniment, rand, coloana, pop, baut);
            } else {
                std::cout<<"Tip bilet invalid\n";
            }
            if (b!=nullptr) {
                std::cout<<"Bilet vandut: "<<b->descriere()<<" | pret final: "<<b->calculeazaPret()<<"\n";
            }
        } else if (optiune == 4) {
            std::cout<<"Incasari totale: "<<manager.calculeazaIncasariTotale()<<"lei \n";
        } else {
            std::cout<<"Optiune invalid\n";
        }
    }

    return 0;
}
