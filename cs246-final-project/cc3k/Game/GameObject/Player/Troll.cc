#include "Troll.h"
#include "../Enemy/Enemy.h"
using namespace std;

Troll::Troll(int x, int y): Player(x, y, TROLL, 120, 120, 25, 15, 0) {}

bool Troll::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Troll::attackedBy(Enemy *e) {
    hp_now -= ceil((100 / (100 + getDef())) * e->getAtk());
}

int Troll::getTileID() { return id; };
Tile* Troll::getTilePtr() { return this; };

bool triggerAbility(int id, int ab_ver);
