#include "Effect.h"
class EffectHandler: public Effect {
        Effect *effect;
    public:
        EffectHandler(Effect *effect);
        int getAtkEffect();
        int getDefEffect();
        void addAtkEffect();
        void addDefEffect();
        void removeAllEffects();
        ~EffectHandler();
};