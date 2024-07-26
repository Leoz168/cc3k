#pragma once

#include "EffectDecorator.h"

class DefModifier: public EffectDecorator {
        int def;
    public:
        DefModifier(std::unique_ptr<Effect> next, int def);
        int getDefModifier() override;
        int getAtkModifier() override;
        void setDef(int def);
        ~DefModifier();
};
