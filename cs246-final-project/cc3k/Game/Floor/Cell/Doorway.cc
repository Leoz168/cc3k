#include "Doorway.h"
#include "tileIDs.h"

Doorway::Doorway(int x, int y) : Cell{x, y, DOORWAY} {}
Tile* Doorway::getTilePtr() { return this; }
Doorway::~Doorway() {}
