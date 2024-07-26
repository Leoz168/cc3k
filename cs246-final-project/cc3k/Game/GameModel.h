#pragma once

#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <string>

#include "../Display/GameSubject.h"
#include "Game/Directions.h"
#include "Tile.h"
#include "tileIDs.h"
#include "Floor/Cell/Cell.h"
#include "GameObject/Enemy/Enemy.h"
#include "GameObject/Item/Item.h"
#include "GameObject/Player/Player.h"
#include "GameMap.h"
#include "Factory/CellCreator.h"
#include "Factory/EnemyCreator.h"
#include "Factory/ItemCreator.h"
#include "Factory/PlayerCreator.h"
#include "Handler/Effects/EffectHandler.h"

class GameModel: public GameSubject {
        // Game State variables:
        int numRows = -1;
        int numCols= -1;
        int floorLevel = 0;
        int potionSpawnCounter = 0;
        int enemySpawnCounter = 0;
        int goldSpawnCounter = 0;

        // Player variables:
        std::shared_ptr<Player> player;
        const std::map<char, int> playerRaceMap {
            {'s', SHADE},
            {'d', DROW},
            {'v', VAMPIRE},
            {'g', GOBLIN},
            {'t', TROLL}
        };
        int playerRace = SHADE;

        // Map and objects on the Map
        GameMap gameMap;
        std::vector<std::shared_ptr<Enemy>> enemies;
        std::vector<std::shared_ptr<Item>> items;
        std::vector<std::shared_ptr<Cell>> cells;

        // Keep track of what has already been created:
        bool isPlayerCreated = false;
        bool isStairCreated = false;
        bool isDragonHoardCreated = false;
        bool isDragonCreated = false;

        // Dragon and Hoard Positions:
        std::pair<int, int> dragonPosn = std::make_pair(-1, -1);
        std::pair<int, int> dragonHoardPosn = std::make_pair(-1, -1);
        std::shared_ptr<DragonHoard> dragonHoard = nullptr;
        std::shared_ptr<Dragon> dragon = nullptr;

    public:
        std::pair<int, int> randomSpawnablePosition();

        void setPlayerRace(char type);

        // Getters:
        int tileIDAt(int x, int y);
        bool isAvailableTileForSpawn(int x, int y);

        std::pair<int,int> findAvailableTileAround(int x, int y);


        // Creators:
        void initializeMap(ifstream &mapFile, bool isMapProvided);
        void readMap(ifstream& mapFile);

        // Spawn a specific type of game object and add it to the gameMap
        void spawnObject(int x, int y, char type);
        // Spawn a random game object(Item or Enemy) and add it to the gameMap
        // types:
        // - E: enemy
        // - P: potion
        // - G: gold
        void spawnRandObject(int x, int y, char type);

        bool createPlayerAtRandPosn();
        void createStairAtRandPosn();
        void createEnemyAtRandPosn();
        void createGoldAtRandPosn();
        void createPotionAtRandPosn();
        void createDragonAndHoardAtRandPosn();

        // Move:
        bool movePlayer(Directions direction);
        bool freezeEnemy();
        bool unfreezeEnemy();
        

        // Attack:
        bool playerAttack(Directions direction);
        bool isValidAttack(int x, int y);
        bool usePotion(Directions direction);

        // Game State Control:
        bool startGame();
        void nextFloor(ifstream& mapFile, bool isMapProvided);
        bool restartGame();
        int calculateScore();
        bool endGame();

        // Update Game State:

        // updateGame should be called at the end of every "turn", which by default is
        //     after every player action (e.g. move, atk, use, etc.). The function 
        //     causes all actionable GameObjects to "take a turn" (e.g. enemies will move/atk)
        //     (i.e. calling Tile->takeAction())
        void updateGame();
        
        bool resetFloor(Tile*);

        // Destructor:
        ~GameModel();     
};
