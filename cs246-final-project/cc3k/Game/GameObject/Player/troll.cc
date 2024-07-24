#include "Troll.h"
using namespace std;

Troll::Troll(int x, int y, EffectHandler* ehr)
        : Player(x, y, TROLL, 120, 120, 25, 15, 0, ehr) {}
