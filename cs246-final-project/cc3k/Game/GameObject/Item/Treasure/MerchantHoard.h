#ifndef MERCHANTHOARD_H
#define MERCHANTHOARD_H

#include "Gold.h"

class MerchantHoard : public Gold {
    public:
        MerchantHoard(int x, int y);
        Tile* getTilePtr() override;
        ~MerchantHoard() = default;
};

#endif
