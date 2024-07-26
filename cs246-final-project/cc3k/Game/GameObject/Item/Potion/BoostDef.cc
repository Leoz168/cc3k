#include "BoostDef.h"
using namespace std;

BoostDef::BoostDef(int x, int y) :
    Potion{"a boost def potion", x, y, BOOSTDEF} {}

Tile* BoostDef::getTilePtr() {
    return this;
}

BoostDef::~BoostDef() {}
