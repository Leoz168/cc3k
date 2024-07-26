#include "Vampire.h"
#include "../Enemy/Enemy.h"
using namespace std;

Vampire::Vampire(int x, int y): Player(x, y, VAMPIRE, 50, -1, 25, 25, 0) {}

bool Vampire::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Vampire::attackedBy(Enemy *e) {
    hp_now -= ceil((100 / (100 + getDef())) * e->getAtk());
}

int Vampire::getTileID() { return id; };
Tile* Vampire::getTilePtr() { return this; };

bool triggerAbility(int id, int ab_ver);

