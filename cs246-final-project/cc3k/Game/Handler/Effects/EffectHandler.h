#pragma once

#include "Effect.h"
#include "AtkModifier.h"
#include "DefModifier.h"
#include "NoEffect.h"

class EffectHandler: public Effect {
        Effect *effect;
    public:
        EffectHandler(Effect *effect);
        int getAtkEffect();
        int getDefEffect();
        void addAtkEffect(int atk);
        void addDefEffect(int def);
        void removeAllEffects();
        ~EffectHandler();
};