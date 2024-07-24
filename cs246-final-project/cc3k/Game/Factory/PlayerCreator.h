#ifndef PLAYERCREATOR_H
#define PLAYERCREATOR_H

#include "Creator.h"
#include "Player.h"
#include "Shade.h"
#include "Drow.h"
#include "Goblin.h"
#include "Troll.h"
#include "Vampire.h"

class EffectHandler;

class PlayerFactory : public Creator {

    public:
        std::shared_ptr<Tile> spawnPlayer(int x, int y, int id, EffectHandler *ehr) override {
            std::shared_ptr<Player> newPlayer;

            switch (id) {
                case SHADE:
                    newPlayer = make_shared<Shade>(x, y, ehr);
                    break;

                case DROW:
                    newPlayer = make_shared<Drow>(x, y, ehr);
                    break;

                case VAMPIRE:
                    newPlayer = make_shared<Vampire>(x, y, ehr);
                    break;

                case TROLL:
                    newPlayer = make_shared<Troll>(x, y, ehr);
                    break;

                case GOBLIN:
                    newPlayer = make_shared<Goblin>(x, y, ehr);
                    break;

                case default:
                    newPlayer = make_shared<Shade>(x, y, ehr);
                    break;
            }

            return newPlayer;
        }
};

#endif
