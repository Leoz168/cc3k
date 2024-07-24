#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "effecthandler.h"
#include "enemy.h"
#include "tileIDs.h"

class Player: public GameObject {
        int hp_now;
        int hp_max;
        int atk;
        int def;
        int id;
        int gold;
        EffectHandler *ehr;
    public:
        Player(int x, int y, int id, int hp_now, int hp_max, int atk, int def, int gold, EffectHandler *ehr);
        virtual int getTileID() = 0;
        int getHP();
        int getAtk();
        int getDef();
        int getMaxHP();
        int getGoldCount();
        bool setHPMax(int hp_max);
        bool setHP(int hp_now);
        bool setAtk(int atk);
        bool setDef(int def);
        bool setGoldCount(int gold);
        std::pair<int, int> getPosition();
        bool setPosition(int x, int y);
        bool move(int x, int y, int dx, int dy);
        bool Player::attackEnemy(Enemy * e);
        bool Player::attackedBy(Enemy * e);
        virtual bool triggerAbility(int id, int ab_ver) = 0;
        ~Player();
};

#endif
