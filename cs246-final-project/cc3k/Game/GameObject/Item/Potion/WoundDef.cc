#include "WoundDef.h"
#include "tileIDs.h"

using namespace std;

WoundDef::WoundDef(int x, int y) :
    Potion{"a wound def potion", x, y, WOUNDDEF} {}

Tile* WoundDef::getTilePtr() {
    return this;
}

WoundDef::~WoundDef() {}
