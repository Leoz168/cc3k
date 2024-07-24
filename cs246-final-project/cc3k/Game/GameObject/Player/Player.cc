#include "Player.h"
Player::Player(int x, int y, int id, int hp_now, int hp_max, int atk, int def, int gold, EffectHandler* ehr)
: GameObject{x, y, id}, id(id), hp_now(hp_now), hp_max(hp_max), atk(atk), def(def), gold(gold), ehr(ehr) {}

int Player::getHP() { return hp_now; }

int Player::getAtk() { return atk + ehr->getAtkEffect(); }

int Player::getDef() { return def + ehr->getDefEffect(); }

int Player::getMaxHP() { return hp_max; }

int Player::getGoldCount() { return gold; }

bool Player::getMerchantHostility() { return merchant_hostility; }

void Player::setHPMax(int hp_max) {
    this->hp_max = hp_max;
}

void Player::setHP(int hp_now) { this->hp_now = hp_now; }

void Player::setAtk(int atk) { this->atk = atk; }

void Player::setDef(int def) { this->def = def; }

void Player::setGoldCount(int gold) { this->gold = gold; }

void Player::setMerchantHostility(bool hostility) { this->merchant_hostility = hostility; }

std::pair<int, int> Player::getPosition() { return std::pair<int, int>{x, y}; }

void Player::setPosition(int x, int y) { this->x = x; this->y = y; }

void Player::move(int x, int y, int dx, int dy) { this->x += dx; this->y += dy; }

Player::~Player() {}
