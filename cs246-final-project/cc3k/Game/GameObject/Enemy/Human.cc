#include "Human.h"
#include "../../tileIDs.h"
#include "../Player/Player.h"

using namespace std;

Human::Human(int x, int y) : 
    Enemy(140, 20, 20, this, x, y, HUMAN) {}

Tile* Human::getTilePtr() { return this; }

Human::~Human() {}
