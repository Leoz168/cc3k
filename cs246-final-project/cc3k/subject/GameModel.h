#include <vector>

#include "GameSubject.h"
#include "floor.h"
#include "cell.h"
#include "enemies/enemy.h"
#include "player/player.h"

using namespace std;

class GameModel: public GameSubject {
        vector<shared_ptr<Enemy>> enemies;
        vector<shared_ptr<Item>> items;
        vector<shared_ptr<Cell>> cells;
    public:
        
};
