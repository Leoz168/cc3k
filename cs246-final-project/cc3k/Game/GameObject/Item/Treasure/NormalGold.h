#ifndef NORMALGOLD_H
#define NORMALGOLD_H

#include "Gold.h"

class NormalGold : public Gold {
    public:
        NormalGold(int x, int y);
        Tile* getTilePtr() override;
        ~NormalGold() = default;
};

#endif
