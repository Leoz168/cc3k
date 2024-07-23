#include "effecthandler.h"

EffectHandler::EffectHandler(Effect *effect) {}
int EffectHandler::getAtkEffect() {
    return effect->getAtkModifier();
}
int EffectHandler::getDefEffect() {
    return effect->getDefModifier();
}
void EffectHandler::addAtkEffect(int delatk) {
    effect = new AtkModifier{effect, delatk};
}
void EffectHandler::addDefEffect(int deldef) {
    effect = new DefModifier{effect, deldef};
}
void EffectHandler::removeAllEffects() {
    delete effect
    effect = new NoEffect{};
}


EffectHandler::~EffectHandler() { delete effect; }
