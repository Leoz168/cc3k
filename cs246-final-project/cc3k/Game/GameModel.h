#include <vector>

#include "GameSubject.h"
#include "floor.h"
#include "Floor/Cell/cell.h"
#include "GameObject/Enemy/enemy.h"
#include "GameObject/Player/player.h"

using namespace std;

class GameModel: public GameSubject {
        vector<shared_ptr<Enemy>> enemies;
        vector<shared_ptr<Item>> items;
        vector<shared_ptr<Cell>> cells;
    public:
        
};
