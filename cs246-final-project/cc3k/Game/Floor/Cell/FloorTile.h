#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "Cell.h"

class FloorTile : public Cell {
        int id;
    public:
        FloorTile(int x, int y);
        Tile* getTilePtr();
        ~FloorTile();
};

#endif
