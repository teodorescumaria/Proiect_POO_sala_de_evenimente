#include <iostream>
#include <string>
#include <limits>

#include <stdexcept>

#include "Persoana.h"
#include "Sala.h"
#include "EvenimentTeatru.h"
#include "EvenimentConcert.h"
#include "EvenimentFilm.h"
#include "ManagerEvenimente.h"

int main() {

    std::cout<<"=== Sistem de vanzare bilete la evenimente === \n";
    std::cout<<"\n";

    Sala salaTeatru("Teatru", 5, 10);
    salaTeatru.initializareLocuriVIP(2);
    Sala salaConcert("Concert", 5, 10);
    salaConcert.initializareLocuriVIP(1);
    Sala salaFilm("Film", 5, 10);
    salaFilm.initializareLocuriVIP(3);

    auto* evTeatru = new EvenimentTeatru("Iona", "10-02-2026", 50.0, salaTeatru, "Bogdan Olteanu", "Trupa IELE");
    auto* evConcert = new EvenimentConcert("Vama", "14-01-2026", 80.0, salaConcert, "Vama", "Pop-Rock");
    auto* evFilm = new EvenimentFilm("Avatar", "10-01-2026", 40.0, salaFilm, "James Cameron", "AP-12");

    auto& manager = ManagerEvenimente::getInstance();
    manager.adaugaEveniment(evTeatru);
    manager.adaugaEveniment(evConcert);
    manager.adaugaEveniment(evFilm);

    std::cout<<"Numar total de evenimente create: "<<Eveniment::getNrEvenimente()<<"\n";
    std::cout<<"\n";

    std::cout<<"Detalii evenimente initiale: \n";
    std::cout<<evTeatru->descriere()<<" | trupa: "<<evTeatru->getTrupa()<<"\n";
    std::cout<<evConcert->descriere()<<" | artist: "<<evConcert->getArtist()<<" | gen: "<<evConcert->getGenMuzical() << "\n";
    std::cout<<evFilm->descriere()<<" | regizor " << evFilm->getRegizor() << " | rating: " << evFilm->getRating()<<"\n";


    int optiune = -1;

    while (true) {
        std::cout<<"\n === MENIU === \n";
        std::cout<<"1. Afiseaza evenimente\n";
        std::cout<<"2. Afiseaza bilete vandute\n";
        std::cout<<"3. Vinde bilet\n";
        std::cout<<"4. Afiseaza incasari totale\n";
        std::cout<<"5. Afiseaza locurile pentru un eveniment\n";
        std::cout<<"0. Iesire\n";
        std::cout<<"Alegeti optiunea: \n";
        std::cin>>optiune;

        if (!std::cin){
            std::cout<<"Eroare la citire\n";
            break;
        }
        if (optiune == 0) {
            std::cout<<"LA REVEDERE! \n";
            break;
        } else if (optiune == 1) {
            manager.afiseazaEvenimente(std::cout);
        } else if (optiune == 2) {
            manager.afiseazaBilete(std::cout);
        } else if (optiune == 3) {
            try {
                std::cout<<"\n --- Vanzare bilet ---\n";
                std::cout<<"Introdu numele evenimentului (Iona / Vama / Avatar): \n";
                std::string numeEveniment;
                if (!(std::cin >> numeEveniment)) {
                    throw std::runtime_error("Eroare la citire");
                }

                Eveniment* eveniment = manager.gasesteEvenimentDupaNume(numeEveniment);
                if (!eveniment) {
                    throw std::runtime_error("Evenimentul nu a fost gasit");
                }
                std::cout<<"\nHarta locurilor\n";
                eveniment->getSala().afisareLocuri(std::cout);
                std::cout<<"\n(- loc liber, V loc Vip, X loc ocupat)\n";
                std::cout<<"\n";

                std::cout<<"Nume persoana: \n";
                std::string numePersoana;
                std::cin>>std::ws; //ca sa sara peste new line
                std::getline(std::cin, numePersoana);

                int anulNasterii = 0;
                int tipBilet = 0;
                int rand = 0;
                int coloana = 0;

                std::cout<<"Anul nasterii persoanei: \n";
                if (!(std::cin>>anulNasterii)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::runtime_error("Anul nasterii invalid\n");
                }

                Persoana p(numePersoana, anulNasterii);

                std::cout<<"Tip bilet (1 = Standard, 2 = Redus, 3 = VIP): \n";
                if (!(std::cin>>tipBilet)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::runtime_error("Tip bilet invalid\n");
                }

                std::cout<<"Rand: \n";
                if (!(std::cin>>rand)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::runtime_error("Rand invalid\n");
                }
                std::cout<<"Coloana: \n";
                if (!(std::cin>>coloana)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::runtime_error("Coloana invalida. \n");
                }

                const Bilet* b = nullptr;

                if (tipBilet == 1) {
                    b = manager.vindeBiletStandard(p, *eveniment, rand, coloana, std::cout);
                } else if (tipBilet == 2) {
                    b = manager.vindeBiletReducere(p, *eveniment, rand, coloana, std::cout);
                } else if (tipBilet == 3) {
                    int pop, baut;
                    std::cout<<"Popcorn inclus? (1 = da, 0 = nu): \n";
                    if (!(std::cin>>pop)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::runtime_error("Valoare invalida\n");
                    }
                    std::cout<<"Bautura inclusa? (1 = da, 0 = nu): \n";
                    if (!(std::cin>>baut)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::runtime_error("Valoare invalida\n");
                    }
                    b = manager.vindeBiletVip(p, *eveniment, rand, coloana, pop, baut, std::cout);
                } else {
                    throw std::runtime_error("Tip bilet invalid\n");
                }
                if (b!=nullptr) {
                    std::cout<<"Bilet vandut: "<<b->descriere()<<" | pret final: "<<b->calculeazaPret()<<"\n";
                }
            }
            catch (const std::exception& e) {
                std::cout<<"Eroare la vanzaare bilet: "<< e.what()<<"\n";
                continue;
            }
        } else if (optiune == 4) {
            std::cout<<"Incasari totale: "<<manager.calculeazaIncasariTotale()<<"lei \n";
        } else if (optiune == 5) {
            std::cout<<"Introdu numele evenimentului: \n";
            std::string numeEv;
            std::cin >> numeEv;
            Eveniment* ev = manager.gasesteEvenimentDupaNume(numeEv);
            if(!ev) {
                std::cout<<"Evenimentul nu a fost gasit. \n";
            } else {
                ev->getSala().afisareLocuri(std::cout);
            }
        }
        else {
                std::cout<<"Optiune invalida\n";
            }

        }

    return 0;
}
