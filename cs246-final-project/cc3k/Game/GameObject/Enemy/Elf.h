#ifndef ELF_H
#define ELF_H

#include <utility>
#include "../Player/Player.h"
#include "Enemy.h"
#include "../../Tile.h"

class Elf: public Enemy {
    public:
        Elf(int x, int y);
        Tile* getTilePtr() override;
        bool move(int dx, int dy) override;
        std::pair<bool, bool> playerAttack() override;
        bool takeAction() override;
        ~Elf();
};

#endif
