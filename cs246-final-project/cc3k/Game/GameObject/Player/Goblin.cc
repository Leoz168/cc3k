#include "Goblin.h"
#include "../Enemy/Enemy.h"
using namespace std;

Goblin::Goblin(int x, int y): Player(x, y, GOBLIN, 110, 110, 15, 20, 0) {}

bool Goblin::attackEnemy(Enemy *e) {
    return (e->atkedByPlayer(this)).first;
}

void Goblin::attackedBy(Enemy *e) {
    hp_now -= ceil((100 / (100 + getDef())) * e->getAtk());
}

int Goblin::getTileID() { return id; };
Tile* Goblin::getTilePtr() { return this; };

bool triggerAbility(int id, int ab_ver) {}
