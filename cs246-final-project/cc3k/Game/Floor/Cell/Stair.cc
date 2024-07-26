#include "Stair.h"
#include "../../tileIDs.h"

Stair::Stair(int x, int y) : Cell{x, y, STAIR} {}
Tile* Stair::getTilePtr() { return this; }
Stair::~Stair() {}
