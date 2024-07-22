#ifndef BLANKFLOOR_H
#define BLANKFLOOR_H

#include "floor.h"

class BlankFloor: public Floor {
        int id;
    public:
        BlankFloor();
        int getTileID(int x, int y);
        Floor* getTilePtr(int x, int y);
        bool move(int x, int y, int dx, int dy);
        std::pair<bool, bool> playerAttack(int x, int y);
        bool playerUsed(int x, int y);
        bool takeAction(int x, int y);
        ~BlankFloor();
};

#endif
