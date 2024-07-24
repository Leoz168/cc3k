#ifndef DWARF_H
#define DWARF_H

#include "Enemy.h"
#include <utility>

using namespace std;
class Dwarf : public Enemy {
    public:
        Dwarf(int x, int y);
        Tile* getTilePtr() override;
        std::pair<bool, bool> atkedByPlayer(Player*) override;
        ~Dwarf();
};


#endif
