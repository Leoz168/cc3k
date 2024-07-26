#include "Elf.h"
#include "../../tileIDs.h"
#include "../Player/Player.h"
#include "../../GameMap.h"
#include <iostream>

using namespace std;

Elf::Elf(int x, int y) : 
    Enemy(140, 30, 10, this, x, y, ELF) {}

Tile* Elf::getTilePtr() { return this; }

void Elf::postAtkAction(Player* player, GameMap& map) {
    if(player->getTileID() != DROW) attackPlayer(player);
}

Elf::~Elf() {}
