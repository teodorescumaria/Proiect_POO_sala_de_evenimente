#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>

class Persoana 
{
  private: 
    std::string nume;
    int anulNasterii;
  public:
    explicit Persoana(const std::string& nume = "", int anulNasterii = 2000);
    Persoana(const Persoana& persoana) = default;
    Persoana& operator=(const Persoana& persoana) = default;
    const std::string& getNume() const;
    int getVarsta() const;
    bool esteCopil() const;
    bool esteSenior() const;
};


#endif
