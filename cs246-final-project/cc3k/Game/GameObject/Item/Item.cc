#include "Item.h"
#include "GameObject.h"
#include <string>

using namespace std;

Item::Item(string description, int x, int y, int id): 
    description{description}, 
    GameObject{x, y, id} {}

string Item::getDescription() { return description; }

bool Item::canPlayerPickup(Player* player) { return false; }

bool Item::canPlayerUse(Player* player) { return false; }
