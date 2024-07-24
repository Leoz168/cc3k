#ifndef OBJECTCREATOR_H
#define OBJECTCREATOR_H

#include <map>
#include <cstdlib>
#include <memory>

#include "tileIDs.h"
#include "CellCreator.h"
#include "EnemyCreator.h"
#include "ItemCreator.h"
#include "PlayerCreator.h"
#include "effecthandler.h"

class Tile;

class ObjectCreator {
    protected:
        // creates a Tile specified by type by calling the correct Creator for the Tile we want to create.
        // types: 
        // - C: cell
        // - E: enemy
        // - G: gold (by default - GOLD)
        // - P: potion (by default - RESTOREHEALTH)
        // - @: player

        std::shared_ptr<Tile> createObject(int x, int y, char type, bool is_rand_generated = false, int id = NOTHING, EffectHandler *ehr = nullptr) {
            CellCreator makeCell;
            PlayerCreator makePlayer;
            EnemyCreator makeEnemy;
            ItemCreator makeItem;
            std::shared_ptr<Tile> newObject;
            switch (type) {
                case 'C':
                    newObject = makeCell.spawnTile(x, y, id, false);
                    break;

                case 'E':
                    newObject = makeEnemy.spawnTile(x, y, id, is_rand_generated);
                    break;

                case 'G':
                    newObject = makeItem.spawnTile(x, y, GOLD, is_rand_generated);
                    break;

                case 'P':
                    newObject = makeItem.spawnTile(x, y, RESTOREHEALTH, is_rand_generated);
                    break;

                case '@':
                    newObject = makePlayer.spawnPlayer(x, y, id, ehr);
                    break;

                default:
                    break;
            }
            
            return newObject;
        }
};

#endif
