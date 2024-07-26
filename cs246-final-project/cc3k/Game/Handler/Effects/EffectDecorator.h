#pragma once

#include "Effect.h"
#include <memory>
class EffectDecorator: public Effect {
    protected:
        std::unique_ptr<Effect> next;
    public:
        EffectDecorator(std::unique_ptr<Effect> next);
        virtual ~EffectDecorator();
};
