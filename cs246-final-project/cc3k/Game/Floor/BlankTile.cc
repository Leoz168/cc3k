#include "BlankTile.h"
#include "../tileIDs.h"

using namespace std;

BlankTile::BlankTile(int x, int y) : id{BLANK}, Tile{x, y} {}
int BlankTile::getTileID(int x, int y) { return id; }
Tile* BlankTile::getTilePtr(int x, int y) { return this; }
bool BlankTile::move(int x, int y, int dx, int dy) { return false; }
pair<bool, bool> BlankTile::playerAttack(int x, int y) { 
    return std::pair<bool, bool>{false, false};
}
bool BlankTile::playerUsed(int x, int y) { return false; }
bool BlankTile::takeAction(int x, int y) { return false; }
BlankTile::~BlankTile() {}
