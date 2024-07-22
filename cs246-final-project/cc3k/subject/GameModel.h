#include "GameSubject.h"
#include <vector>
#include <>
using namespace std;

class GameModel: public GameSubject {
    vector<shared_ptr<Enemy>> enemies;
    vector<shared_ptr<Item>> items;
    vector<shared_ptr<Cell>> cells;
};
