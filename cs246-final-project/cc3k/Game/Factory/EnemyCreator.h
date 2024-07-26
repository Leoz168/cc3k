#ifndef ENEMYCREATOR_H
#define ENEMYCREATOR_H

#include <vector>
#include <stdlib.h>
#include <iostream>

#include "Creator.h"
#include "../tileIDs.h"
#include "../GameObject/Enemy/Enemy.h"
#include "../GameObject/Enemy/Dragon.h"
#include "../GameObject/Enemy/Dwarf.h"
#include "../GameObject/Enemy/Elf.h"
#include "../GameObject/Enemy/Orc.h"
#include "../GameObject/Enemy/Halfling.h"
#include "../GameObject/Enemy/Human.h"
#include "../GameObject/Enemy/Merchant.h"


class EnemyCreator : public Creator {

	// probabilities: [race] = probability
	const int totalEnemyProbability = 18;
	map<int, int> probabilityMap {
		{HUMAN , 4},
		{DWARF, 3},
		{ELF, 2},
		{ORC, 2},
		{MERCHANT, 2},
		{HALFLING, 5}
	};

    int chooseEnemyRace() {
        int probabilityIndex = rand() % totalEnemyProbability;
        int sum = 0;
        for (const auto& entry : probabilityMap) {
            sum += entry.second;
            if (sum >= probabilityIndex) {
                return entry.first;
            }
        }
        return HUMAN;
    }

    public:
        std::unique_ptr<Tile> spawnTile(int x, int y, int id = NOTHING, bool is_rand_generated = false) override {
            std::unique_ptr<Tile> newEnemy;
            if (is_rand_generated) { // choose a random Enemy race
                id = chooseEnemyRace();
            }

            switch (id) {
                case HUMAN:
                    newEnemy = make_unique<Human>(x, y);
                    break;
                case DWARF:
                    newEnemy = make_unique<Dwarf>(x, y);
                    break;
                case ELF:
                    newEnemy = make_unique<Elf>(x, y);
                    break;
                case ORC:
                    newEnemy = make_unique<Orc>(x, y);
                    break;
                case MERCHANT:
                    newEnemy = make_unique<Merchant>(x, y);
                    break;
                case HALFLING:
                    newEnemy = make_unique<Halfling>(x, y);
                    break;
                default:
                    std::cerr << "Could Not initialize enemy. Invalid id" + std::to_string(id) + " in EnemyCreator" << endl;
                    break;
            }

            return newEnemy;
        }
};

#endif