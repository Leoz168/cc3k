#include "Goblin.h"
using namespace std;

Goblin::Goblin(int x, int y, EffectHandler* ehr)
        : Player(x, y, GOBLIN, 110, 110, 15, 20, 0, ehr) {}
