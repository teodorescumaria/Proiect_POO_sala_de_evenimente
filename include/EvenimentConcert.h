#ifndef EVENIMENT_CONCERT_H
#define EVENIMENT_CONCERT_H

#include "Eveniment.h"
#include <string>

class EvenimentConcert : public Eveniment {
private:
  std::string artist;
  std::string genMuzical;
public:
  EvenimentConcert();
  EvenimentConcert(const std::string& nume, const std::string& data, double pretBaza, const Sala& sala, const std::string& artist, const std::string& genMuzical);
  EvenimentConcert& operator=(const EvenimentConcert& other);
  
};
#endif
  
