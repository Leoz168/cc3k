#ifndef BLANKTILE_H
#define BLANKTILE_H

#include <utility>
#include "Tile.h"

class BlankTile: public Tile {
    public:
        BlankTile(int x, int y);
        Tile* getTilePtr();
        ~BlankTile();
};

#endif
