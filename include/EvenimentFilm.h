#ifndef EVENIMENT_FILM_H
#define EVENIMENT_FILM_H

#include "Eveniment.h"
#include <string>

class EvenimentFilm : public Eveniment {
private:
    std::string regizor;
    std::string rating;
public:
    EvenimentFilm();
    EvenimentFilm(const std::string& nume, const std::string& data, double pretBaza, const Sala& sala, const std::string& regizor, const std::string& raiting);
    EvenimentFilm(const EvenimentFilm& other);

    ~EvenimentFilm() override = default;
    const std::string& getRegizor() const;
    const std::string& getRating() const;

    double calculeazaVenitMaximTeoretic() const override;
    std::string descriere() const override;
};
#endif
