#ifndef NORMALPILE_H
#define NORMALPILE_H

#include "Gold.h"

class NormalPile : public Gold {
    public:
        NormalPile(int x, int y);
        Tile* getTilePtr() override;
        ~NormalPile() = default;
};

#endif
