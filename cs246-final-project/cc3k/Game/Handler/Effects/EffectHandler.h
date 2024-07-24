#include "Effect.h"
#include "atkModifier.h"
#include "defModifier.h"
#include "noEffect.h"

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