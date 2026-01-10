#ifndef LOC_H
#define LOC_H

class Loc
{
    int rand;
    int coloana;
    bool esteVip;
    bool ocupat;
  public:
    Loc(int rand = 1, int coloana = 1, bool esteVip = false, bool ocupat = false);

    Loc(const Loc& other) = default;
    Loc& operator=(const Loc& other) = default;
    Loc(Loc&& other) noexcept = default;
    Loc& operator=(Loc&& other) noexcept = default;

    ~Loc() = default;

    int getRand() const;
    int getColoana() const;
    bool esteVIP() const;
    bool esteOcupat() const;

    void ocupa();
};
#endif
