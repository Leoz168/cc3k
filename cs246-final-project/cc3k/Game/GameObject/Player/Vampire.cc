#include "Vampire.h"
#include "../Enemy/Enemy.h"
using namespace std;

Vampire::Vampire(int x, int y): Player(x, y, VAMPIRE, 50, -1, 25, 25, 0) {}

bool Vampire::attackEnemy(Enemy *e) {
    auto atk_result = e->atkedByPlayer(this);
    if (atk_result.first) {
        if (e->getTileID() == DWARF) triggerAbility(VAMPIRE, 1);
        else triggerAbility(VAMPIRE, 0);
    }
        
    return atk_result.first;
}

void Vampire::attackedBy(Enemy *e) {
    int damage_dealt = static_cast<int>(ceil((100.0 / (100.0 + getDef())) * e->getAtk()));
    hp_now -= damage_dealt;
    enemyAttackHistory.emplace_back(make_pair(e->getTileID(), damage_dealt));
}

int Vampire::getTileID() { return id; };
Tile* Vampire::getTilePtr() { return this; };

bool Vampire::triggerAbility(int id, int ab_ver) {
    if (id == VAMPIRE && ab_ver == 0) {
        setHP(getHP() + 5);
        return true;
    } else if (id == VAMPIRE && ab_ver == 1) {
        setHP(getHP() - 5);
        if (getHP() < 0) setHP(0);
    }
    return false;
}
