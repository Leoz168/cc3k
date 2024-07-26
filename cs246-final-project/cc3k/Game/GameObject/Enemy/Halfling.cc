#include "Halfling.h"
#include "../../tileIDs.h"
#include "../Player/Player.h"

using namespace std;

Halfling::Halfling(int x, int y) : 
    Enemy(100, 15, 20, this, x, y, HALFLING) {}

Tile* Halfling::getTilePtr() { return this; }

std::pair<bool, bool> Halfling::atkedByPlayer(Player* player) {
    if ( rand() % 2 == 0 ) return make_pair(false, false);

    takeDamage( ceil((100.0 / (100.0 + getDef())) * player->getAtk()) );
    if ( getHP() <= 0 ) return make_pair(true, true);
    return make_pair(true, false);
}

Halfling::~Halfling() {}
