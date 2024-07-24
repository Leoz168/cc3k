#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "EffectHandler.h"
#include "Enemy.h"
#include "tileIDs.h"
#include <cmath>

class Player: public GameObject {
    protected:
        int hp_now;
        int hp_max;
        int atk;
        int def;
        int id;
        int gold;
        unique_ptr<EffectHandler> ehr;
    public:
        Player(int x, int y, int id, int hp_now, int hp_max, int atk, int def, int gold, EffectHandler *ehr);
        virtual int getTileID() = 0;
        int getHP();
        int getAtk();
        int getDef();
        int getMaxHP();
        int getGoldCount();
        void setHPMax(int hp_max);
        void setHP(int hp_now);
        void setAtk(int atk);
        void setDef(int def);
        void setGoldCount(int gold);
        std::pair<int, int> getPosition();
        void setPosition(int x, int y);
        void move(int x, int y, int dx, int dy);
        virtual bool Player::attackEnemy(Enemy * e);
        virtual void Player::attackedBy(Enemy * e);
        virtual bool triggerAbility(int id, int ab_ver) = 0;
        ~Player();
};

#endif
