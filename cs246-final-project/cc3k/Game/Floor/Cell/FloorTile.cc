#include "FloorTile.h"
#include "../../tileIDs.h"

FloorTile::FloorTile(int x, int y, int room_number) : Cell{x, y, FLOORTILE, room_number} {}
Tile* FloorTile::getTilePtr() { return this; }
FloorTile::~FloorTile() {}
