#ifndef WOUNDATK_H
#define WOUNDATK_H

#include "Potion.h"
#include <string>

using namespace std;

class WoundAtk : public Potion {
    public:
        WoundAtk(int x, int y);
        Tile* getTilePtr();
        virtual ~WoundAtk();
};

#endif
