#include "Player.h"
#include "../Enemy/Enemy.h"
#include <iostream>
using namespace std;

Player::Player(int x, int y, int id, int hp_now, int hp_max, int atk, int def, int gold)
: GameObject{x, y, id}, id(id), hp_now(hp_now), hp_max(hp_max), atk(atk), def(def), gold(gold), ehr(std::unique_ptr<EffectHandler>{new EffectHandler{}}) {}

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

void Player::usePotion(int id) {
    switch (id)
        {
        case RESTOREHEALTH:
            int hp_now = this->getHP();
            int hp_max = this->getMaxHP();
            if (this->getTileID() == VAMPIRE) {
                this->setHP(hp_now + 10);
            } else {
                if (hp_now + 10 <= hp_max) {
                    this->setHP(hp_now + 10);
                } else {
                    this->setHP(hp_max);
                }
            }
            break;
        case BOOSTATK:
            this->ehr->addAtkEffect(5);
            break;
        case BOOSTDEF:
            this->ehr->addDefEffect(5);
            break;
        case POISONHEALTH:
            int hp_now = this->getHP();
            if (hp_now - 10 >= 0) {
                this->setHP(hp_now - 10);
            } else {
                this->setHP(0);
            }
            break;
        case WOUNDATK:
            this->ehr->addAtkEffect(-5);
            break;
        case WOUNDDEF:
            this->ehr->addDefEffect(-5);
        default:
            cout << "Ah? What are you picking?" << endl;
            break;
        }
}

void Player::move(int x, int y, int dx, int dy) { this->x += dx; this->y += dy; }

Player::~Player() {}
