#ifndef DWARF_H
#define DWARF_H

#include "Enemy.h"
#include <utility>

using namespace std;
class Dwarf : public Enemy {
        void postAtkedByPlayerAction(Player* player) override;
    public:
        Dwarf(int x, int y);
        Tile* getTilePtr() override;
        ~Dwarf();
};


#endif
