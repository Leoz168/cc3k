#include "Potion.h"

using namespace std;

Potion::Potion(string description, int x, int y, int id) :
    Item{description, x, y, id, POTION} {}

bool Potion::canPlayerUse(Player* player) { return true; }

Potion::~Potion() {}
