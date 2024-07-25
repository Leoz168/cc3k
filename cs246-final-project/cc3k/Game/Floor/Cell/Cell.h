#ifndef CELL_H
#define CELL_H

#include <utility>
#include "Tile.h"
#include "tileGenConsts.h"

class Cell : public Tile {
    public:
        Cell(int x, int y, int id, int room_number = NOASSOCIATEDROOM);
        virtual Tile* getTilePtr() = 0;
        virtual ~Cell() = default;
};

#endif
