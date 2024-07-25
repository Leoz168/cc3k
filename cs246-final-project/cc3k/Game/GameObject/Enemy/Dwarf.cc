#include "Dwarf.h"
#include "tileIDs.h"
#include "Player.h"

using namespace std;

Dwarf::Dwarf(int x, int y) : 
    Enemy(100, 20, 30, this, x, y, DWARF) {}

Tile* Dwarf::getTilePtr() { return this; }

void Dwarf::postAtkedByPlayerAction(Player* player) {
    player->triggerAbility(VAMPIRE, 1);
}

Dwarf::~Dwarf() {}
