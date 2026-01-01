#ifndef PERSOANA_h
#define Persoana_h

#include <string>

class Persoana 
{
  private: 
    std::string nume;
    int anulNasterii;
  public:
    Persoana(const std::string& nume = "", int anulNasterii = 2000);
    const std::string& getNume() const;
    int getvarsta() const;
    bool esteCopil() const;
    bool esteSenior() const;
};


#endif
