#pragma once

#include "Effect.h"
#include "AtkModifier.h"
#include "DefModifier.h"
#include "NoEffect.h"
#include <memory>

using namespace std;

class EffectHandler {
        unique_ptr<Effect> effect;
    public:
        EffectHandler();
        int getAtkEffect();
        int getDefEffect();
        void addAtkEffect(int atk);
        void addDefEffect(int def);
        void removeAllEffects();
        ~EffectHandler();
};