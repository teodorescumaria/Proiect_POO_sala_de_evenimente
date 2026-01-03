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
};
#endif
  
