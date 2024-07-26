#include "Shade.h"
#include "../Enemy/Enemy.h"
#include <iostream>
using namespace std;

Shade::Shade(int x, int y): Player(x, y, SHADE, 125, 125, 25, 25, 0) {}

bool Shade::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Shade::attackedBy(Enemy *e) {
    hp_now -= static_cast<int>(ceil((100.0 / (100.0 + getDef())) * e->getAtk()));
}



int Shade::getTileID() { return id; };
Tile* Shade::getTilePtr() { return this; };

bool Shade::triggerAbility(int id, int ab_ver) {
    if (id == SHADE) return true;
    return false;
}
