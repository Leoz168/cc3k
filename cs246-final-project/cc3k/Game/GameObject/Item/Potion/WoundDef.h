#ifndef WOUNDDEF_H
#define WOUNDDEF_H

#include "Potion.h"
#include <string>

using namespace std;

class WoundDef : public Potion {
    public:
        WoundDef(int x, int y);
        Tile* getTilePtr();
        virtual ~WoundDef();
};

#endif
