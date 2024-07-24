#include "Goblin.h"
using namespace std;

Goblin::Goblin(int x, int y, EffectHandler* ehr): Player(x, y, GOBLIN, 110, 110, 15, 20, 0, ehr) {}

bool Goblin::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

bool Goblin::attackedBy(Enemy *e) {
    ceil((100 / (100 + getDef())) * e->getAtk());
}

bool triggerAbility(int id, int ab_ver);
