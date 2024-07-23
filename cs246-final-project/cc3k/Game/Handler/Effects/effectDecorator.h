#include "Effect.h"

class EffectDecorator: public Effect {
    protected:
        Effect *effect;
    public:
        EffectDecorator(Effect *effct);
        virtual ~EffectDecorator();
};
