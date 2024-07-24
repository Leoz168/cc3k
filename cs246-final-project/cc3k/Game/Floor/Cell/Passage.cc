#include "Passage.h"
#include "tileIDs.h"

Passage::Passage(int x, int y) : Cell{x, y, PASSAGE} {}
Tile* Passage::getTilePtr() { return this; }
Passage::~Passage() {}
