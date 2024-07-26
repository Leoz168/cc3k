#include "Shade.h"
#include "../Enemy/Enemy.h"
#include <iostream>
using namespace std;

Shade::Shade(int x, int y): Player(x, y, SHADE, 125, 125, 25, 25, 0) {}

bool Shade::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Shade::attackedBy(Enemy *e) {
    int damage_dealt = static_cast<int>(ceil((100.0 / (100.0 + getDef())) * e->getAtk()));
    hp_now -= damage_dealt;
    enemyAttackHistory.emplace_back(make_pair(e->getTileID(), damage_dealt));
}



int Shade::getTileID() { return id; };
Tile* Shade::getTilePtr() { return this; };

bool Shade::triggerAbility(int id, int ab_ver) {
    if (id == SHADE) return true;
    return false;
}
