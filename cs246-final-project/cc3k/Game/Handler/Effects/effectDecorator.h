#include "Effect.h"
#include "atkModifier.h"
#include "defModifier.h"

class EffectDecorator: public Effect {
    protected:
        Effect *effect;
    public:
        EffectDecorator(Effect *effct);
        virtual ~EffectDecorator() = 0;
};
