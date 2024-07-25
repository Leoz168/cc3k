#ifndef ITEMCREATOR_H
#define ITEMCREATOR_H

#include "Creator.h"
#include "tileIDs.h"
#include "Item.h"
#include "Gold.h"
#include "MerchantHoard.h"
#include "DragonHoard.h"
#include "BA.h"
#include "BD.h"
#include "RH.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"

class ItemCreator : public Creator
{
	// Potion probabilities
	int totalGoldProbability = 6;
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
        for (const auto& entry : goldProbabilityMap) {
            sum += entry.second;
            if (sum >= probabilityIndex) {
                return entry.first;
            }
        }
        return NORMALGOLD;

    int choosePotionType() {
        int probabilityIndex = rand() % totalPotionProbability;
        int sum = 0;
        for (const auto& entry : potionProbabilityMap) {
            sum += entry.second;
            if (sum >= probabilityIndex) {
                return entry.first;
            }
        }
        return RESTOREHEALTH;
    }

public:
    std::unique_ptr<Tile> spawnTile(int x, int y, int id = NOTHING, bool is_rand_generated = false) override {
        std::unique_ptr<Tile> newItem;
        if (is_rand_generated) {
            if (id == GOLD) { // default values - provde in ObjectCreator
                id = chooseGoldType();
            } else if (id == RESTOREHEALTH) { // default values - provde in ObjectCreator
                id = choosePotionType();
            }
        }


        switch (id) {
            case NORMALGOLD:
                newItem = std::make_unique<NormalGold>(x, y);
                break;
            case SMALLGOLD:
                newItem = std::make_unique<SmallGold>(x, y);
                break;
            case DRAGONHOARD:
                newItem = std::make_unique<DragonHoard>(x, y);
                break;
            case RESTOREHEALTH:
                newItem = std::make_unique<RH>(x, y);
                break;
            case BOOSTATK:
                newItem = std::make_unique<BA>(x, y);
                break;
            case BOOSTDEF:
                newItem = std::make_unique<BD>(x, y);
                break;
            case POISONHEALTH:
                newItem = std::make_unique<PH>(x, y);
                break;
            case WOUNDATK:
                newItem = std::make_unique<WA>(x, y);
                break;
            case WOUNDDEF:
                newItem = std::make_unique<WD>(x, y);
                break;
        }
        return newItem;
    }

};

#endif
