#include "FloorTile.h"
#include "../../tileIDs.h"

FloorTile::FloorTile(int x, int y) : Cell{x, y, FLOORTILE} {}
Tile* FloorTile::getTilePtr() { return this; }
FloorTile::~FloorTile() {}
