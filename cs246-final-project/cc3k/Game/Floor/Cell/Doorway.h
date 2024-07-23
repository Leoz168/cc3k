#ifndef DOORWAY_H
#define DOORWAY_H

#include "Cell.h"

class Doorway : public Cell {
    public:
        Doorway(int x, int y);
        Tile* getTilePtr();
        ~Doorway();
};

#endif
