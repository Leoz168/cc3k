#include "EffectDecorator.h"
EffectDecorator::EffectDecorator(Effect *next): next{next} {}
EffectDecorator::~EffectDecorator() {}
