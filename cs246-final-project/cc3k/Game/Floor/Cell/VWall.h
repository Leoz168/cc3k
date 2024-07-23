#ifndef VWALL_H
#define VWALL_H

#include "Cell.h"

class VWall : public Cell {
        int id;
    public:
        VWall(int x, int y);
        Tile* getTilePtr();
        ~VWall();
};

#endif
