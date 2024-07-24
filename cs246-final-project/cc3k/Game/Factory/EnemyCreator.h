#ifndef ENEMYCREATOR_H
#define ENEMYCREATOR_H

#include "Creator.h"
#include "TileIDs.h"
#include "Enemy.h"
#include "Dragon.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Halfling.h"
#include "Human.h"
#include "Merchant.h"


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

    public:
        std::shared_ptr<Tile> spawnTile(int x, int y, int id = NOTHING, bool is_rand_generated = false) override {
            std::shared_ptr<Tile> newEnemy;
            if (is_rand_generated) { // choose a random Enemy race
                id = chooseEnemyRace();
            }

            switch (id) {
                case HUMAN:
                    newEnemy = make_shared<Human>(x, y);
                    break;
                case DWARF:
                    newEnemy = make_shared<Dwarf>(x, y);
                    break;
                case ELF:
                    newEnemy = make_shared<Elf>(x, y);
                    break;
                case ORC:
                    newEnemy = make_shared<Orc>(x, y);
                    break;
                case MERCHANT:
                    newEnemy = make_shared<Merchant>(x, y);
                    break;
                case HALFLING:
                    newEnemy = make_shared<Halfling>(x, y);
                    break;
                case DRAGON:
                    newEnemy = make_shared<Dragon>(x, y);
                    break;
                case default:
                    break;
            }

            return newEnemy;
        }
};

#endif