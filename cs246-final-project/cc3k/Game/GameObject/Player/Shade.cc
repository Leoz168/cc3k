#include "Shade.h"
#include "../Enemy/Enemy.h"
using namespace std;

Shade::Shade(int x, int y): Player(x, y, SHADE, 125, 125, 25, 25, 0) {}

bool Shade::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Shade::attackedBy(Enemy *e) {
    ceil((100 / (100 + getDef())) * e->getAtk());
}

bool triggerAbility(int id, int ab_ver);
