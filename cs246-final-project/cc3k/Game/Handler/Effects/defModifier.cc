#include "defModifier.h"
DefModifier::DefModifier(Effect *Effect, int def): EffectDecorator{effect} , def{def} {}
int DefModifier::getDefModifier() { return def; }
int DefModifier::getAtkModifier() { return 0; }
void DefModifier::setDef(int atk) { this->def = def; }
DefModifier::~DefModifier() {}
