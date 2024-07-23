#ifndef BLANKTILE_H
#define BLANKTILE_H

#include <utility>
#include "../Tile.h"

class BlankTile: public Tile {
        int id;
    public:
        BlankTile(int x, int y);
        int getTileID();
        Tile* getTilePtr();
        bool move(int dx, int dy);
        std::pair<bool, bool> playerAttack();
        bool playerUsed();
        bool takeAction();
        ~BlankTile();
};

#endif
