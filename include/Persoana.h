#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>

class Persoana 
{
    std::string nume;
    int anulNasterii;
    static int anCurent;
  public:
    static void setAnCurent(int an);
    explicit Persoana(const std::string& nume = "", int anulNasterii = 2000);

    Persoana(const Persoana& persoana) = default;
    Persoana& operator=(const Persoana& persoana) = default;

    const std::string& getNume() const;
    int getVarsta() const;
    bool esteCopil() const;
    bool esteSenior() const;
};


#endif
