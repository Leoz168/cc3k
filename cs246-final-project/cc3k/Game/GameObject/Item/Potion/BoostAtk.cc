#include "BoostAtk.h"

using namespace std;

BoostAtk::BoostAtk(int x, int y) :
    Potion{"a boost atk potion", x, y, BOOSTATK} {}

Tile* BoostAtk::getTilePtr() {
    return this;
}

BoostAtk::~BoostAtk() {}
