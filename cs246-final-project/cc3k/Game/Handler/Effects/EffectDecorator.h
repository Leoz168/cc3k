#include "Effect.h"

class EffectDecorator: public Effect {
    protected:
        Effect *next;
    public:
        EffectDecorator(Effect *next);
        virtual ~EffectDecorator();
};
