#ifndef STAIR_H
#define STAIR_H

#include "Cell.h"

class Stair : public Cell {
        int id;
    public:
        Stair(int x, int y);
        Tile* getTilePtr();
        ~Stair();
};

#endif
