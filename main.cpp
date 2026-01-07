#include <iostream>
#include <string>
//
#include <fstream>
//


#include "Persoana.h"
#include "Sala.h"
#include "EvenimentTeatru.h"
#include "EvenimentConcert.h"
#include "EvenimentFilm.h"
#include "ManagerEvenimente.h"

int main() {

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open()) {
        std::cout<<"Nu s-a putut deschide fisierul\n";
        return 1;
    }
    if (!fout.is_open()) {
        std::cout<<"Nu s-a putut deschide fisierul\n";
        return 1;
    }

    fout<<"=== Sistem de vanzare bilete la evenimente === \n";
    fout<<"\n";

    Sala salaTeatru("Teatru", 5, 10);
    salaTeatru.initializareLocuriVIP(2);
    Sala salaConcert("Concert", 5, 10);
    salaConcert.initializareLocuriVIP(1);
    Sala salaFilm("Film", 5, 10);
    salaFilm.initializareLocuriVIP(3);

    auto* evTeatru = new EvenimentTeatru("Iona", "10-02-2026", 50.0, salaTeatru, "Bogdan Olteanu", "Trupa IELE");
    auto* evConcert = new EvenimentConcert("Vama", "14-01-2026", 80.0, salaConcert, "Vama", "Pop-Rock");
    auto* evFilm = new EvenimentFilm("Avatar", "10-01-2026", 40.0, salaFilm, "James Cameron", "AP-12");

     ManagerEvenimente manager;
    manager.adaugaEveniment(evTeatru);
    manager.adaugaEveniment(evConcert);
    manager.adaugaEveniment(evFilm);

    fout<<"Numar total de evenimente create: "<<Eveniment::getNrEvenimente()<<"\n";
    fout<<"\n";

    fout<<"Detalii evenimente initiale: \n";
    fout<<evTeatru->descriere()<<" | trupa: "<<evTeatru->getTrupa()<<"\n";
    fout<<evConcert->descriere()<<" | artist: "<<evConcert->getArtist()<<" | gen: "<<evConcert->getGenMuzical() << "\n";
    fout<<evFilm->descriere()<<" | regizor " << evFilm->getRegizor() << " | rating: " << evFilm->getRating()<<"\n";


    int optiune = -1;

    while (true) {
        fout<<"\n === MENIU === \n";
        fout<<"1. Afiseaza evenimente\n";
        fout<<"2. Afiseaza bilete vandute\n";
        fout<<"3. Vinde bilet\n";
        fout<<"4. Afiseaza incasari totale\n";
        fout<<"5. Afiseaza locurile pentru un eveniment\n";
        fout<<"0. Iesire\n";
        fout<<"Alegeti optiunea: \n";
        fin>>optiune;

        if (!fin) {
            fout<<"Eroare la citire \n";
            break;
        }
        if (optiune == 0) {
            fout<<"LA REVEDERE! \n";
            break;
        } else if (optiune == 1) {
            manager.afiseazaEvenimente(fout);
        } else if (optiune == 2) {
            manager.afiseazaBilete(fout);
        } else if (optiune == 3) {
            fout<<"\n --- Vanzare bilet ---\n";
            fout<<"Introdu numele evenimentului (Iona / Vama / Avatar): \n";
            std::string numeEveniment;
            fin>>numeEveniment;

            Eveniment* eveniment = manager.gasesteEvenimentDupaNume(numeEveniment);
            if (!eveniment) {
                fout<<"Evenimentul nu a fost gasit. \n";
                continue;
            }

            fout<<"\nHarta locurilor\n";
            eveniment->getSala().afisareLocuri(fout);
            fout<<"\n(- loc liber, V loc Vip, X loc ocupat)\n";
            fout<<"\n";

            fout<<"Nume persoana: \n";
            std::string numePersoana;
            fin>>std::ws; //ca sa sara peste new line
            std::getline(fin, numePersoana);

            fout<<"Anul nasterii persoanei: \n";
            int anulNasterii;
            fin>>anulNasterii;

            Persoana p(numePersoana, anulNasterii);

            fout<<"Tip bilet (1 = Standard, 2 = Redus, 3 = VIP): \n";
            int tipBilet;
            fin>>tipBilet;

            fout<<"Rand: \n";
            int rand;
            fin>>rand;
            fout<<"Coloana: \n";
            int coloana;
            fin>>coloana;

            const Bilet* b = nullptr;

            if (tipBilet == 1) {
                b = manager.vindeBiletStandard(p, *eveniment, rand, coloana, fout);
            } else if (tipBilet == 2) {
                b = manager.vindeBiletReducere(p, *eveniment, rand, coloana, fout);
            } else if (tipBilet == 3) {
                int pop, baut;
                fout<<"Popcorn inclus? (1 = da, 0 = nu): \n";
                fin>>pop;
                fout<<"Bautura inclusa? (1 = da, 0 = nu): \n";
                fin>>baut;
                b = manager.vindeBiletVip(p, *eveniment, rand, coloana, pop, baut, fout);
            } else {
                fout<<"Tip bilet invalid\n";
            }
            if (b!=nullptr) {
                fout<<"Bilet vandut: "<<b->descriere()<<" | pret final: "<<b->calculeazaPret()<<"\n";
            }
        } else if (optiune == 4) {
            fout<<"Incasari totale: "<<manager.calculeazaIncasariTotale()<<"lei \n";
        } else if (optiune == 5) {
            fout<<"Introdu numele evenimentului: \n";
            std::string numeEv;
            fin >> numeEv;
            Eveniment* ev = manager.gasesteEvenimentDupaNume(numeEv);
            if(!ev) {
                fout<<"Evenimentul nu a fost gasit. \n";
            } else {
                ev->getSala().afisareLocuri(fout);
            }
        }
        else {
                fout<<"Optiune invalida\n";
            }

        }

    return 0;
}
