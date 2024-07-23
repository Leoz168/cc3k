#include "gameObject.h"
class Enemy: public GameObject {
    protected:
        int hp;
        int atk;
        int def;
    public:
        Enemy(int x, int y, int id, int hp, int atk, int def);
        int getHP();
        int getAtk();
        int getDef();
        virtual ~Enemy() = default;
};
