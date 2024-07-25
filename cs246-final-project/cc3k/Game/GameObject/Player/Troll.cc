#include "Troll.h"
#include "Enemy.h"
using namespace std;

Troll::Troll(int x, int y, EffectHandler* ehr): Player(x, y, TROLL, 120, 120, 25, 15, 0, ehr) {}

bool Troll::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Troll::attackedBy(Enemy *e) {
    hp_now -= ceil((100 / (100 + getDef())) * e->getAtk());
}

bool triggerAbility(int id, int ab_ver);
