#ifndef BOOSTDEF_H
#define BOOSTDEF_H

#include "Potion.h"
#include <string>

using namespace std;

class BoostDef : public Potion {
    public:
        BoostDef(int x, int y);
        Tile* getTilePtr();
        virtual ~BoostDef();
};

#endif
