#ifndef BOOSTATK_H
#define BOOSTATK_H

#include "Potion.h"
#include <string>

using namespace std;

class BoostAtk : public Potion {
    public:
        BoostAtk(int x, int y);
        Tile* getTilePtr();
        virtual ~BoostAtk();
};

#endif
