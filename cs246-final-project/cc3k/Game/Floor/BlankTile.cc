#include "BlankTile.h"
#include "../tileIDs.h"

using namespace std;

BlankTile::BlankTile(int x, int y) : id{BLANK}, Tile{x, y} {}
int BlankTile::getTileID() { return id; }
Tile* BlankTile::getTilePtr() { return this; }
bool BlankTile::move(int dx, int dy) { return false; }
pair<bool, bool> BlankTile::playerAttack() { 
    return std::pair<bool, bool>{false, false};
}
bool BlankTile::playerUsed() { return false; }
bool BlankTile::takeAction() { return false; }
BlankTile::~BlankTile() {}
