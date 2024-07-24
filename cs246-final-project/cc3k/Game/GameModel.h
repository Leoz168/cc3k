#pragma once

#include <vector>
#include <memory>
#include "fstream"

#include "GameSubject.h"
#include "../Tile.h"
#include "tileIDs.h"
#include "Floor/Cell/Cell.h"
#include "GameObject/Enemy/Enemy.h"
#include "GameObject/Item/Item.h"
#include "Player/Player.h"
#include "Map.h"
#include "Factory/ObjectCreator.h"
#include "Factory/CellCreator.h"
#include "Factory/EnemyCreator.h"
#include "Factory/ItemCreator.h"
#include "Factory/PlayerCreator.h"
#include "Handler/AttackHandler.h"
#include "Handler/MoveHandler.h"
#include "Handler/Effects/effecthandler.h"


class GameModel: public GameSubject {
        // Game State variables:
        int numRows = -1;
        int numCols= -1;
        int floorLevel = 0;
        int potionSpawnCounter = 0;
        int enemySpawnCounter = 0;
        int goldSpawnCounter = 0;

        // Player variables:
        std::unique_ptr<Player> player;
        const std::map<char, int> playerRaceMap {
            {'s', SHADE},
            {'d', DROW},
            {'v', VAMPIRE},
            {'g', GOBLIN},
            {'t', TROLL}
        }
        int playerRace = SHADE;
        std::shared_ptr<EffectHandler> effectHandler;

        // Map and objects on the Map
        Map map;
        std::vector<std::shared_ptr<Enemy>> enemies;
        std::vector<std::shared_ptr<Item>> items;
        std::vector<std::shared_ptr<Cell>> cells;

    public:
        std::pair<int, int> randomPosition();

        // Getters:
        int tileIDAt(int x, int y);

        // Creators:
        void createPlayer(char playerRace);
        void initializeCells();
        void initializeMap(ifstream &mapFile, bool isMapProvided);
        void readMap(istream& mapFile)
        shared_ptr<Tile> spawnRandGameObj();
        shared_ptr<Tile> spawn(string type);

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
        void nextFloor(ifstream& mapFile, bool isMapProvided)
        bool restartGame();
        void quitGame();
        bool setScore();
        bool endGame();

        // Update Game State:
        void updateGame();
        bool resetFloor(Tile*);

        // Destructor:
        ~GameModel();
        
        
        bool spawn(Tile*);
        
        
};
