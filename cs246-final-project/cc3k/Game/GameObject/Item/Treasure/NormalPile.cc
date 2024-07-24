#include "NormalPile.h"
#include "tileIDs.h"

NormalPile::NormalPile(int x, int y) :
    Gold{2, "a normal pile of gold", x, y, NORMALGOLD} {}

Tile* NormalPile::getTilePtr() { return this; }
