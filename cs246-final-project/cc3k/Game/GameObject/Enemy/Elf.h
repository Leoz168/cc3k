#ifndef ELF_H
#define ELF_H

#include "Enemy.h"

using namespace std;

class Elf : public Enemy {
        void postAtkAction(Player* player, GameMap& map) override;
    public:
        Elf(int x, int y);
        Tile* getTilePtr() override;
        ~Elf();
};


#endif
