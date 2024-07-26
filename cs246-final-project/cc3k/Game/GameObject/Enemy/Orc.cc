#include "Orc.h"
#include "../../tileIDs.h"
#include "../Player/Player.h"

using namespace std;

Orc::Orc(int x, int y) : 
    Enemy(180, 30, 25, this, x, y, ORC) {}

Tile* Orc::getTilePtr() { return this; }

Orc::~Orc() {}
