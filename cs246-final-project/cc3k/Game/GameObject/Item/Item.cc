#include "Item.h"
#include "../GameObject.h"
#include <string>

using namespace std;

Item::Item(string description, int x, int y, int id, int tile_type): 
    description{description}, 
    GameObject{x, y, id, tile_type} {}

string Item::getDescription() { return description; }

bool Item::canPlayerPickup(Player* player) { return false; }

bool Item::canPlayerUse(Player* player) { return false; }
