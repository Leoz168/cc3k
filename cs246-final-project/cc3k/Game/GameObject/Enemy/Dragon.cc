#include "Dragon.h"
#include "tileIDs.h"
#include "Player.h"
#include "GameMap.h"
#include "Directions.h"

using namespace std;

Dragon::Dragon(int x, int y, shared_ptr<DragonHoard> hoard) : 
    hoard{hoard},
    Enemy(150, 20, 20, this, x, y, DRAGON, false) {}

Tile* Dragon::getTilePtr() { return this; }

void Dragon::preAction(Player* player, GameMap& map) {
    pair<int, int> playerPosn = player->getPosn();
    pair<int, int> thisPosn = getPosn();
    pair<int, int> hoardPosn = hoard->getPosn();

    if (abs(playerPosn.first - thisPosn.first) <= 1 && abs(playerPosn.second - thisPosn.second) <= 1) {
        hostile = true;
    } else if (abs(playerPosn.first - hoardPosn.first) <= 1 && abs(playerPosn.second - hoardPosn.second) <= 1) {
        hostile = true;
    } else {
        hostile = false;
    }
}

bool Dragon::takeAction(Player* player, GameMap& map) {
    preAction(player, map);

    if (hostile) {
        attackPlayer(player);
        postAtkAction(player, map);
    }

    return false;
}

Dragon::~Dragon() {}
