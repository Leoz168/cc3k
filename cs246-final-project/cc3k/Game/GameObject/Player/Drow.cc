#include "Drow.h"
#include "../Enemy/Enemy.h"
#include <iostream>
using namespace std;

Drow::Drow(int x, int y): Player(x, y, DROW, 150, 150, 25, 15, 0) {}

bool Drow::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Drow::attackedBy(Enemy *e) {
    int damage_dealt = static_cast<int>(ceil((100.0 / (100.0 + getDef())) * e->getAtk()));
    hp_now -= damage_dealt;
    enemyAttackHistory.emplace_back(make_pair(e->getTileID(), damage_dealt));
}

int Drow::getTileID() { return id; };
Tile* Drow::getTilePtr() { return this; };

bool Drow::triggerAbility(int id, int ab_ver) {
    if (id == DROW) {
        return true;
    }
    return false;
}
