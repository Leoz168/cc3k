#ifndef PLAYER_H
#define PLAYER_H

#include "../GameObject.h"
#include "../../Handler/Effects/EffectHandler.h"
#include "Directions.h"
#include <cmath>
#include <memory>

using namespace std;

class Enemy;

class Player: public GameObject {
    protected:
        int hp_now;
        int hp_max;
        int atk;
        int def;
        int id;
        int gold;
        bool merchant_hostility = false;
    public:
        unique_ptr<EffectHandler> ehr;
        Player(int x, int y, int id, int hp_now, int hp_max, int atk, int def, int gold);
        virtual int getTileID() = 0;
        virtual Tile* getTilePtr() = 0;
        int getHP();
        int getAtk();
        int getDef();
        int getMaxHP();
        int getGoldCount();
        bool getMerchantHostility();
        void setHPMax(int hp_max);
        void setHP(int hp_now);
        void setAtk(int atk);
        void setDef(int def);
        void setGoldCount(int gold);
        void setMerchantHostility(bool);
        void usePotion(int id);
        std::pair<int, int> getPosition();
        void setPosition(int x, int y);
        void setRoom(int room);
        void move(int x, int y, int dx, int dy);
        virtual bool attackEnemy(Enemy * e) = 0;
        virtual void attackedBy(Enemy * e) = 0;
        virtual bool triggerAbility(int id, int ab_ver) = 0;
        ~Player();
};

#endif
