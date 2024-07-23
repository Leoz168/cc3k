#include "tileIDs.h"
#include "player.h"
#include "enemy.h"

class Elf: public Enemy {
    public:
        Elf(int x, int y);
        bool playerAtk(Player *);
        bool takeAction();
        ~Elf();
};