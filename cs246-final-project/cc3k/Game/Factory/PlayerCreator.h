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
        std::shared_ptr<Player> spawnPlayer(int x, int y, int id) override {
            std::shared_ptr<Player> newPlayer;

            switch (id) {
                case SHADE:
                    newPlayer = make_shared<Shade>(x, y);
                    break;

                case DROW:
                    newPlayer = make_shared<Drow>(x, y);
                    break;

                case VAMPIRE:
                    newPlayer = make_shared<Vampire>(x, y);
                    break;

                case TROLL:
                    newPlayer = make_shared<Troll>(x, y);
                    break;

                case GOBLIN:
                    newPlayer = make_shared<Goblin>(x, y);
                    break;

                default:
                    newPlayer = make_shared<Shade>(x, y);
                    break;
            }

            return newPlayer;
        }
};

#endif
