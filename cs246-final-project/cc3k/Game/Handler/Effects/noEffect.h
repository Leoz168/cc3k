#include "effectDecorator.h"
class NoEffect: EffectDecorator {
    public:
        NoEffect();
        int getAtkModifier();
        int getDefModifier();
        ~NoEffect();
};