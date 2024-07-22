#include "blankFloor.h"
#include "../tileIDs.h"

using namespace std;

BlankFloor::BlankFloor() : id{BLANK} {}
int BlankFloor::getTileID(int x, int y) { return id; }
Floor* BlankFloor::getTilePtr(int x, int y) { return this; }
bool BlankFloor::move(int x, int y, int dx, int dy) { return false; }
pair<bool, bool> BlankFloor::playerAttack(int x, int y) { 
    return std::pair<bool, bool>{false, false};
}
bool BlankFloor::playerUsed(int x, int y) { return false; }
bool BlankFloor::takeAction(int x, int y) { return false; }
BlankFloor::~BlankFloor() {}
