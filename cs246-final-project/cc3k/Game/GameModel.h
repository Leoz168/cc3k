#include <vector>
#include <memory>

#include "GameSubject.h"
#include "../Tile.h"
#include "Floor/Cell/cell.h"
#include "GameObject/Enemy/enemy.h"
#include "GameObject/Item/item.h"
#include "../Cell/cell.h"
#include "Player/player.h"

using namespace std;

class GameModel: public GameSubject {
        vector<shared_ptr<Enemy>> enemies;
        vector<shared_ptr<Item>> items;
        vector<shared_ptr<Cell>> cells;
        vector<vector<shared_ptr<Tile>>> map;
    public:
        void updateGame();
        int tileIDAt(int, int);
        Player *getPlayer();
        bool movePlayer(string);
        bool usePotion(string);
        bool attackEnemy(string);
        Tile *createPlayer(string);
        bool spawnRandGameObj(Tile*);
        bool spawn(Tile*);
        bool resetFloor(Tile*);
        bool freezeEnemy();
        bool restartGame();
        void quitGame();
        bool setScore();
        bool endGame();
        ~GameModel();
};
