#include "effectDecorator.h"
class NoEffect: EffectDecorator {
    public:
        int getAtkModifier();
        int getDefModifier();
        ~NoEffect();
};