#include "NormalGold.h"

NormalGold::NormalGold(int x, int y) :
    Gold{2, "a normal pile of gold", x, y, NORMALGOLD} {}

Tile* NormalGold::getTilePtr() { return this; }
