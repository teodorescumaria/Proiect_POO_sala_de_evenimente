#ifndef LOC_H
#define LOC_H

class Loc
{
  private:
    int rand;
    int coloana;
    bool esteVip;
    bool esteOcupat;
  public:
    Loc(int rand = 1, int coloana = 1, bool esteVip = false, bool esteOcupat = false);
    int getRand() const;
    int getColoana() const;
    bool esteVIP() const;
    bool este_Ocupat() const;
};
#endif
