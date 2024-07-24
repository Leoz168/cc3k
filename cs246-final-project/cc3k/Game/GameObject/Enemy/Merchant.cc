#include "Merchant.h"
#include "tileIDs.h"
#include "Directions.h"
#include "Player.h"
#include "GameMap.h"
#include <iostream>

using namespace std;

Merchant::Merchant(int x, int y) : 
    Enemy(30, 70, 5, this, x, y, MERCHANT, false) {}

Tile* Merchant::getTilePtr() { return this; }

void Merchant::preAction(Player* player, GameMap& map) {
    if (player->getMerchantHostility()) {
        hostile = true;
    } else {
        hostile = false;
    }
}

Merchant::~Merchant() {}
