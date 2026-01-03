#ifndef MANAGER_EVENIMENTE_H
#define MANAGER_EVENIMENTE_H

#include <vector>
#include <string>
#include "Eveniment.h"
#include "EvenimentFilm.h"
#include "EvenimentConcert.h"
#include "EvenimentTeatru.h"
#include "Bilet.h"
#include "BiletStandard.h"
#include "BiletReducere.h"
#include "BiletVip.h"

class ManagerEvenimente {
private:
    std::vector<Eveniment*> evenimente;
    std::vector<Bilet*> bileteVandute;
public:
    ManagerEvenimente();
    ~ManagerEvenimente();
};

#endif
