#include "DefModifier.h"
DefModifier::DefModifier(Effect *next, int def): EffectDecorator{next} , def{def} {}
int DefModifier::getDefModifier() { return def + next->getDefModifier(); }
int DefModifier::getAtkModifier() { return next->getAtkModifier(); }
void DefModifier::setDef(int atk) { this->def = def; }
DefModifier::~DefModifier() {}
