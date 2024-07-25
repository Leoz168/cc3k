#pragma once

#include <vector>
#include <memory>
#include "fstream"
#include <string>

#include "GameSubject.h"
#include "Tile.h"
#include "tileIDs.h"
#include "Cell.h"
#include "Enemy.h"
#include "Item.h"
#include "Player.h"
#include "GameMap.h"
#include "CellCreator.h"
#include "EnemyCreator.h"
#include "ItemCreator.h"
#include "PlayerCreator.h"
#include "AttackHandler.h"
#include "MoveHandler.h"
#include "EffectHandler.h"


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
        std::shared_ptr<EffectHandler> effectHandler;

        // Map and objects on the Map
        GameMap gameMap;
        std::vector<std::shared_ptr<Enemy>> enemies;
        std::vector<std::shared_ptr<Item>> items;
        std::vector<std::shared_ptr<Cell>> cells;

        // Map between char and tileID - for reading input from a file 
        const std::map<char, int> cellMap {
            {'.', FLOORTILE},
            {'|', VWALL},
            {'-', HWALL},
            {'#', PASSAGE},
            {'+', DOORWAY},
            {'\\', STAIR}
        };
        
        const std::map<char, int> itemMap {
            {'0', RESTOREHEALTH},
            {'1', BOOSTATK},
            {'2', BOOSTDEF},
            {'3', POISONHEALTH},
            {'4', WOUNDATK},
            {'5', WOUNDDEF},
            {'6', NORMALGOLD},
            {'7', SMALLGOLD},
            {'8', MERCHANTHOARD},
            {'9', DRAGONHOARD}
        };
        const std::map<char, int> enemyMap {
            {'D', DRAGON},
            {'H', HUMAN},
            {'E', ELF},
            {'O', ORC},
            {'L', HALFLING},
            {'M', MERCHANT},
            {'W', DWARF},
        };

    public:
        std::pair<int, int> randomPosition();

        // Getters:
        int tileIDAt(int x, int y);


        // Creators:
        void initializeMap(ifstream &mapFile, bool isMapProvided);
        void readMap(istream& mapFile);

        // Spawn a specific type of game object and add it to the gameMap
        void spawnObject(int x, int y, char type);
        // Spawn a random game object(Item or Enemy) and add it to the gameMap
        // types:
        // - E: enemy
        // - P: potion
        // - G: gold
        void spawnRandObject(int x, int y, char type);

        void createPlayerAtRandPosn(char type);
        void createStairAtRandPosition();
        void createEnemyAtRandPosn();
        void createGoldAtRandPosn();
        void createPotionAtRandPosn();


        // Move:
        bool movePlayer(string direction);
        bool moveEnemy(string direction);
        bool moveEnemyInRandomDirection();
        bool isValidMove(shared_ptr<GameObject> gameObject);
        bool freezeEnemy();
        

        // Attack:
        bool enemyAttack(shared_ptr<GameObject> enemyThatAttacks);
        bool playerAttack(string direction, shared_ptr<GameObject> enemyToAttack);
        bool isValidAttack(shared_ptr<GameObject> enemy);
        bool usePotion(string);

        // Game State Control:
        bool startGame();
        void nextFloor(ifstream& mapFile, bool isMapProvided);
        bool restartGame();
        void quitGame();
        bool setScore();
        bool endGame();

        // Update Game State:
        void updateGame();
        bool resetFloor(Tile*);

        // Destructor:
        ~GameModel();     
};
