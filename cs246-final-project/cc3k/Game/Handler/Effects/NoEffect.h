#pragma once

#include "EffectDecorator.h"
class NoEffect: public Effect {
    public:
        NoEffect();
        int getAtkModifier();
        int getDefModifier();
        ~NoEffect();
};
