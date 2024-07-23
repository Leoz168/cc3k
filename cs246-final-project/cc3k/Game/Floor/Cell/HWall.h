#ifndef HWALL_H
#define HWALL_H

#include "Cell.h"

class HWall : public Cell {
        int id;
    public:
        HWall(int x, int y);
        Tile* getTilePtr();
        ~HWall();
};

#endif
