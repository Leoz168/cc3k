#include "BlankTile.h"
#include "../tileIDs.h"

BlankTile::BlankTile(int x, int y) : Tile{x, y, BLANK} {}
Tile* BlankTile::getTilePtr() { return this; }
BlankTile::~BlankTile() {}
