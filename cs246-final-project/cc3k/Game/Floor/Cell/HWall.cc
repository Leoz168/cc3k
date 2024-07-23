#include "HWall.h"
#include "../../tileIDs.h"

HWall::HWall(int x, int y) : Cell{x, y, HWALL} {}
Tile* HWall::getTilePtr() { return this; }
HWall::~HWall() {}
