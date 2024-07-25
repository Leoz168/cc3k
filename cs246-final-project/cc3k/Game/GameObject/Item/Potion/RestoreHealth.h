#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H

#include "Potion.h"
#include <string>

using namespace std;

class RestoreHealth : public Potion {
    public:
        RestoreHealth(int x, int y);
        Tile* getTilePtr();
        virtual ~RestoreHealth();
};

#endif
