#include "effectDecorator.h"
EffectDecorator::EffectDecorator(Effect *next): next{next} {}
EffectDecorator::~EffectDecorator() {}
