#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "Cell.h"

class FloorTile : public Cell {
        int id;
    public:
        FloorTile(int x, int y, int room_number);
        Tile* getTilePtr();
        ~FloorTile();
};

#endif
