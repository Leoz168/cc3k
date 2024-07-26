#include "Drow.h"
#include "../Enemy/Enemy.h"
using namespace std;

Drow::Drow(int x, int y): Player(x, y, DROW, 150, 150, 25, 15, 0) {}

bool Drow::attackEnemy(Enemy *e) {
    e->atkedByPlayer(this);
}

void Drow::attackedBy(Enemy *e) {
    hp_now -= ceil((100 / (100 + getDef())) * e->getAtk());
}

int Drow::getTileID() { return id; };
Tile* Drow::getTilePtr() { return this; };

bool Drow::triggerAbility(int id, int ab_ver) {
    if (id == DROW) {
        return true;
    }
    return false;
}
