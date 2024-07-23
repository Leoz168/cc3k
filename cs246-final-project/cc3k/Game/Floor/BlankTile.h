#ifndef BLANKTILE_H
#define BLANKTILE_H

#include "../Tile.h"

class BlankTile: public Tile {
        int id;
    public:
        BlankTile(int x, int y);
        int getTileID(int x, int y);
        Tile* getTilePtr(int x, int y);
        bool move(int x, int y, int dx, int dy);
        std::pair<bool, bool> playerAttack(int x, int y);
        bool playerUsed(int x, int y);
        bool takeAction(int x, int y);
        ~BlankTile();
};

#endif
