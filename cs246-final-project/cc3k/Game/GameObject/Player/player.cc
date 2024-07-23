#include "player.h"
Player::Player(int x, int y, int hp_now, int hp_max, int atk, int def, int id, int gold, EffectHandler *ehr):
GameObject{x, y, id}, hp_now(hp_now), hp_max{hp_max}, atk{atk}, def{def}, gold{gold}, ehr{ehr} {}

int Player::getHP() { return hp_now; }

int Player::getAtk() { return atk + ehr->getAtkEffect(); }

int Player::getDef() { return def + ehr->getDefEffect(); }

int Player::getMaxHP() { return hp_max; }

int Player::getGoldCount() { return gold; }

bool Player::setHPMax(int hp_max) { this->hp_max = hp_max; }

bool Player::setHP(int hp_now) { this->hp_now = hp_now; }

bool Player::setAtk(int atk) { this->atk = atk; }

bool Player::setDef(int def) { this->def = def; }

bool Player::setGoldCount(int gold) { this->gold = gold; }

std::pair<int, int> Player::getPosition() { return std::pair<int, int>{x, y}; }

bool Player::setPosition(int x, int y) { this->x = x; this->y = y; }

bool Player::move(int x, int y, int dx, int dy) { this->x += dx; this->y += dy; }

bool Player::attackEnemy(Enemy *e) { e->playerAttack(); }

bool Player::attackedBy(Enemy *e) { hp_now -= e->getDef(); }

Player::~Player() { delete ehr; }
