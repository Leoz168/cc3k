#include "Dwarf.h"
#include "tileIDs.h"

using namespace std;

Dwarf::Dwarf(int x, int y) : 
    Enemy(100, 20, 30, this, x, y, DWARF) {}

Tile* Dwarf::getTilePtr() { return this; }

std::pair<bool, bool> Dwarf::atkedByPlayer(Player* player) {
    takeDamage( ceil((100 / (100 + getDef())) * player->getAtk()) );
    player->triggerAbility(VAMPIRE, 1);
    if ( getHP() <= 0 ) return make_pair(true, true);
    return make_pair(false, true);
}

Dwarf::~Dwarf() {}
