#include "SmallGold.h"

SmallGold::SmallGold(int x, int y) :
    Gold{1, "a small pile of gold", x, y, SMALLGOLD} {}

Tile* SmallGold::getTilePtr() { return this; }
