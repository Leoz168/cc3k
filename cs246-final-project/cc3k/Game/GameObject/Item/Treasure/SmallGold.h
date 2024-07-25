#ifndef SMALLGOLD_H
#define SMALLGOLD_H

#include "Gold.h"

class SmallGold : public Gold {
    public:
        SmallGold(int x, int y);
        Tile* getTilePtr() override;
        ~SmallGold() = default;
};

#endif
