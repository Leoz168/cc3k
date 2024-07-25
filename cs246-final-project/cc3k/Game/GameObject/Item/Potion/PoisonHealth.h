#ifndef POISONHEALTH_H
#define POISONHEALTH_H

#include "Potion.h"
#include <string>

using namespace std;

class PoisonHealth : public Potion {
    public:
        PoisonHealth(int x, int y);
        Tile* getTilePtr();
        virtual ~PoisonHealth();
};

#endif
