#include "Goblin.h"
#include "../Enemy/Enemy.h"
using namespace std;

Goblin::Goblin(int x, int y): Player(x, y, GOBLIN, 110, 110, 15, 20, 0) {}

bool Goblin::attackEnemy(Enemy *e) {
    auto atk_result = e->atkedByPlayer(this);
    if (atk_result.second) triggerAbility(GOBLIN, 0);
    return atk_result.first;
}

void Goblin::attackedBy(Enemy *e) {
    if (e->getTileID() == ORC) hp_now -= ceil((100 / (100 + getDef())) * e->getAtk()) * 1.5;
    else hp_now -= ceil((100 / (100 + getDef())) * e->getAtk());
}

int Goblin::getTileID() { return id; };
Tile* Goblin::getTilePtr() { return this; };

bool Goblin::triggerAbility(int id, int ab_ver) {
    if (id == GOBLIN) {
        setGoldCount(getGoldCount() + 5);
        return true;
    }
    return false;
}
