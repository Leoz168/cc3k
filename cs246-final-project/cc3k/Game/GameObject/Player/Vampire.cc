#include "Vampire.h"
#include "../Enemy/Enemy.h"
using namespace std;

Vampire::Vampire(int x, int y, EffectHandler* ehr): Player(x, y, VAMPIRE, 50, -1, 25, 25, 0, ehr) {}

bool Vampire::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Vampire::attackedBy(Enemy *e) {
    hp_now -= ceil((100 / (100 + getDef())) * e->getAtk());
}

bool triggerAbility(int id, int ab_ver);

