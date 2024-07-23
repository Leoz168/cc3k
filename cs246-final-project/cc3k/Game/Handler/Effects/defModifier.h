#include "effectDecorator.h"

class DefModifier: public EffectDecorator {
        int def;
    public:
        DefModifier(Effect *effect, int def);
        int getDefModifier();
        void setDef(int def);
        ~DefModifier();
};
