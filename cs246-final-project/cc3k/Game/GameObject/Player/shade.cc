#include "Shade.h"
using namespace std;

Shade::Shade(int x, int y, EffectHandler* ehr)
        : Player(x, y, SHADE, 125, 125, 25, 25, 0, ehr) {}
