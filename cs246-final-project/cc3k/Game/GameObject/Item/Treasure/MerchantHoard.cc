#include "MerchantHoard.h"
#include "tileIDs.h"

MerchantHoard::MerchantHoard(int x, int y) :
    Gold{4, "a hoard of gold once belonging to a merchant", x, y, MERCHANTHOARD} {}

Tile* MerchantHoard::getTilePtr() { return this; }
