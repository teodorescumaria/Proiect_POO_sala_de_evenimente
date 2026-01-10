#ifndef EVENIMENT_CONCERT_H
#define EVENIMENT_CONCERT_H

#include "Eveniment.h"
#include <string>

class EvenimentConcert : public Eveniment {
  std::string artist;
  std::string genMuzical;

public:

  EvenimentConcert();
  EvenimentConcert(const std::string& nume, const std::string& data, double pretBaza, const Sala& sala, const std::string& artist, const std::string& genMuzical);
  EvenimentConcert(const EvenimentConcert& other) = default;
  EvenimentConcert& operator=(const EvenimentConcert& other) = default;

  ~EvenimentConcert() override = default;

  const std::string& getArtist() const;
  const std::string& getGenMuzical() const;

  double calculeazaVenitMaximTeoretic() const override;
  std::string descriere() const override;

};
#endif
  
