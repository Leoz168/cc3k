#include "effectDecorator.h"
class NoEffect: public Effect {
    public:
        NoEffect();
        int getAtkModifier();
        int getDefModifier();
        ~NoEffect();
};