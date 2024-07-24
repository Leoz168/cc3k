#include "DragonHoard.h"
#include "tileIDs.h"
#include <string>

using namespace std;

DragonHoard::DragonHoard(int x, int y, bool is_dragon_alive) :
    is_dragon_alive{is_dragon_alive},
    Gold{6, "a hoard of gold belonging to a dragon", x, y, DRAGONHOARD} {}

Tile* DragonHoard::getTilePtr() { return this; }

string DragonHoard::getDescription() {
    return description + 
        (is_dragon_alive ? " which is still protecting it" : " which has been slain");
}

bool DragonHoard::canPlayerPickup(Player* player) {
    return !is_dragon_alive;
}

void DragonHoard::setDragonStatus(bool dragon_status) {
    is_dragon_alive = dragon_status;
}

DragonHoard::~DragonHoard() {}
