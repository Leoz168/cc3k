#include "Enemy.h"
#include "../Player/Player.h"
#include "../../Directions.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

Enemy::Enemy(int hp, int atk, int def, Enemy* thisEnemy, int x, int y, int id, bool hostility) :
    hp{hp},
    atk{atk}, 
    def{def}, 
    thisEnemy{thisEnemy},
    hostile{hostility},
    GameObject{x, y, id, ENEMY} {}

int Enemy::getHP() { return hp; }
int Enemy::getAtk() { return atk; }
int Enemy::getDef() { return def; }
bool Enemy::isDead() { return getHP() <= 0; }
void Enemy::takeDamage(int damage) { hp -= damage; }

Enemy::~Enemy() = default;

bool Enemy::attackPlayer(Player* player) {
    if ((rand() % 2) == 0) {
        return false;
    } else {
        player->attackedBy(thisEnemy);
    }
}

void Enemy::preAtkedByPlayerAction(Player* player) { return; }
void Enemy::postAtkedByPlayerAction(Player* player) { return; }

pair<bool, bool> Enemy::atkedByPlayer(Player* player) {
    preAtkedByPlayerAction(player);

    takeDamage( ceil((100 / (100 + getDef())) * player->getAtk()) );

    postAtkedByPlayerAction(player);

    if ( isDead() ) return make_pair(true, true);

    return make_pair(true, false);
}

bool Enemy::move(int dx, int dy, GameMap& map) {
    if (map.moveTile(x, y, dx, dy, thisEnemy)) {
        x += dx;
        y += dy;
        return true;
    }
    return false;
}

void Enemy::preAction(Player* player, GameMap& map) { return; }

void Enemy::postMoveAction(Player* player, GameMap& map) { return; }

void Enemy::postAtkAction(Player* player, GameMap& map) { return; }

bool Enemy::takeAction(Player* player, GameMap& map) {
    preAction(player, map);

    pair<int, int> playerPosn = player->getPosn();
    pair<int, int> thisPosn = getPosn();

    if (abs(playerPosn.first - thisPosn.first) <= 1 && abs(playerPosn.second - thisPosn.second) <= 1 && hostile) {
        attackPlayer(player);
        postAtkAction(player, map);
    } else if (!is_frozen) {
        Directions direction = Directions(rand() % NUM_DIRECTIONS);
        for (int i = 0; i < NUM_DIRECTIONS; i++) {
            int dx, dy;

            switch (Directions((direction + i) % NUM_DIRECTIONS)) {
                case N:
                    dx = 0;
                    dy = -1;
                    break;
                case NE:
                    dx = 1;
                    dy = -1;
                    break;
                case E:
                    dx = 1;
                    dy = 0;
                    break;
                case SE:
                    dx = 1;
                    dy = 1;
                    break;
                case S:
                    dx = 0;
                    dy = 1;
                    break;
                case SW:
                    dx = -1;
                    dy = 1;
                    break;
                case W:
                    dx = -1;
                    dy = 0;
                    break;
                case NW:
                    dx = -1;
                    dy = 1;
                    break;
            }

            if (map.tileIDAt(thisPosn.first + dx, thisPosn.second + dy) == FLOORTILE) {
                if (!move(dx, dy, map)) {
                    cerr << "position desync of enemy " << id << " at position " << thisPosn.first << "," << thisPosn.second << endl;
                } else {
                    postMoveAction(player, map);
                }
                break;
            }
        }
    }
    return false;
}

bool Enemy::setFrozen(bool frozen) {
    is_frozen = frozen;
    return frozen;
}
