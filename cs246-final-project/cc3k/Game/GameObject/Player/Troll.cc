#include "Troll.h"
#include "../Enemy/Enemy.h"
using namespace std;

Troll::Troll(int x, int y): Player(x, y, TROLL, 120, 120, 25, 15, 0) {}

bool Troll::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Troll::attackedBy(Enemy *e) {
    hp_now -= static_cast<int>(ceil((100.0 / (100.0 + getDef())) * e->getAtk()));
}

int Troll::getTileID() { return id; };
Tile* Troll::getTilePtr() { return this; };

bool Troll::triggerAbility(int id, int ab_ver) {
    if (id == TROLL) {
        int cur_hp = getHP();
        if ((cur_hp + 5) > getMaxHP()) {
            setHP(getMaxHP());
        } else {
            setHP(cur_hp + 5);
        }
        return true;
    }
    return false;
}
