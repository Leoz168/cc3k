#ifndef CELL_H
#define CELL_H

#include <utility>
#include "../../Tile.h"

class Cell : public Tile {
    public:
        Cell(int x, int y);
        virtual int getTileID() = 0;
        virtual Tile* getTilePtr() = 0;
        virtual bool move(int dx, int dy);
        virtual std::pair<bool, bool> playerAttack();
        virtual bool playerUsed();
        virtual bool takeAction();
        virtual ~Cell() = 0;
};

#endif
