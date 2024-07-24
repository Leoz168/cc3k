#include "SmallPile.h"
#include "tileIDs.h"

SmallPile::SmallPile(int x, int y) :
    Gold{1, "a small pile of gold", x, y, SMALLGOLD} {}

Tile* SmallPile::getTilePtr() { return this; }
