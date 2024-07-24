#ifndef SMALLPILE_H
#define SMALLPILE_H

#include "Gold.h"

class SmallPile : public Gold {
    public:
        SmallPile(int x, int y);
        Tile* getTilePtr() override;
        ~SmallPile() = default;
};

#endif
