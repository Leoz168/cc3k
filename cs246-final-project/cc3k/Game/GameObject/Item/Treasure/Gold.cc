#include "Gold.h"

using namespace std;

Gold::Gold(int value, string description, int x, int y, int id) :
    value{value},
    Item{description, x, y, id} {}

Tile* Gold::getTilePtr() { return this; }

int Gold::getValue() { return value; }

bool Gold::canPlayerPickup(Player* player) { return true; }

Gold::~Gold() {}
