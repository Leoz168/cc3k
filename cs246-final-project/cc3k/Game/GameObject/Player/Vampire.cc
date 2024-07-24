#include "Vampire.h"
using namespace std;

Vampire::Vampire(int x, int y, EffectHandler* ehr)
        : Player(x, y, VAMPIRE, 50, -1, 25, 25, 0, ehr) {}
