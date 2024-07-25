#include "PoisonHealth.h"
#include "tileIDs.h"

using namespace std;

PoisonHealth::PoisonHealth(int x, int y) :
    Potion{"a boost atk potion", x, y, POISONHEALTH} {}

Tile* PoisonHealth::getTilePtr() {
    return this;
}

PoisonHealth::~PoisonHealth() {}
