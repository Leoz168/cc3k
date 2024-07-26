#ifndef ENEMY_H
#define ENEMY_H

#include "../GameObject.h"
#include "../../Tile.h"
#include "../../GameMap.h"
#include <utility>

using namespace std;

class Player;

class Enemy: public GameObject {
    protected:
        int hp;
        int atk;
        int def;
        Enemy* thisEnemy;
        bool hostile;
        bool is_frozen = false;

        virtual void preAction(Player* player, GameMap& map);
        virtual void postMoveAction(Player* player, GameMap& map);
        virtual void postAtkAction(Player* player, GameMap& map);
        virtual void preAtkedByPlayerAction(Player* player);
        virtual void postAtkedByPlayerAction(Player* player);
    public:
        Enemy(int hp, int atk, int def, Enemy* thisEnemy, int x, int y, int id, bool hostility = true);

        int getHP();
        int getAtk();
        int getDef();
        bool isDead();
        void takeDamage(int dHP);

        // attackPlayer causes the eneny to attack the player. The return value
        //     indicates whether the attack succeeded or not.
        // Default: default attack.
        virtual bool attackPlayer(Player*);

        // Default: default damage calculations, always succeeds
        //     Damage(Defender) = ceiling((100/(100 + Def (Def ender))) ∗ Atk(Attacker))
        // Returns std::pair<bool, bool>, where first is if the attack succeeded, and
        //     second is if the attack killed.
        virtual std::pair<bool, bool> atkedByPlayer(Player*);

        // Default: moves by dx, dy.
        virtual bool move(int dx, int dy, GameMap& map) override;
        
        // takeAction allows the enemy to "take a turn"
        // Default: Attacks if player within one block radius.
        //          Moves a random direction one tile if player not within radius,
        //              if the tile is unoccupied and a FloorTile. Will check in a
        //              clockwise radius, starting from the randomly selected direction.
        //          If neither action can be done, does nothing.
        // Returns whether the tile should be despawned after the action (default: false)
        virtual bool takeAction(Player* player, GameMap& map) override;

        bool setFrozen(bool);

        virtual ~Enemy() = default;
};

#endif
