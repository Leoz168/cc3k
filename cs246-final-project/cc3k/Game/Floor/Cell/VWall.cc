#include "VWall.h"
#include "tileIDs.h"

VWall::VWall(int x, int y) : Cell{x, y, VWALL} {}
Tile* VWall::getTilePtr() { return this; }
VWall::~VWall() {}
