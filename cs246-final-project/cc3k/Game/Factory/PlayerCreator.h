#ifndef PLAYERCREATOR_H
#define PLAYERCREATOR_H

#include "Creator.h"
#include "../GameObject/Player/Player.h"
#include "../GameObject/Player/Shade.h"
#include "../GameObject/Player/Drow.h"
#include "../GameObject/Player/Goblin.h"
#include "../GameObject/Player/Troll.h"
#include "../GameObject/Player/Vampire.h"

class EffectHandler;

class PlayerCreator : public Creator {

    public:
        std::unique_ptr<Tile> spawnPlayer(int x, int y, int id, EffectHandler *ehr) override {
            std::unique_ptr<Player> newPlayer;

            switch (id) {
                case SHADE:
                    newPlayer = make_unique<Shade>(x, y, ehr);
                    break;

                case DROW:
                    newPlayer = make_unique<Drow>(x, y, ehr);
                    break;

                case VAMPIRE:
                    newPlayer = make_unique<Vampire>(x, y, ehr);
                    break;

                case TROLL:
                    newPlayer = make_unique<Troll>(x, y, ehr);
                    break;

                case GOBLIN:
                    newPlayer = make_unique<Goblin>(x, y, ehr);
                    break;

                default:
                    newPlayer = make_unique<Shade>(x, y, ehr);
                    break;
            }

            return newPlayer;
        }
};

#endif
