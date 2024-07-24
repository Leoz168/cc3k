#include "Drow.h"
using namespace std;

Drow::Drow(int x, int y, EffectHandler* ehr): Player(x, y, DROW, 150, 150, 25, 15, 0, ehr) {}

bool Drow::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

bool Drow::attackedBy(Enemy *e) {
    ceil((100 / (100 + getDef())) * e->getAtk());
}

bool triggerAbility(int id, int ab_ver);
