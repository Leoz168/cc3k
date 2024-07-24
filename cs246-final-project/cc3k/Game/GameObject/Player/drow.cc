#include "Drow.h"
using namespace std;

Drow::Drow(int x, int y, EffectHandler* ehr)
        : Player(x, y, DROW, 150, 150, 25, 15, 0, ehr) {}

