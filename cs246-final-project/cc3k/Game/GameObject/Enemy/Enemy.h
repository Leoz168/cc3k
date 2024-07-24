#ifndef ENEMY_H
#define ENEMY_H

#include "../GameObject.h"
#include "../Player/player.h"
#include "../../Tile.h"

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

        // attackPlayer causes the eneny to attack the player. The return value
        //     indicates whether the attack succeeded or not.
        // Default: default attack.
        virtual bool attackPlayer(Player*);

        virtual bool atkedByPlayer(Player*);

        // Default: moves by dx, dy if available.
        virtual bool move(int dx, int dy, vector<vector<shared_ptr<Tile>>>& map);
        
        virtual bool takeAction(Player*, vector<vector<shared_ptr<Tile>>>& map);
        virtual ~Enemy() = 0;
};

#endif
