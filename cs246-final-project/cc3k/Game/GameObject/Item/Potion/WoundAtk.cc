#include "WoundAtk.h"

using namespace std;

WoundAtk::WoundAtk(int x, int y) :
    Potion{"a wound atk potion", x, y, WOUNDATK} {}

Tile* WoundAtk::getTilePtr() {
    return this;
}

WoundAtk::~WoundAtk() {}
