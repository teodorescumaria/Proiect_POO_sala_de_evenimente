#ifndef EVENIMENT_TEATRU_H
#define EVENIMENT_TEATRU_H

#include "Eveniment.h"

class EvenimentTeatru : public Eveniment {
  private:
    std::string regizor;
    std::string trupa;
  public:
    EvenimentTeatru();
    EvenimentTeatru(const std::string& nume, const std::string& data, double pretBaza, const Sala& sala, const std::string& regizor, const std::string& trupa);
    EvenimentTeatru(const EvenimentTeatru& other);

  ~EvenimentTeatru() override = default;

  const std::string& getRegizor() const;
  const std::string& getTrupa() const;

  double calculeazaVenitMaximTeoretic() const override;
  std::string descriere() const override;
};
#endif
