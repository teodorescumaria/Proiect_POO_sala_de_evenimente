#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>

class Persoana 
{
  private: 
    std::string nume;
    int anulNasterii;
  public:
    Persoana(const std::string& nume = "", int anulNasterii = 2000);
    const std::string& getNume() const;
    int getVarsta() const;
    bool esteCopil() const;
    bool esteSenior() const;
};


#endif
