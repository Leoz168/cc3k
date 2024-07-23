#include "enemy.h"

Enemy::Enemy(int x, int y, int hp, int id, int atk, int def): GameObject{x, y, id}, hp{hp}, atk{atk}, def{def} {}

int Enemy::getHP() { return hp; }
int Enemy::getAtk() { return atk; }
int Enemy::getDef() { return def; }

Enemy::~Enemy() {}
