#ifndef LOC_H
#define LOC_H

class Loc
{
  private:
    int rand;
    int coloana;
    bool esteVip;
    bool ocupat;
  public:
    explicit Loc(int rand = 1, int coloana = 1, bool esteVip = false, bool ocupat = false);
    int getRand() const;
    int getColoana() const;
    bool esteVIP() const;
    bool esteOcupat() const;

    void ocupa();
};
#endif
