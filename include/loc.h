#ifndef loc_h
#define loc_h

class loc
{
  private:
    int rand;
    int coloana;
    bool esteVip;
    bool esteOcupat;
  public:
    loc(int rand = 1, int coloana = 1, bool esteVip = false, bool esteOcupat = false);
    int getRand() const;
    int getColoana() const;
    bool esteVIP() const;
    bool este_Ocupat() const;
};
#endif
