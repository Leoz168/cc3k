#include "EffectHandler.h"

EffectHandler::EffectHandler(Effect *effect) {}

int EffectHandler::getAtkEffect() {
    return effect->getAtkModifier();
}

int EffectHandler::getDefEffect() {
    return effect->getDefModifier();
}

void EffectHandler::addAtkEffect(int atk) {
    effect = new AtkModifier{effect, atk};
}

void EffectHandler::addDefEffect(int def) {
    effect = new DefModifier{effect, def};
}

void EffectHandler::removeAllEffects() {
    delete effect;
    effect = new NoEffect{};
}

EffectHandler::~EffectHandler() { delete effect; }
