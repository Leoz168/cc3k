#ifndef ITEMCREATOR_H
#define ITEMCREATOR_H

#include "Creator.h"
#include "../tileIDs.h"
#include "../GameObject/Item/Item.h"
#include "../GameObject/Item/Treasure/Gold.h"
#include "../GameObject/Item/Treasure/NormalGold.h"
#include "../GameObject/Item/Treasure/SmallGold.h"
#include "../GameObject/Item/Treasure/MerchantHoard.h"
#include "../GameObject/Item/Treasure/DragonHoard.h"
#include "../GameObject/Item/Potion/BoostAtk.h"
#include "../GameObject/Item/Potion/BoostDef.h"
#include "../GameObject/Item/Potion/RestoreHealth.h"
#include "../GameObject/Item/Potion/PoisonHealth.h"
#include "../GameObject/Item/Potion/WoundAtk.h"
#include "../GameObject/Item/Potion/WoundDef.h"

class ItemCreator : public Creator {
	// Potion probabilities
	int totalPotionProbability = 6;
	map<int, int> potionMap {
		{RESTOREHEALTH, 0},
		{BOOSTATK, 1},
		{BOOSTDEF, 2},
		{POISONHEALTH, 3},
		{WOUNDATK, 4},
		{WOUNDDEF, 5}
	};

	// Gold probabilities
	int totalGoldProbability = 8;
	map<int, int> goldMap {
		{NORMALGOLD, 5},
		{SMALLGOLD, 2},
		{DRAGONHOARD, 1}
	};
	

    int chooseGoldType() {
        int probabilityIndex = rand() % totalGoldProbability;
        int sum = 0;
        for (const auto& entry : goldMap) {
            sum += entry.second;
            if (sum >= probabilityIndex) {
                return entry.first;
            }
        }
        return NORMALGOLD;
    }

    int choosePotionType() {
        int probabilityIndex = rand() % totalPotionProbability;
        int sum = 0;
        for (const auto& entry : potionMap) {
            sum += entry.second;
            if (sum >= probabilityIndex) {
                return entry.first;
            }
        }
        return RESTOREHEALTH;
    }

    public:
        std::shared_ptr<Tile> spawnTile(int x, int y, int id = NOTHING, bool is_rand_generated = false) override {
            std::shared_ptr<Tile> newItem;
            if (is_rand_generated) {
                if (id == NORMALGOLD) { // default values - provde in ObjectCreator
                    id = chooseGoldType();
                } else if (id == RESTOREHEALTH) { // default values - provde in ObjectCreator
                    id = choosePotionType();
                }
            }


            switch (id) {
                case NORMALGOLD:
                    newItem = std::make_shared<NormalGold>(x, y);
                    break;
                case SMALLGOLD:
                    newItem = std::make_shared<SmallGold>(x, y);
                    break;
                case DRAGONHOARD:
                    newItem = std::make_shared<DragonHoard>(x, y);
                    break;
                case RESTOREHEALTH:
                    newItem = std::make_shared<RestoreHealth>(x, y);
                    break;
                case BOOSTATK:
                    newItem = std::make_shared<BoostAtk>(x, y);
                    break;
                case BOOSTDEF:
                    newItem = std::make_shared<BoostDef>(x, y);
                    break;
                case POISONHEALTH:
                    newItem = std::make_shared<PoisonHealth>(x, y);
                    break;
                case WOUNDATK:
                    newItem = std::make_shared<WoundAtk>(x, y);
                    break;
                case WOUNDDEF:
                    newItem = std::make_shared<WoundDef>(x, y);
                    break;
            }
            return newItem;
        }
};

#endif
