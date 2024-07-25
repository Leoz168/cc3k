#include "RestoreHealth.h"
#include "tileIDs.h"

using namespace std;

RestoreHealth::RestoreHealth(int x, int y) :
    Potion{"a boost atk potion", x, y, RESTOREHEALTH} {}

Tile* RestoreHealth::getTilePtr() {
    return this;
}

RestoreHealth::~RestoreHealth() {}
